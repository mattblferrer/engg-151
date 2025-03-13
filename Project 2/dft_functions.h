/**
 * dft_functions.h
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

using namespace std;

/**
* returns true if a valid signal was actually obtained from 
* filename
* returns false otherwise
*/
bool importSignalFromFile(string filename, double*& outputData,
  int& duration);

/**
 * returns true if the DFT data was successfully exported to a DFT
 * file format file with the specified filename
 * returns false otherwise
 */
bool exportDFTToFile(string filename, double startFreq, 
  double endFreq, int nSteps, double* realPart, double* imagPart, 
  double* magnitude, double* phase);

/**
 * computes the Discrete Fourier Transform of the signal x(n)
 * and stores the real and imaginary parts, magnitude, and phase
 */
void computeDFT(
  double* xData, int duration,
  double samplingRate, double startFreq, double endFreq, int nSteps,
  double*& realPart, double*& imagPart,
  double*& magnitude, double*& phase);

/**
 * returns true if the input string is a valid positive integer
 * greater than zero
 */
bool isPositiveInteger(const string& input);
