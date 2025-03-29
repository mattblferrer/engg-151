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
  ofstream logFile;
  int duration = 0;
  int m = 0;
  int n = 0;
  int start = 0;
  double* signalData = new double[0];
  double* bData = new double[0];
  double* aData = new double[0];
  double* yData = new double[0];
  double* xData = new double[0];
  double doubleTest = 0.0;
  
  // starting program logic
  cout << "LTISim\nType \"help\" for more information.\n";
  logFile.open("ltisim-log.txt", ios::app);
  if (!(logFile.is_open())) 
  {
    cout << "Unable to open log file \"ltisim-log.txt\".\n";
  }

  // program loop, will only exit when command exit is typed
  while (!exitTyped)
  {
    ss.clear();
    getline(cin, input);
    ss.str(input);
    ss >> command >> filename;
    ss.clear();
    ss.str(input);
    if (ss >> doubleTest)  // check if input is a floating point n
    {

    }
    if (input == "help")  
    {
      printHelpMenu();
    }
    else if (input == "clear")
    {
      clearMemory(LTISpecified, signalSpecified, duration, m, n, 
        start, signalData, bData, aData, yData, xData);
      cout << "Memory cleared.\n";
      logFile << "clear\n";
    }
    else if (input == "exit")
    {
      exitTyped = true;
    }
    else if (input == "cls")
    {
      system("cls");
    }
    else if (command == "system")
    {
      // import LTI system from file
      if (!importLTISystemFromFile(filename, bData, aData, m, n))
      {
        cout << "Unable to import a valid LTI system " 
          << "from " << filename << "\n";
      }
      else 
      {
        cout << "System obtained from " << filename << ". recursive "
          << "coefficients: " << n << ", non-recursive " 
          << "coefficients: " << m + 1 << "\n";
        LTISpecified = true;
      }
    }
    else if (command == "signal")
    {
      // import signal from file
      if (!importSignalFromFile(filename, signalData, duration))
      {
        cout << "Unable to import a valid signal from " << filename 
          << "\n";
      }
      else 
      {
        cout << "Signal obtained from " << filename << ". start"
          << " index: " << start << ", duration: " << duration 
          << "\n";
        signalSpecified = true;
      }
    }
  }
  logFile.close();
  return 0;
}