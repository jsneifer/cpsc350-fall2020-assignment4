#include <iostream>
using namespace std;


class Windows {
  public:
    Windows();
    Windows(int win); //creates an array of size win
    ~Windows();

    int checkWindows(); // Returns index of first 0, returns -1 if there are no open windows
    void setWindow(int index, int time);
    int getWindow(int index); //returns value at the index
    void timePass(); //Decrements all active windows (windows greater than 0)
    bool isEmpty(); //returns true if all the windows equal zero

    int numWindows; //Total number of windows

  protected:
    int *openWindows;
};
