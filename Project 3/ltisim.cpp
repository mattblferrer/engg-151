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
#include "ltisim_functions.cpp"

using namespace std;

int main()
{
  bool exitTyped = false;
  bool LTISpecified = false;
  bool signalSpecified = false;
  string input;
  string command;
  string filename;
  stringstream ss;
  int duration = 0;
  double* signalData = new double[0];
  double* aData = new double[0];
  double* bData = new double[0];
  
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
      continue;
    }
    else if (input == "clear")
    {
      continue;
    }
    else if (input == "exit")
    {
      exitTyped = true;
      continue;
    }
    else if (input == "cls")
    {
      system("cls");
      continue;
    }

    ss.str(input);
    ss >> command;
    ss >> filename;
    if (command == "system")
    {
      
    }
    else if (command == "signal")
    {
      // import signal from file
      if (!importSignalFromFile(filename, signalData, duration))
      {
        cout << "Unable to import a valid signal from " << filename 
            << "\n";
        return 1;
      }
      continue;
    }
  }
  return 0;
}