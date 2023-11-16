#include "utilities.hpp"

String loadTja(const FilePath& filename) {
  BinaryReader reader{filename};

  if (not reader) {
    throw Error{U"Failed to open."};
  }

  std::string buf;
  char c;
  while (reader.read(c)) {
    buf.push_back(c);
  }

  String tja = utf8_to_char32(ansi_to_utf8(buf));

  return tja;
}
