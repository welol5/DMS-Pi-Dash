#include <chrono>
#include <cstring>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <unistd.h>
#include "PiDash.h"
#include "env/Env.h"

#define TESTING_MODE FALSE

PiDashWindow :: PiDashWindow() {

  if(debugging){
    std::cout << "debugging mode activated" << std::endl;
  }

  //open can0
  int canSocket;
  struct sockaddr_can addr;
  struct ifreq ifr;
  std::cout << "opening socket on can0" << std::endl;
  canSocket = socket(PF_CAN, SOCK_RAW, CAN_RAW);
  strcpy(ifr.ifr_name, "can0");
  ioctl(canSocket, SIOCGIFINDEX, &ifr);
  addr.can_family = AF_CAN;

  #if TESTING_MODE != TRUE
    addr.can_ifindex = ifr.ifr_ifindex;
    int bindCode = bind(canSocket, (struct sockaddr *)&addr, sizeof(addr));
    if(bindCode < 0){
      std::cout << "failed to bind socket" << std::endl;
    }
  #endif

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

  rpm_gauge.add_css_class("rpm-bar");

  rpm_other_pane.set_orientation(Gtk::Orientation::VERTICAL);
  // rpm_other_pane.set_start_child(rpm_bar);
  rpm_other_pane.set_start_child(rpm_gauge);


  clock.add_css_class("clock");
  clock_other_pane.set_start_child(clock);

  clock_other_pane.set_end_child(gauges);
  rpm_other_pane.set_end_child(clock_other_pane);

  set_child(rpm_other_pane);

  if(debugging){
    std::cout << "Dash window created" << std::endl;
  }
}

void PiDashWindow :: increase_rpms(){
  double current_rpms = rpm_testing;
  current_rpms += 100;
  if(current_rpms > 6969){
    current_rpms = 0;
  }
  rpm_testing = current_rpms;
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
      Env::styles_path);

  Gtk::StyleContext::add_provider_for_display(
      Gdk::Display::get_default(), css_provider,
      GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

void PiDashWindow :: can_worker(int socket){
  if(debugging){
    std::cout << "Starting CAN worker" << std::endl;
  }
  int nbytes;

  while(true){
    struct can_frame frame;

    #if TESTING_MODE == TRUE
      usleep(20000);
      nbytes = sizeof(struct can_frame);
      increase_rpms();
    #else
      nbytes = read(socket, &frame, sizeof(can_frame));
    #endif

    if(nbytes < 0){
      std::cout << "error reading message" << std::endl;
    } else if(nbytes == sizeof(struct can_frame)){
      __u32 canId = frame.can_id;
      __u8 dataLength = frame.len;
      __u8 *data = frame.data;
      #if TESTING_MODE == TRUE
        std::map<std::string, float> dataMap;
        testing_map_gauge_values(&dataMap);
        update_current_map(&dataMap);
      #else
        std::map<std::string, float> dataMap;
        CanDecoder::decode_can_frame(&frame, &dataMap);
        update_current_map(&dataMap);
      #endif
      
    }

    dispatcher.emit();
  }

}

void PiDashWindow :: update_current_map(std::map<std::string,float>* updatedData){
  for (auto const& data : *updatedData){
    next_values[data.first]=data.second;
  }

  //log current set
  std::stringstream s;
  for(auto const& data: next_values){
    s << data.second << ",";
  }
  logger->log(1,s.str());
}

void PiDashWindow :: testing_map_gauge_values(std::map<std::string,float> *data){
  (*data)["rpm"] = rpm_testing;
  (*data)["clt"] = 80.0;
  (*data)["map"] = 100.0;
  (*data)["batt"] = 11.5;
  (*data)["afr"] = 14;
}

void PiDashWindow :: update_gauges(){
  if(next_values["batt_set"] == 1){
    gauges.update_gauge("Voltage", next_values["batt"]);
  }
  if(next_values["map_set"] == 1){
    gauges.update_gauge("MAP", next_values["map"]);
  }
  if(next_values["clt_set"] == 1){
    gauges.update_gauge("Coolent temp", next_values["clt"]);
  }
  if(next_values["AFR1_set"] == 1){
    gauges.update_gauge("AFR", next_values["AFR1"]);
  }

  if(next_values["rpm_set"] == 1){
    rpm_gauge.update_value(next_values["rpm"]);
  }
}
