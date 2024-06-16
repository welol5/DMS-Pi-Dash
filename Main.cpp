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
  auto app = Gtk::Application::create("org.dallasmakerspace.pidash");
  return app->make_window_and_run<PiDashWindow>(argc, argv);
}