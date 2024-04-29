#include <stdio.h>
#include <gtkmm/application.h>
#include "PiDash.h"
#include <fstream>

/**
 * Requirements:
 * RPM
 * Voltage
 * Oil Pressure
 * Coolent temp
 * AFR
 * Clock
*/

int main (int argc, char *argv[])
{
  // std::ifstream css_file; css_file.open("/home/welol/Desktop/CPPTests/styles/styles.css");
  // std::string file_string;
  // std::cout << "file contents" << std::endl;
  // if(css_file.is_open()){
  //   css_file >> file_string;
  //   std::cout << file_string;
  // }
  // std::cout << "eof" << std::endl;


  auto app = Gtk::Application::create("org.dallasmakerspace.pidash");
  return app->make_window_and_run<PiDashWindow>(argc, argv);
}