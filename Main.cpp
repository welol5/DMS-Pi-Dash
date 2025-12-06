#include <stdio.h>
#include <string>
#include <gtkmm/application.h>
#include "PiDash.h"
#include "env/Env.h"

int processCommmandLineArgs(int argc, char *argv[]){
  int retCode = 0;
  std::string rootPath = "/home/pidash/DMS-Pi-Dash";
  if(argc > 0){
    for(int i = 0; i < argc; i++){
      if(strcmp("root", argv[i]) == 0){
        if((i+1) <= argc){
          i++;
          rootPath = argv[i];
          std::cout << "set root path: " << rootPath << std::endl;
        } else {
          std::cout << "no value found for -c argument" << std::endl;
          retCode = 1;
        }
      } else {
        std::cout << "ignoring invaild argument: " << argv[i] << std::endl;
      }
    }
  }
  Env::init(rootPath);
  return retCode;
}

int main (int argc, char *argv[]) {

  if(processCommmandLineArgs(argc, argv) == 1){
    return 1;
  }
  Logger logger;

  auto app = Gtk::Application::create("org.dallasmakerspace.pidash");
  return app->make_window_and_run<PiDashWindow>(1, argv);
}