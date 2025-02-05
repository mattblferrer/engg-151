/**
 * main.cpp
 * 
 * BERNARDO, Jonathan
 * FERRER, Matt
 * 
 * Project 1 - Normalized Crosscorrelation
 * ENGG 151.01 - A
*/

#include <iostream>

using namespace std;

class engg151Signal
{
  public:
    double* data;
    int start;
    int duration; 

    engg151Signal() {
      /**
       * Default constructor for the engg151Signal class.
       * Suggested default: one-element signal with value 0.0, 
       * start index 0
       */
      data[1] = {0.0};
      start = 0;
      duration = 1;
    }
    engg151Signal(double* x, int s, int d) {
      /**
       * Constructor for the engg151Signal class, given an array of 
       * double x, a start index s, and a duration d.
       */
      data = x;
      start = s;
      duration = d;
    } 
    bool importSignalFromFile(string filename) {
      /**
       * returns true if a valid signal was actually obtained from filename
       * returns false otherwise
       */
      return false;
    }
    bool exportSignalToFile(string filename) {
      /**
       * returns true if the signal was successfully exported to a file
       * returns false otherwise
       */
      return false;
    }
    int start() {
      return start;
    }
    int end() {
      return start + duration - 1;
    }
    int duration() {
      return duration;
    }
    double* data() {
      return data;
    }
};

engg151Signal normalizedXCorr(engg151Signal x, engg151Signal y) {
  /**
   * computes the normalized crosscorrelation of x crosscorrelated 
   * with y and returns the normalized crosscorrelation as a 
   * signal object.
   * Note that the crosscorrelation is not commutative.
   * This does not need to be a class member.
   */
  return engg151Signal();
}

int main(int argc, char* argv[]) {

  return 0;
}