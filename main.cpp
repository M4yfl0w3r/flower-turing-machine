#include "include/turing_machine.h"
#include "src/turing_machine.cpp"

int main()
{
  Turing_Machine machine;

  std::cout << "Type (Symbols 1 0 #)): ";
  std::getline(std::cin, machine.tape);
  
  machine.read_instructions();
  // machine.print_instructions();
}
