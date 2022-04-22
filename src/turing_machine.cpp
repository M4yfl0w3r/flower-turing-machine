#include "../include/turing_machine.h"

Turing_Machine::Turing_Machine() 
{
  tape.reserve(40);
}

auto Turing_Machine::read_instructions() -> void
{
  std::ifstream infile("../instructions.txt");
  std::string line;

  while (std::getline(infile, line))
  {
    std::vector<char> row;

    for (const auto& c: line)
    {
      if (c != ',') 
      {
        row.emplace_back(c);
      }
    }

    instructions.emplace_back(row);
  }
}

auto Turing_Machine::print_instructions() const -> void
{
  for (const auto& row : instructions)
  {
    for (const auto& c : row)
    {
      std::cout << c;
    }

    std::cout << '\n';
  }
}

auto Turing_Machine::current_instruction(char symbol) const -> size_t
{
  for (size_t i = 0; i < instructions.size(); i++)
  {
    if (instructions[i][0] == symbol && current_state == instructions[i][1])
    {
      return i;
    }
  }

  return std::numeric_limits<size_t>::max();
}

auto Turing_Machine::setup_parameters(size_t i) -> void
{
  old_symbol = instructions[i][0];
  old_state = instructions[i][1];
  new_symbol = instructions[i][2];
  new_state = instructions[i][3];
  turn = instructions[i][4];
}

auto Turing_Machine::process_instructions() -> void
{
  // (0 old_symbol, 1 old_state, 2 new_symbol, 3 new_state, 4 turn)

  for (size_t i = 0; i < instructions.size(); i++)
  {
    setup_parameters(i);
  }

  std::cout << tape << " ↓ \n";

  while (tape[head_pos] != '#')
  {
    size_t ins = current_instruction(tape[head_pos]);

    if (ins != std::numeric_limits<size_t>::max())
    {
      tape[head_pos] = instructions[ins][2];
      current_state = instructions[ins][3];

      if (instructions[ins][4] == 'L') head_pos--;
      else if (instructions[ins][4] == 'R') head_pos++;
      else return;
    }

    std::cout << tape << " ↓ \n";
  }
}

