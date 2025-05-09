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
#include "ltisim_functions.h"

using namespace std;

int main()
{
  bool exitTyped = false;
  bool LTISpecified = false;
  bool signalSpecified = false;
  char extra;
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
    cout << "ltisim> ";
    getline(cin, input);
    ss.str(input);
    ss >> command >> filename;
    ss.clear();
    ss.str(input);

     // check if input is a floating point number
    if (ss >> doubleTest && !(ss >> extra)) 
    {
      inputCommand(doubleTest, LTISpecified, aData, bData, xData, 
        yData, n, m, logFile);
    }
    else if (input == "help")  
    {
      printHelpMenu();
    }
    else if (input == "clear")
    {
      clearMemory(LTISpecified, signalSpecified, duration, m, n, 
        start, signalData, bData, aData, yData, xData, logFile);
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
      LTISystemCommand(filename, bData, aData, yData, xData, m, n, 
        LTISpecified, logFile);
    }
    else if (command == "signal")
    {
      signalCommand(filename, signalData, duration, start,
        signalSpecified, LTISpecified, logFile);
      if (signalSpecified) {
        signalEvaluation(signalData, duration, bData, aData, yData,
          xData, m, n, logFile);
      }
    }
    else
    {
      cout << "Invalid command.\n"; 
    }
  }
  logFile.close();
  return 0;
}