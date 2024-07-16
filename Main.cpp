#include <stdio.h>
#include <gtkmm/application.h>
#include "PiDash.h"
#include "env/Env.h"

/**
 * Requirements:
 * RPM
 * Voltage
 * Oil Pressure
 * Coolent temp
 * AFR
 * Clock
*/

int main (int argc, char *argv[]) {
  Env::init("/home/welol/Desktop/DMSPiDash");

  auto app = Gtk::Application::create("org.dallasmakerspace.pidash");
  return app->make_window_and_run<PiDashWindow>(argc, argv);
}