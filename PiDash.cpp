#include "PiDash.h"

PiDashWindow :: PiDashWindow() {

  //start clock thread
  start_time = std::time(nullptr);
  Glib::signal_timeout().connect(sigc::mem_fun(*this, &PiDashWindow::clock_update), 500);

  //start can thread

  
  setup_css();

  set_title("Shrimplified Pi Dash");
  set_default_size(1280, 400);

  rpm_bar.set_margin(5);
  rpm_bar.set_min_value(0);
  rpm_bar.set_max_value(6900);
  rpm_bar.add_css_class("rpm-bar");

  rpm_other_pane.set_orientation(Gtk::Orientation::VERTICAL);
  rpm_other_pane.set_start_child(rpm_bar);

  clock_label.set_label("Clock");
  clock_label.add_css_class("clock");
  clock_other_pane.set_start_child(clock_label);

  test_button.set_label("increase rpm");
  test_button.signal_clicked().connect(sigc::mem_fun(*this, &PiDashWindow::increase_rpms));

  // clock_other_pane.set_end_child(test_button);

  clock_other_pane.set_end_child(gauges);
  rpm_other_pane.set_end_child(clock_other_pane);

  set_child(rpm_other_pane);
}

//needs disbatcher for threading communication
void PiDashWindow :: increase_rpms(){
  double current_rpms = rpm_bar.get_value();
  current_rpms += 100;
  if(current_rpms > 6900){
    current_rpms = 0;
  }
  rpm_bar.set_value(current_rpms);
}

void PiDashWindow :: can_thread(){
  
}

int PiDashWindow :: clock_update(){
  time_t current_time = std::time(nullptr);
  time_t timer_value = current_time - start_time;

  time_t seconds = timer_value%60;
  time_t mins = (timer_value/60)%60;
  time_t hours = (timer_value/3600)%60;

  clock_label.set_label(std::to_string(hours) + " : " + std::to_string(mins) + " : " + std::to_string(seconds));
  return 1;
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
      "/home/welol/Desktop/DMSPiDash/styles/styles.css");

  Gtk::StyleContext::add_provider_for_display(
      Gdk::Display::get_default(), css_provider,
      GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}