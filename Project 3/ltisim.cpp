/**
 * ltisim.cpp
 * 
 * BERNARDO, Jonathan
 * FERRER, Matt
 * 
 * Project 3 - Linear Time-Invariant System Simulator
 * ENGG 151.01 - A
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  bool exitTyped = false;
  string input;
  string command;
  string filename;
  stringstream ss;
  
  cout << "LTISim\nType \"help\" for more information.\n";
  while (!exitTyped)
  {
    ss.clear();
    getline(cin, input);
    if (input == "help")
    {
      cout << "\nLTISim - Linear Time-Invariant System Simulator\n";
      cout << "Type \"help\" for more information.\n";
      cout << "Type \"system [filename]\" to extract an LTI " << 
        "system from a file with the specified filename.\n";
      cout << "Type any floating point number to add another " << 
        "input to the LTI system.\n";
      cout << "Type \"signal [filename]\" to extract a signal " << 
        "from a file with the specified filename.\n";
      cout << "Type \"clear\" to clear the application's memory " <<
        " of previous inputs and outputs to 0.\n";
      cout << "Type \"exit\" to exit the program.\n";
      cout << "Type \"cls\" to clear the screen.\n";
    }
    else if (input == "clear")
    {

    }
    else if (input == "exit")
    {
      exitTyped = true;
    }
    else if (input == "cls")
    {
      system("cls");
    }

    ss.str(input);
    ss >> command;
    ss >> filename;
  }
  return 0;
}