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
bool importLTISystemFromFile(string filename, double*& b_data, 
  double*& a_data, int& m, int& n)
{
  ifstream myfile;
  stringstream ss;
  string line;

  // check if filename is valid
  myfile.open(filename);
  if (!(myfile.is_open())) return false;

  // get first line of file (M + 1) and second line of file (N)
  getline(myfile, line);
  ss.str(line);
  if (!(ss >> m)) return false; // checks if there is a first line
  ss.clear();
  getline(myfile, line);
  ss.str(line);
  if (!(ss >> n)) return false; // checks if there is a second line
  ss.clear();

  // validate that (M + 1) and (N) are nonnegative and nonzero
  if (m < 0 || n < 0) return false;

  m--;

  // temporary double arrays for temporary b_data and a_data
  double* b_temp_data = new double[m + 1];
  double* a_temp_data = new double[n];

  // validate b_data and a_data from files
  for (int i = 0; i <= m; i++)
  {
    ss.clear();
    getline(myfile, line);
    ss.str(line);
    double value;
    if (!(ss >> value)) return false; // checks if there is a value
    b_temp_data[i] = value;
  }
  for (int i = 0; i < n; i++)
  {
    ss.clear();
    getline(myfile, line);
    ss.str(line);
    double value;
    if (!(ss >> value)) return false; // checks if there is a value
    a_temp_data[i] = value;
  }
  b_data = b_temp_data;
  a_data = a_temp_data;
  myfile.close();

  return true;
}

/**
 * computes the outputs of the LTI system given the previous inputs, 
 * outputs, and coefficients of the system
 */
void computeOutputs(double* acoeff, double* bcoeff,
  double* inputs, double* outputs, int sizea, int sizeb,
  double* input_samples, int nSamples,
  double** output_samples)
{

}

/**
 * prints the help menu for the program, invoked by typing the 
 * command "help"
 */
void printHelpMenu()
{
  const string help_message = "\n"
    "LTISim - Linear Time-Invariant System Simulator\n"
    "Type \"help\" for more information.\n"
    "Type \"system [filename]\" to extract an LTI system from a "
    "file with the specified filename.\n"
    "Type any floating point number to add another input to " 
    "the LTI system.\n"
    "Type \"signal [filename]\" to extract a signal from a file "
    "with the specified filename.\n"
    "Type \"clear\" to clear the application's memory of previous "
    "inputs and outputs to 0.\n"
    "Type \"exit\" to exit the program.\n"
    "Type \"cls\" to clear the screen.\n";
  cout << help_message;
}

/**
 * clears the memory of the program by setting all variables to 0 and 
 * deleting all dynamically allocated arrays
 */
void clearMemory(bool& LTISpecified, bool& signalSpecified, 
  int& duration, int& m, int& n, int& start, double*& signalData, 
  double*& bData, double*& aData, double*& yData, double*& xData, 
  ofstream& logFile)
{
  // validate if there is an LTI system to be cleared
  if (LTISpecified == false) 
  {
    cout << "No specified LTI system.\n";
    return;
  }

  LTISpecified = false;
  signalSpecified = false;
  duration = 0;
  m = 0;
  n = 0;
  start = 0;
  signalData = new double[0];
  bData = new double[0];
  aData = new double[0];
  yData = new double[0];
  xData = new double[0];
  cout << "Memory cleared.\n";
  logFile << "clear\n";
}

/**
 * runs the LTI system file check and outputs the results to the
 * console and the log file.
 */
void LTISystemCommand(string filename, double*& bData, 
  double*& aData, int& m, int& n, bool& LTISpecified,
  ofstream& logFile)
{
  // import LTI system from file
  if (!importLTISystemFromFile(filename, bData, aData, m, n))
  {
    cout << "Unable to import a valid LTI system " 
      << "from " << filename << "\n";
    return;
  }
  LTISpecified = true;
  cout << "System obtained from " << filename << ". recursive "
    << "coefficients: " << n << ", non-recursive " 
    << "coefficients: " << m + 1 << "\n";
  logFile << "new system\n";
  for (int i = 0; i <= m; i++)
  {
    logFile << bData[i] << "\n";
  }
  for (int i = 0; i < n; i++)
  {
    logFile << aData[i] << "\n";
  }
  logFile << "ready\n";
}

/**
 * validates if the signal file was successfully read and outputs
 * the results to the console and the log file. 
 */
void signalCommand(string filename, double*& signalData, 
  int& duration, int& start, bool& signalSpecified, 
  bool& LTISpecified, ofstream& logFile)
{
  // validate if there is an LTI system loaded for the signal
  if (LTISpecified == false) 
  {
    cout << "No specified LTI system.\n";
    return;
  }

  // import signal from file
  if (!importSignalFromFile(filename, signalData, duration))
  {
    cout << "Unable to import a valid signal from " << filename 
      << "\n";
    return;
  }
  signalSpecified = true;
  cout << "Signal obtained from " << filename << ". start"
    << " index: " << start << ", duration: " << duration 
    << "\n";
}