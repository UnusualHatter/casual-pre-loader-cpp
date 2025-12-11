#include "Logger.hpp"
#include <iostream>

namespace casual_pre_loader {

void Logger::log(Level level, const std::string &message) {
  std::string prefix;
  switch (level) {
  case Level::INFO:
    prefix = "[INFO] ";
    break;
  case Level::WARNING:
    prefix = "[WARN] ";
    break;
  case Level::ERROR:
    prefix = "[ERROR] ";
    break;
  }
  std::cout << prefix << message << std::endl;
}

void Logger::info(const std::string &message) { log(Level::INFO, message); }

void Logger::error(const std::string &message) { log(Level::ERROR, message); }

} 
