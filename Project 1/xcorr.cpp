/**
 * xcorr.cpp
 * 
 * BERNARDO, Jonathan
 * FERRER, Matt
 * 
 * Project 1 - Normalized Crosscorrelation
 * ENGG 151.01 - A
*/

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "xcorr_functions.h"

using namespace std;

int main(int argc, char* argv[]) 
{
  if (argc != 4)  // invalid number of arguments
  {  
    cout << "Correct Usage: xcorr [x_file] [y_file] [output file]\n";
    return 1;
  }
  string x_file = argv[1];
  string y_file = argv[2];
  string output = argv[3];

  // default variable definitions
  double* x_data = new double[0];
  double* y_data = new double[0];
  double* rho_data = new double[0];
  int x_duration = 0;
  int y_duration = 0;
  int x_start = 0;
  int y_start = 0;
  int rho_start = 0;
  int rho_duration = 0;

  // import data from files
  if (!importSignalFromFile(x_file, x_data, x_duration, x_start))
  {
    cout << "Unable to import a valid signal from " << x_file << "\n";
    return 1;
  }
  else
  {
    cout << "Signal with start index " << x_start << ", duration "
         << x_duration << ",  imported from "<< x_file << "\n";
  }
  if (!importSignalFromFile(y_file, y_data, y_duration, y_start))
  {
    cout << "Unable to import a valid signal from " << y_file << "\n";
    return 1;
  }
  else
  {
    cout << "Signal with start index " << y_start << ", duration "
         << y_duration << ",  imported from "<< y_file << "\n";
  }
  
  // compute normalized crosscorrelation and output to output_data
  normalizedXCorr(x_data, y_data, x_duration, y_duration, x_start, 
    y_start, rho_start, rho_duration, rho_data);

  // export the normalized crosscorrelation to the output file
  if(!exportSignalToFile(output, rho_data, rho_duration, rho_start))
  {
    cout << "Unable to export the signal with start index " 
         << rho_start << ", duration " << rho_duration 
         << ", to " << output << "\n";
    return 1;
  }
  else
  {
    cout << "\nCrosscorrelation with start index " << rho_start 
         << ", duration " << rho_duration << ", exported to " 
         << output << "\n";
  }

  return 0;
}