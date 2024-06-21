#include <chrono>
#include <cstring>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <unistd.h>
#include "PiDash.h"

PiDashWindow :: PiDashWindow() {

  //open can0
  int canSocket;
  struct sockaddr_can addr;
  struct ifreq ifr;
  std::cout << "opening socket on can0" << std::endl;
  canSocket = socket(PF_CAN, SOCK_RAW, CAN_RAW);
  strcpy(ifr.ifr_name, "can0");
  ioctl(canSocket, SIOCGIFINDEX, &ifr);
  addr.can_family = AF_CAN;
  addr.can_ifindex = ifr.ifr_ifindex;
  int bindCode = bind(canSocket, (struct sockaddr *)&addr, sizeof(addr));
  if(bindCode < 0){
    std::cout << "failed to bind socket" << std::endl;
  }

  //start can thread
  can_thread = std::thread(&PiDashWindow::can_worker, this, canSocket);
  dispatcher.connect(sigc::mem_fun(*this, &PiDashWindow::update_gauges));
  
  setup_css();

  set_title("Shrimplified Pi Dash");
  set_default_size(1280, 400);

  rpm_bar.set_margin(5);
  rpm_bar.set_min_value(0);
  rpm_bar.set_max_value(6900);
  rpm_bar.add_css_class("rpm-bar");

  rpm_other_pane.set_orientation(Gtk::Orientation::VERTICAL);
  rpm_other_pane.set_start_child(rpm_bar);

  clock.add_css_class("clock");
  clock_other_pane.set_start_child(clock);

  test_button.set_label("increase rpm");
  test_button.signal_clicked().connect(sigc::mem_fun(*this, &PiDashWindow::increase_rpms));

  // clock_other_pane.set_end_child(test_button);

  clock_other_pane.set_end_child(gauges);
  rpm_other_pane.set_end_child(clock_other_pane);

  set_child(rpm_other_pane);
}

void PiDashWindow :: increase_rpms(){
  double current_rpms = rpm_bar.get_value();
  current_rpms += 100;
  if(current_rpms > 6900){
    current_rpms = 0;
  }
  rpm_bar.set_value(current_rpms);
}

void PiDashWindow :: setup_css(){
  auto css_provider = Gtk::CssProvider::create();
  css_provider->signal_parsing_error().connect(
    [](const Glib::RefPtr<const Gtk::CssSection>& section,
      const Glib::Error& error) {
        //error reporting
        std::cerr << "parsing error: " << error.what() << std::endl;
      });
  css_provider->load_from_path(
      "/home/pi/DMS-Pi-Dash/styles/styles.css");

  Gtk::StyleContext::add_provider_for_display(
      Gdk::Display::get_default(), css_provider,
      GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

void PiDashWindow :: can_worker(int socket){
  int nbytes;

  while(true){
    //read values
    //next_rpm = (next_rpm += 10)%6900;
    next_voltage = rand()%1024;
    next_oil_pressure = rand()%1024;
    //next_coolent_temp = rand()%1024;
    next_afr = rand()%1024;

//    std::cout << "read frame" << std::endl;
    struct can_frame frame;
    nbytes = read(socket, &frame, sizeof(can_frame));
//    std::cout << "read nbytes: " << std::endl;

    if(nbytes < 0){
      std::cout << "error reading message" << std::endl;
    } else if(nbytes == sizeof(struct can_frame)){
//      std::cout << "can id: " << frame.can_id << std::endl;
      __u32 canId = frame.can_id;
      __u8 dataLength = frame.len;
      __u8 *data = frame.data;

      if(canId == 1512){

	uint16_t tps = CanDecoder::decode1512(data).tps;
	uint16_t coolent_temp = CanDecoder::decode1512(data).clt;
	__u16 rpm = (data[2] << 8) | (data[3]);

	next_rpm = rpm;
	next_coolent_temp = coolent_temp/10;
	std::cout << "tps: " << tps << std::endl;
     }
    }
    dispatcher.emit();

  }

}

void PiDashWindow :: update_gauges(){
  gauges.update_gauge("Voltage", next_voltage);
  gauges.update_gauge("Oil pressure", next_oil_pressure);
  gauges.update_gauge("Coolent temp", next_coolent_temp);
  gauges.update_gauge("AFR", next_afr);

  rpm_bar.set_value(next_rpm);
}
