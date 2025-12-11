#pragma once
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace casual_pre_loader {

class VPKHandler {
public:
  VPKHandler();
  struct VPKEntry {
    uint16_t archiveIndex;
    uint32_t entryOffset;
    uint32_t entryLength;
    bool valid = false;
  };

  bool open(const std::filesystem::path &path);
  VPKEntry findFile(const std::string &filename);

private:
  std::filesystem::path m_path;
  std::streampos m_treeStart;
  std::ifstream m_file;
};

}
