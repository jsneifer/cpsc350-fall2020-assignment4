#include "Windows.h"

Windows::Windows() {}

Windows::Windows(int win) {
  openWindows = new int[win];
  numWindows = win;
  for(int i; i < win; ++i) {
    openWindows[i] = 0;
  }
}

Windows::~Windows() {
  delete openWindows;
}

int Windows::checkWindows() {
  for(int i; i < numWindows; ++i) {
    if(openWindows[i] == 0) {
      return i;
    }
  }
  return -1;
}

void Windows::setWindow(int index, int time) {
  openWindows[index] = time;
}

int Windows::getWindow(int index) {
  return openWindows[index];
}

void Windows::timePass() {
  for(int i = 0; i < numWindows; ++i) {
    if(openWindows[i] > 0) {
      openWindows[i]--;
    }
  }
}

bool Windows::isEmpty() {
  bool temp = true;
  for(int i; i < (numWindows-1); ++i) {
    if(openWindows[i] > 0) {
      temp = false;
    }
  }
  return temp;
}
