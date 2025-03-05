/**
 * dft_functions.cpp
 * 
 * BERNARDO, Jonathan
 * FERRER, Matt
 * 
 * Project 2 - Fourier Transform
 * ENGG 151.01 - A
 */

#define _USE_MATH_DEFINES 

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
  ofstream myfile;
  myfile.open(filename, ios::app);
  if (!(myfile.is_open())) return false;
  myfile << fixed;

  // export the first set of DFT data to the log file
  myfile << "frequency (Hz)\treal part\timaginary part\n";
  for (int i = 0; i < nSteps + 1; i++)
  {
    myfile << startFreq + i * (endFreq - startFreq) / nSteps << "\t"
           << realPart[i] << "\t" << imagPart[i] << "\n";
  }

  // export the second set of DFT data to the log file
  myfile << "\n\nfrequency (Hz)\tmagnitude\tphase (degrees)\n";
  for (int i = 0; i < nSteps + 1; i++)
  {
    myfile << startFreq + i * (endFreq - startFreq) / nSteps << "\t"
           << magnitude[i] << "\t" << phase[i] << "\n";
  }
  myfile << "\n"; // add a newline at the end of the file
  myfile.close();

  cout << fixed;  // convert from scientific notation to fixed format

  // output results from log file to console
  if (nSteps < 10)
  {
    // print the first set of DFT data
    cout << "frequency (Hz)\treal part\timaginary part\n";
    for (int i = 0; i < nSteps + 1; i++)
    {
      cout << startFreq + i * (endFreq - startFreq) / nSteps << "\t"
           << realPart[i] << "\t" << imagPart[i] << "\n";
    }

    // print the second set of DFT data
    cout << "\n\nfrequency (Hz)\tmagnitude\tphase (degrees)\n";
    for (int i = 0; i < nSteps + 1; i++)
    {
      cout << startFreq + i * (endFreq - startFreq) / nSteps << "\t"
           << magnitude[i] << "\t" << phase[i] << "\n";
    }
  }

  return true;
}

/**
 * computes the Discrete Fourier Transform of the signal x(n)
 * and stores the real and imaginary parts, magnitude, and phase
 */
void computeDFT(
  double* xData, int duration,
  double samplingRate, double startFreq, double endFreq, int nSteps,
  double*& realPart, double*& imagPart,
  double*& magnitude, double*& phase)
{
  for (int i = 0; i < nSteps + 1; i++)  // initialize DFT arrays to 0
  {
    double currFreq = startFreq + i * (endFreq - startFreq) / nSteps;
    realPart[i] = 0;
    imagPart[i] = 0;
    magnitude[i] = 0;
    phase[i] = 0;
    
    for (int j = 0; j < duration; j++)  // compute DFT rectangular
    {
      realPart[i] += xData[j] * cos(2 * M_PI * currFreq 
        * j / samplingRate);
      imagPart[i] -= xData[j] * sin(2 * M_PI * currFreq 
        * j / samplingRate);
    }

    // compute DFT polar from rectangular form
    magnitude[i] = sqrt(pow(realPart[i], 2) + pow(imagPart[i], 2));
    phase[i] = atan2(imagPart[i], realPart[i]) * 180 / M_PI;
  }
}

