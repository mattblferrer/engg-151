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
 #include <iomanip>
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
  string logFile;
  if (argc == 7)  // logfile is provided
  {
    logFile = argv[6];
  }
  else  // logfile not provided, fallback to default
  {
    logFile = "dftlog.txt";
  }

  // create double pointers and ints for DFT data and results
  double* xData = new double[0];
  double* realPart = new double[nSteps + 1];
  double* imagPart = new double[nSteps + 1];
  double* magnitude = new double[nSteps + 1];
  double* phase = new double[nSteps + 1];
  int duration = 0;
  int start = 0;

  // import signal from file
  if (!importSignalFromFile(signalFile, xData, duration, start))
  {
    cout << "Unable to import a valid signal from " << signalFile 
         << "\n";
    return 1;
  }
  else
  {
    cout << "Signal of duration " << duration 
         << " extracted from "<< signalFile << "\n";
  }

  // compute DFT
  computeDFT(xData, duration, samplingRate, startFreq, endFreq, 
    nSteps, realPart, imagPart, magnitude, phase);

  // export DFT data to file
  if (!exportDFTToFile(logFile, startFreq, endFreq, nSteps, 
    realPart, imagPart, magnitude, phase))
  {
    cout << "Unable to export DFT data to " << logFile << "\n";
    return 1;
  }
  else
  {
    cout << "DFT data successfully exported to " << logFile << "\n";
  }
  
  return 0;
}