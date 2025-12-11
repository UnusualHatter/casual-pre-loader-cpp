#pragma once
#include <string>

namespace casual_pre_loader {

class Logger {
public:
  enum class Level { INFO, WARNING, ERROR };

  static void log(Level level, const std::string &message);
  static void info(const std::string &message);
  static void error(const std::string &message);
};

}
