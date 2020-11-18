#include "RegistrarOffice.h"
#include <fstream>
#include <string>
using namespace std;


RegistrarOffice::RegistrarOffice() {
  waitLine = new GenQueue<int>();
  waitTimes = new GenQueue<int>();
}

RegistrarOffice::~RegistrarOffice() {
  delete office;
  delete waitLine;
  delete waitTimes;
  delete idleTimes;
}

void RegistrarOffice::RunSimulation(string location) {
  // cout << "Input a file name: " << endl;
  // string feel;
  // getline(cin, feel);
  // cout << "after";


  string tp;
  int clock = 0;
  int waitCounter = 0;
  ifstream newFile;
  newFile.open(location.c_str());
  if(newFile.is_open()) {

    getline(newFile, tp);
    int windows = stoi(tp);
    office = new Windows(windows); // Parse to integer
    idleTimes = new int[windows];

    getline(newFile, tp);

    while(true) { // Main Loop
      cout << "clock: " << clock << endl;
      int time = stoi(tp);

      //Decrements student time at Windows
      office->timePass();

      //Checks if the time for students to show up is correct
      if(time == clock) {
        getline(newFile, tp);
        int numStd = stoi(tp);
        for(int i = 0; i < numStd; ++i) { //Loops through for however many students there are
          getline(newFile, tp);
          int timeNeeded = stoi(tp);
          waitLine->push(timeNeeded);
        }
      }

      //If there is a student in waitLine then check for open window
      if(!waitLine->isEmpty()) {
        if(office->checkWindows() > -1) { //And there is an open window
          //Take the student out of the waitline and set the window to their time needed
          office->setWindow(office->checkWindows(), waitLine->pop());
          waitTimes->push(waitCounter);
          if(!waitLine->isEmpty()) { //if there still are students in the waiting line we don't want to reset the wait time
            waitCounter++;
          } else {
            waitCounter = 0;
          }
        } else { //And there is not an open window increase student wait time by 1
          waitCounter++;
        }
      } else { //If the line is empty, reset the wait counter
        waitCounter = 0;
      }

      for(int j = 0; j < office->numWindows; ++j) {
        if(office->getWindow(j) == 0) {
          idleTimes[j]++;
        }
      }
      if(clock == 24) {
        break;
      }

      clock++;
    }
    newFile.close();

    //Finds wait time mean, median, longest, and wait times over 10
    int waitMean;
    int waitMedian;
    int longest = 0;
    int tenCount = 0;
    int size = waitTimes->getSize();
    for(int k = 0; !waitTimes->isEmpty(); ++k) {

      //Checks for longest
      if(waitTimes->peek() > longest) {
        longest = waitTimes->peek();
      }
      //Checks for wait times over 10
      if(waitTimes->peek() > 10) {
        tenCount++;
      }
      //checks median value
      if(k = (size / 2)) {
        waitMedian = waitTimes->peek();
      }

      waitMean += waitTimes->pop();
    }
    waitMean /= size;
    cout << "Mean student wait time: " << waitMean << endl;
    cout << "Median student wait time: " << waitMedian << endl;
    cout << "Longest student wait time: " << longest << endl;
    cout << "Number of students waiting for over 10 minutes: " << tenCount << endl;


    longest = 0;
    int idleMean;
    int fiveCount = 0;
    for(int t = 0; t < office->numWindows; ++t) {
      //Checks for longest idle time
      if(office->getWindow(t) > longest) {
        longest = office->getWindow(t);
      }

      //Checks if idle time is over 5
      if(office->getWindow(t) > 5) {
        fiveCount++;
      }

      //Adds to idle mean
      idleMean += office->getWindow(t);
    }
    idleMean /= office->numWindows;

    cout << "Mean window idle time: " << idleMean << endl;
    cout << "Longest window idle time: " << longest << endl;
    cout << "Number of windows idle for over 5 minutes: " << fiveCount << endl;
  } else {
    cout << "Could not open file" << endl;
  }
}
