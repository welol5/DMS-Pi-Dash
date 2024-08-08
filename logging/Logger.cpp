#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
#include "Logger.h"
#include "../env/Env.h"

uint8_t Logger::log_level;
Logger* Logger::logger;

Logger::Logger(){
    std::cout << "creating logger" << std::endl;
    std::string levelString = Env::enviornmentVaribles["dataLogging.level"];
    log_level = std::atoi(levelString.c_str());

    //start writing thread
    bool isEnabled;
    std::istringstream(Env::enviornmentVaribles["dataLogging.enabled"]) >> std::boolalpha >> isEnabled;
    if(isEnabled){
        write_thread = std::thread(&Logger::write, this);
    }
    logger = this;
}

Logger* Logger::getLogger() {
    return Logger::logger;
}

void Logger::log(uint8_t level, std::string message){
    if(level <= log_level){
        std::stringstream s;
        std::chrono::time_point now = std::chrono::high_resolution_clock::now();
        s << std::to_string(level) << " " << now.time_since_epoch().count() << " " << message;
        log_buffer.push_back(s.str());
    }

    if(mutex.try_lock()){
        for(std::string m: log_buffer){
            write_buffer.push_back(m);
            log_buffer.clear();
        }
        mutex.unlock();
    }
}

void Logger::write(){

    std::string loggingPath = Env::enviornmentVaribles["dataLogging.fileLocation"] + "/log.txt";
    std::cout << "logging to: " << loggingPath << std::endl;

    while(true){
        if(write_buffer.size() > 0){
            
            mutex.lock();
            std::ofstream logFile("log.txt", std::ios_base::app);
            while(write_buffer.size() > 0){
                // std::ofstream logFile(loggingPath.c_str());
                std::string message = write_buffer.front();
                write_buffer.pop_front();
                logFile << message << std::endl;
                std::cout << "writing message: " << message << std::endl;
            }
            mutex.unlock();
            logFile.close();

            //open log file
        }
    }
}