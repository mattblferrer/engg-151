/**
 * dft.cpp
 * 
 * BERNARDO, Jonathan
 * FERRER, Matt
 * 
 * Project 2 - Fourier Transform
 * ENGG 151.01 - A
 */

 #include <cmath>
 #include <fstream>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <vector>
 #include "dft_functions.h"

using namespace std;

int main(int argc, char* argv[])
{
  if (argc != 6 && argc != 7)  // invalid number of arguments
  {
    cout << "Correct Usage: dft [signal-file] [sampling-rate] "; 
    cout << "[start-freq] [end-freq] [nSteps] [optional logfile]\n";
    return 1;
  }

  // valid number of arguments, parse command line arguments
  string signalFile = argv[1];
  double samplingRate = stod(argv[2]);
  double startFreq = stod(argv[3]);
  double endFreq = stod(argv[4]);
  int nSteps = stoi(argv[5]);
  if (argc == 7)  // logfile is provided
  {
    string logfile = argv[6];
  }
  else  // logfile not provided, fallback to default
  {
    string logfile = "dftlog.txt";
  }

  // create double pointers for DFT data and results
  double* xData;
  double* realPart;
  double* imagPart;
  
  return 0;
}