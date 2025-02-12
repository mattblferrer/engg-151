/**
 * main.cpp
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

class engg151Signal
{
  public:
    double* s_data;
    int s_start;
    int s_duration; 

    /**
     * Default constructor for the engg151Signal class.
     * Suggested default: one-element signal with value 0.0, 
     * start index 0
     */
    engg151Signal() 
    {
      s_data[1] = {0.0};
      s_start = 0;
      s_duration = 1;
    }
    /**
      * Constructor for the engg151Signal class, given an array of 
      * double x, a start index s, and a duration d.
      */
    engg151Signal(double* x, int s, int d) 
    {
      
      s_data = x;
      s_start = s;
      s_duration = d;
    } 
    /**
      * returns true if a valid signal was actually obtained from 
      * filename
      * returns false otherwise
      */
    bool importSignalFromFile(string filename, engg151Signal& signal) 
    {
      ifstream myfile;
      stringstream ss;
      string line;
      int duration = 0;
      int start;
      double first, second;
      int number;
      vector<double> data;

      // check if filename is valid
      myfile.open(filename);
      if (!myfile.is_open()) return false;

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
      
      // get following lines of data
      while (getline(myfile, line))
      {
        ss.str(line);
        ss.clear();
        double value;
        ss >> value;
        data.push_back(value);
        duration++;
      }
      engg151Signal new_signal(data.data(), start, duration);
      signal = new_signal;
      
      return true;
    }
    /**
     * returns true if the signal was successfully exported to a 
     * file
     * returns false otherwise
     */
    bool exportSignalToFile(string filename) 
    {
      
      return false;
    }
    
    int start() 
    {
      return s_start;
    }
    int end() 
    {
      return s_start + s_duration - 1;
    }
    int duration() 
    {
      return s_duration;
    }
    double* data() 
    {
      return s_data;
    }
};

/**
 * computes the normalized crosscorrelation of x crosscorrelated 
 * with y and returns the normalized crosscorrelation as a 
 * signal object.
 * Note that the crosscorrelation is not commutative.
 * This does not need to be a class member.
 */
engg151Signal normalizedXCorr(engg151Signal x, engg151Signal y) 
{
  return engg151Signal();
}

int main(int argc, char* argv[]) 
{
  if (argc != 3)  // invalid number of arguments
  {  
    cout << "Correct Usage: xcorr [xdata] [ydata] [output file]\n";
    return 1;
  }
  string xdata = argv[0];
  string ydata = argv[1];
  string output = argv[2];

  return 0;
}