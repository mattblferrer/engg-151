/**
 * xcorr_functions.h
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

using namespace std;

bool importSignalFromFile(string filename, double*& output_data,
  int& duration, int& start);
bool exportSignalToFile(string filename, double*& rho_data, 
  int duration, int start);
void normalizedXCorr(double* x_raw, double* y_raw, int x_duration,
  int y_duration, int x_start, int y_start, int& rho_start,
  int& rho_duration, double*& rho_xy);