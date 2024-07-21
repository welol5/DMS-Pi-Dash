#include <fstream>
#include <iostream>
#include "Env.h"

std::string Env::root_path;
std::string Env::config_path;
std::string Env::styles_path;

std::map<std::string,std::string> Env::enviornmentVaribles;

void Env::init(std::string rootPath){
    root_path = rootPath;
    config_path = root_path + "/env/config.txt";
    styles_path = root_path + "/styles/styles.css";

    std::ifstream configFile(config_path, std::ios::in);
    if(configFile.is_open()){
        std::string line;
        while(getline(configFile, line)){
            int delimIndex = line.find("=");
            std::string key = line.substr(0, delimIndex);
            std::string value = line.substr(delimIndex+1, line.size());
            enviornmentVaribles.insert(std::pair<std::string,std::string>(key,value));
            std::cout << "loaded " << key << " : " << value << std::endl;
        }
    }
}