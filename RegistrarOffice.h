#include <iostream>
using namespace std;
#include "GenQueue.cpp"
#include "Windows.cpp"

class RegistrarOffice {
  public:
    RegistrarOffice();
    ~RegistrarOffice();

    void RunSimulation(string location); //Simulates the registrar's office
  protected:
    Windows *office;
    GenQueue<int> *waitLine;
    GenQueue<int> *waitTimes;
    int *idleTimes;

};
