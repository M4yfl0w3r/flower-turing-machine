#pragma once

#include <vector>
#include <fstream>
#include <iostream>

class Turing_Machine
{

public:
  std::string tape; 
  std::vector<std::vector<char>> instructions;

public:
  Turing_Machine();

  auto read_instructions() -> void;
  auto print_instructions() const -> void; // just for testing i guess
};


