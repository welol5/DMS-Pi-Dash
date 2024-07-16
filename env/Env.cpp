#include "Env.h"

std::string Env::root_path = "";
std::string Env::config_path = "";
std::string Env::styles_path = "";

void Env::init(std::string rootPath){
    root_path = rootPath;
    config_path = root_path + "/env/config.txt";
    styles_path = root_path + "/styles/styles.css";
}