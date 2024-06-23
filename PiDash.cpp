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

    //next_voltage = rand()%1024;
    //next_oil_pressure = rand()%1024;
    //next_coolent_temp = rand()%1024;
    //next_afr = rand()%1024;

    struct can_frame frame;
    nbytes = read(socket, &frame, sizeof(can_frame));

    if(nbytes < 0){
      std::cout << "error reading message" << std::endl;
    } else if(nbytes == sizeof(struct can_frame)){
      __u32 canId = frame.can_id;
      __u8 dataLength = frame.len;
      __u8 *data = frame.data;

      if(canId == 1512){

        can_1512 msg;
        uint8_t success = CanDecoder::decode1512(data, &msg);

	      next_rpm = msg.rpm;
	      next_coolent_temp = msg.clt;
        next_tps = msg.tps;
        next_map = msg.map;

      } else if(canId == 1513){

        can_1513 msg;
        uint8_t success = CanDecoder::decode1513(data, &msg);

        next_adv_deg = msg.adv_deg;
        next_mat = msg.mat;
        next_pw2 = msg.pw2;
        next_pw1 = msg.pw1;

      } else if(canId == 1514){

        can_1514 msg;
        uint8_t success = CanDecoder::decode1514(data, &msg);

        next_pwseq1 = msg.pwseq1;
        next_egt1 = msg.egt1;
        next_egocor1 = msg.egocor1;
        next_afr = msg.AFR1;
        next_afrtgt1 = msg.afrtgt1;
        
      } else if(canId == 1515){

        can_1515 msg;
        uint8_t success = CanDecoder::decode1515(data, &msg);

        next_knk_rtd = msg.knk_rtd;
        next_sensors2 = msg.sensors2;
        next_sensors1 = msg.sensors1;
        next_batt = msg.batt;
        
      } else if(canId == 1516){
        
        can_1516 msg;
        uint8_t success = CanDecoder::decode1516(data, &msg);

        next_launch_timing = msg.launch_timing;
        next_tc_retard = msg.tc_retard;
        next_VSS1 = msg.VSS1;
      }
    }

    dispatcher.emit();
  }

}

void PiDashWindow :: update_gauges(){
  gauges.update_gauge("Voltage", next_voltage);
  gauges.update_gauge("Manifold air pressure", next_map);
  gauges.update_gauge("Coolent temp", next_coolent_temp);
  gauges.update_gauge("AFR", next_afr);

  rpm_bar.set_value(next_rpm);
}
