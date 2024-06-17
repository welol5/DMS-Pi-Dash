#include <iostream>
#include <ctime>
#include <string>
#include <gtkmm/label.h>
#include <glibmm/main.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>
#include "Clock.h"

Clock :: Clock(){
    set_label("Clock");
    start_time = std::time(nullptr);
    Glib::signal_timeout().connect(sigc::mem_fun(*this, &Clock::clock_update), 500);
}

int Clock :: clock_update(){
  time_t current_time = std::time(nullptr);
  time_t timer_value = current_time - start_time;

  time_t seconds = timer_value%60;
  time_t mins = (timer_value/60)%60;
  time_t hours = (timer_value/3600)%60;

  std::string seconds_string;
  std::string min_string;
  std::string hours_string;

  if(seconds < 10){
    seconds_string = "0" + std::to_string(seconds);
  } else {
    seconds_string = std::to_string(seconds);
  }

  if(mins < 10){
    min_string = "0" + std::to_string(mins);
  } else {
    min_string = std::to_string(mins);
  }

  hours_string = std::to_string(hours);

  set_label(hours_string + " : " + min_string + " : " + seconds_string);
  return 1;
}