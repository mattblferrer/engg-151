/**
 * ltisim_functions.h
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

/**
 * returns true if a valid signal was actually obtained from 
 * filename
 * returns false otherwise
 */
bool importSignalFromFile(string filename, double*& outputData,
  int& duration); 

/**
 * returns true if a valid LTI system was actually obtained from 
 * filename
 * returns false otherwise
 */
bool importLTISystemFromFile(string filename, double*& b_data, 
  double*& a_data, int& m, int& n);

/**
 * computes the outputs of the LTI system given the previous inputs, 
 * outputs, and coefficients of the system
 */
void computeOutputs(double* acoeff, double* bcoeff,
  double* inputs, double* outputs, int sizea, int sizeb,
  double* input_samples, int nSamples,
  double** output_samples);

/**
 * prints the help menu for the program, invoked by typing the 
 * command "help"
 */
void printHelpMenu();

/**
 * clears the memory of the program by setting all variables to 0 and 
 * deleting all dynamically allocated arrays
 */
void clearMemory(bool& LTISpecified, bool& signalSpecified, 
  int& duration, int& m, int& n, int& start, double*& signalData, 
  double*& bData, double*& aData, double*& yData, double*& xData, 
  ofstream& logFile);

/**
 * runs the LTI system file check and outputs the results to the
 * console and the log file.
 */
void LTISystemCommand(string filename, double*& bData, 
  double*& aData, int& m, int& n, bool& LTISpecified,
  ofstream& logFile);

/**
 * validates if the signal file was successfully read and outputs
 * the results to the console and the log file. 
 */
void signalCommand(string filename, double*& signalData, 
  int& duration, int& start, bool& signalSpecified, 
  bool& LTISpecified, ofstream& logFile);
