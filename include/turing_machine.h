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
  
  static char 
    old_symbol,
    old_state;
  
  static char 
    new_symbol,
    new_state;

  static char
    turn;

public:
  Turing_Machine();

  auto read_instructions() -> void;
  auto print_instructions() const -> void; // just for testing i guess
  auto process_instructions() -> void; 
};


