#include "VPKHandler.hpp"
#include "../utils/BinaryStream.hpp"
#include "../utils/Logger.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>

namespace casual_pre_loader {

VPKHandler::VPKHandler() {}

bool VPKHandler::open(const std::filesystem::path &path) {
  Logger::info("Opening VPK: " + path.string());
  m_path = path;

  std::ifstream file(path, std::ios::binary);
  if (!file.is_open()) {
    Logger::error("Failed to open VPK file: " + path.string());
    return false;
  }

  BinaryStream stream(file);
  uint32_t signature = stream.read<uint32_t>();
  uint32_t version = stream.read<uint32_t>();
  uint32_t treeSize = stream.read<uint32_t>();

  if (signature != 0x55AA1234) {
    Logger::error("Invalid VPK signature: " + std::to_string(signature));
    return false;
  }

  if (version == 2) {
    stream.read<uint32_t>();
    stream.read<uint32_t>();
    stream.read<uint32_t>();
    stream.read<uint32_t>();
  }

  Logger::info("VPK Version: " + std::to_string(version));
  Logger::info("Tree Size: " + std::to_string(treeSize));

  m_treeStart = file.tellg();
  m_file = std::move(file);
  return true;
}

std::string readString(std::ifstream &f) {
  std::string s;
  std::getline(f, s, '\0');
  return s;
}

VPKHandler::VPKEntry VPKHandler::findFile(const std::string &filename) {
  std::filesystem::path p(filename);
  std::string ext = p.extension().string();
  if (!ext.empty() && ext[0] == '.')
    ext.erase(0, 1);

  std::string name = p.stem().string();
  std::string path = p.parent_path().string();
  if (path == ".")
    path = "";

  std::replace(path.begin(), path.end(), '\\', '/');

  m_file.clear();
  m_file.seekg(m_treeStart);
  BinaryStream stream(m_file);

  while (m_file.good()) {
    std::string c_ext = readString(m_file);
    if (c_ext.empty())
      break;

    while (m_file.good()) {
      std::string c_path = readString(m_file);
      if (c_path.empty())
        break;

      while (m_file.good()) {
        std::string c_name = readString(m_file);
        if (c_name.empty())
          break;

        stream.read<uint32_t>();
        uint16_t preloadBytes = stream.read<uint16_t>();
        uint16_t archiveIndex = stream.read<uint16_t>();
        uint32_t entryOffset = stream.read<uint32_t>();
        uint32_t entryLength = stream.read<uint32_t>();
        stream.read<uint16_t>();

        if (c_ext == ext && c_path == path && c_name == name) {
          return {archiveIndex, entryOffset, entryLength, true};
        }

        if (preloadBytes > 0) {
          m_file.seekg(preloadBytes, std::ios::cur);
        }
      }
    }
  }
  return {};
}

}
