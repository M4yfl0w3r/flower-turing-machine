#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <limits>

class Turing_Machine
{

public:
  std::string tape; 
  std::vector<std::vector<char>> instructions;

public: 
  inline static char 
    current_state = '0',
    old_state,
    new_state;
  
  inline static char 
    old_symbol,
    new_symbol;

  inline static char
    turn;

  inline static int 
    head_pos;

public:
  Turing_Machine();

  auto read_instructions() -> void;
  auto print_instructions() const -> void; // just for testing i guess
  auto process_instructions() -> void; 

private:
  auto setup_parameters(size_t) -> void;
  auto current_instruction(char) const -> int;
};

