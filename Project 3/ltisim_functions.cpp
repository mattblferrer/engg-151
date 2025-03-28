/**
 * ltisim_functions.cpp
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
  int& duration)
{
  ifstream myfile;
  stringstream ss;
  string line;
  string first;
  double second;
  vector<double> data;
  
  // check if filename is valid
  myfile.open(filename);
  if (!(myfile.is_open())) return false;

  // get first line of file
  getline(myfile, line);
  ss.str(line);

  if (!(ss >> first)) return false; // checks if there is a first line

  // checks the first line if there is an optional starting index
  if (!(ss >> second)) data.push_back(stod(first)); // no index
  else 
  {
    // validates that input does not have a non-numeric character
    for (char a:first)
    {
      if (!isdigit(a)) return false;
    }
    data.push_back(second); 
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

  myfile.close();

  // convert data as vector to array
  outputData = new double[duration];
  for (int i = 0; i < duration; i++) 
  {
    outputData[i] = data[i];
  }
  
  return true;
}

/**
 * returns true if a valid LTI system was actually obtained from 
 * filename
 * returns false otherwise
 */
// TODO: function implementation
bool importLTISystemFromFile(string filename, double*& a_data, 
  double*& b_data, int& m, int& n)
{
  return true;
}
