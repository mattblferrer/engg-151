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
void compute_outputs(double* acoeff, double* bcoeff,
  double* inputs, double* outputs, int sizea, int sizeb,
  double* input_samples, int nSamples,
  double** output_samples)
{

}

