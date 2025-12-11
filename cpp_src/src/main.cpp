#include "core/ModManager.hpp"
#include "utils/Logger.hpp"
#include <argparse/argparse.hpp>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  argparse::ArgumentParser program("casual_pre_loader_cpp");

  program.add_argument("-t", "--tf2-path")
      .help("Path to TF2 installation")
      .default_value(std::string(""));

  program.add_argument("-c", "--config")
      .help("Path to config file")
      .default_value(std::string("config.json"));

  program.add_argument("--dry-run")
      .help("Simulate operations without writing changes")
      .default_value(false)
      .implicit_value(true);

  try {
    program.parse_args(argc, argv);
  } catch (const std::exception &err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return 1;
  }

  std::cout << "Casual Pre-Loader C++ (Prototype)" << std::endl;

  auto tfPath = program.get<std::string>("--tf2-path");
  if (tfPath.empty()) {
    std::cerr << "Error: --tf2-path is required." << std::endl;
    return 1;
  }

  try {
    casual_pre_loader::ModManager manager;
    manager.scanMods(tfPath);
    manager.processMods();
  } catch (const std::exception &e) {
    casual_pre_loader::Logger::error("Exception: " + std::string(e.what()));
    return 1;
  }

  return 0;
}
