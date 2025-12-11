#pragma once
#include <fstream>

namespace casual_pre_loader {

class BinaryStream {
public:
  explicit BinaryStream(std::ifstream &stream) : m_stream(stream) {}

  template <typename T> T read() {
    T value;
    m_stream.read(reinterpret_cast<char *>(&value), sizeof(T));
    return value;
  }

private:
  std::ifstream &m_stream;
};

}
