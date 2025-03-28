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
bool importLTISystemFromFile(string filename, double*& a_data, 
  double*& b_data, int& m, int& n);

