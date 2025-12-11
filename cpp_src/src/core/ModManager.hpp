#pragma once
#include <filesystem>
#include <string>
#include <vector>

namespace casual_pre_loader {

class ModManager {
public:
  ModManager();
  void scanMods(const std::filesystem::path &modPath);
  void processMods();

private:
  std::vector<std::filesystem::path> m_mods;
};

}
