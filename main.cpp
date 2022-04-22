#include "include/turing_machine.h"

int main()
{
  Turing_Machine machine;

  std::cout << "Tape (Symbols 1 0 #)): ";
  std::getline(std::cin, machine.tape);
 
  machine.read_instructions();
  machine.process_instructions();
}

