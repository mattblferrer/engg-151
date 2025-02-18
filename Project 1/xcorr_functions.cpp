/**
 * xcorr_functions.cpp
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

/**
* returns true if a valid signal was actually obtained from 
* filename
* returns false otherwise
*/
bool importSignalFromFile(string filename, double*& output_data,
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
  output_data = new double[duration];
  for (int i = 0; i < duration; i++) 
  {
    output_data[i] = data[i];
  }
  
  return true;
}

/**
 * returns true if the signal was successfully exported to a 
 * file
 * returns false otherwise
 */
bool exportSignalToFile(string filename, double*& rho_data, 
  int duration, int start) 
{
  ofstream myfile;
  myfile.open(filename);
  if (!(myfile.is_open())) return false;

  // export the normalized crosscorrelation to the file
  myfile << start;
  for (int i = 0; i < duration; i++) 
  {
    myfile << "\t" << rho_data[i] << "\n";  //print on file
  }

  // counting if the duration of normalized crosscorrelation is < 20
  if (duration < 20)
  {
    cout << "\nNormalized crosscorrelation: \n";
    cout << start;
    for (int i = 0; i < duration; i++) 
    {
      cout << "\t" << rho_data[i] << "\n";  //print on console
    }
  }  
  
  return true;
}

/**
 * computes the normalized crosscorrelation of x crosscorrelated 
 * with y and returns the normalized crosscorrelation as an array.
 * Note that the crosscorrelation is not commutative.
 */
void normalizedXCorr(double* x_raw, double* y_raw, int x_duration,
  int y_duration, int x_start, int y_start, int& rho_start,
  int& rho_duration, double*& rho_xy) 
{
  // initialize variables
  double* x = new double[x_duration];
  double* y = new double[y_duration];
  double x_sum = 0;
  double y_sum = 0;

  // compute array sums of x and y
  for (int i = 0; i < x_duration; i++) 
  {
    x_sum += x_raw[i];
  }
  for (int i = 0; i < y_duration; i++) 
  {
    y_sum += y_raw[i];
  }

  // compute x(n) and y(n)
  for (int i = 0; i < x_duration; i++) 
  {
    x[i] = x_raw[i] - (x_sum / x_duration);
  }
  for (int i = 0; i < y_duration; i++) 
  {
    y[i] = y_raw[i] - (y_sum / y_duration);
  }

  // get the range of the crosscorrelation
  int l_min_half = min(x_start, y_start);
  int l_max_half = max(x_start + x_duration, y_start + y_duration);
  int l_range_half = l_max_half - l_min_half;
  int l_min = l_min_half - l_range_half / 2 + 1; // +1 remove start 0s
  int l_max = l_max_half + l_range_half / 2 - 1; // -1 remove end 0s
  rho_start = l_min;
  rho_duration = l_max - l_min;

  // compute crosscorrelation between x and y (r_xy)
  double* r_xy = new double[rho_duration];
  for (int l = l_min; l < l_max; l++) 
  {
    r_xy[l - l_min] = 0;
    for (int n = 0; n < x_duration; n++) 
    {
      if ((n - l >= 0) && (n - l < y_duration)) // check if in bounds
      { 
        r_xy[l - l_min] += x[n] * y[n - l];  // shifting y
      }
    }
  }

  // compute autocorrelations of x and y (r_xx(0) and r_yy(0))
  double r_xx = 0;
  double r_yy = 0;
  for (int n = 0; n < x_duration; n++) 
  {
    r_xx += x[n] * x[n];
  }
  for (int n = 0; n < y_duration; n++) 
  {
    r_yy += y[n] * y[n];
  }

  // compute normalized crosscorrelation (rho_xy)
  rho_xy = new double[rho_duration];
  for (int l = l_min; l < l_max; l++) 
  {
    rho_xy[l - l_min] = r_xy[l - l_min] / sqrt(r_xx * r_yy);
  }
}
