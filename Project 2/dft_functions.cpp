/**
 * dft_functions.cpp
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

using namespace std;

/**
 * returns true if a valid signal was actually obtained from 
 * filename
 * returns false otherwise
 */
bool importSignalFromFile(string filename, double*& outputData,
  int& duration, int& start) 
{
  ifstream myfile;
  stringstream ss;
  string line;
  double first, second;
  vector<double> data;
  
  // check if filename is valid
  myfile.open(filename);
  if (!(myfile.is_open())) return false;

  // get first line of file
  getline(myfile, line);
  ss.str(line);

  // checks the first line if there is an optional starting index
  ss >> first;
  if (ss >> second)
  {
    if (trunc(first) == first)  // check if first is an integer
    {  
      start = first;
    }
    else
    {
      start = 0;
    }
    data.push_back(second);
  }
  else
  {
    start = 0;
    data.push_back(first);
  }

  duration++; // accounting the first line
  
  // get following lines of data
  while (getline(myfile, line))
  {
    ss.str(line);
    ss.clear();
    double value;
    if (!(ss >> value)) break;
    data.push_back(value);
    duration++;
  }

  // convert data as vector to array
  outputData = new double[duration];
  for (int i = 0; i < duration; i++) 
  {
    outputData[i] = data[i];
  }
  
  return true;
}

/**
 * returns true if the DFT data was successfully exported to a DFT
 * file format file with the specified filename
 * returns false otherwise
 */
bool exportDFTToFile(string filename, double startFreq, 
  double endFreq, int nSteps, double* realPart, double* imagPart, 
  double* magnitude, double* phase)
{
  return false;
}

/**
 * computes the Discrete Fourier Transform of the signal x(n)
 * and stores the real and imaginary parts, magnitude, and phase
 */
void computeDFT(
  double* xData, int xDuration,
  double samplingFreq, double startFreq, double endFreq, int nSteps,
  double*& realPart, double*& imagPart,
  double*& magnitude, double*& phase)
{

}

