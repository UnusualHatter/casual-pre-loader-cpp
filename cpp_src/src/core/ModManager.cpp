#include "ModManager.hpp"
#include "../utils/Logger.hpp"
#include "VPKHandler.hpp"
#include <filesystem>

namespace casual_pre_loader {

ModManager::ModManager() {}

void ModManager::scanMods(const std::filesystem::path &modPath) {
  Logger::info("Scanning mods in: " + modPath.string());
  if (!std::filesystem::exists(modPath)) {
    Logger::error("Mod path does not exist: " + modPath.string());
    return;
  }

  for (const auto &entry :
       std::filesystem::recursive_directory_iterator(modPath)) {
    if (entry.is_regular_file() && entry.path().extension() == ".vpk") {
      Logger::info("Found VPK: " + entry.path().string());
      m_mods.push_back(entry.path());
    }
  }
}

void ModManager::processMods() {
  Logger::info("Processing " + std::to_string(m_mods.size()) + " mods...");
  for (const auto &mod : m_mods) {
    Logger::info("Processing VPK: " + mod.string());
    VPKHandler vpk;
    if (vpk.open(mod)) {
      Logger::info("  VPK opened successfully.");
    } else {
      Logger::error("  Failed to open VPK.");
    }
  }
}

} 
