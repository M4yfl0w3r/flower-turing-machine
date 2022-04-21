#include "../include/turing_machine.h"

Turing_Machine::Turing_Machine()
{
  tape.reserve(40);
}

auto Turing_Machine::read_instructions()-> void
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
      std::cout << c << ' ';
    }

    std::cout << '\n';
  }
}

