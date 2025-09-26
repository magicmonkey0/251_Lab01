//main.cpp,  
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream>

#include "week.hpp"
#include "slotRange.hpp"

using namespace std;

// info is taken from user input and needs to be validated
int main(){
  // testing 
  int reserve = 0;
  bool reserved[24];
  fstream outputFile;

  outputFile.open("output.txt");
  if (outputFile.is_open()){}
  else { cout << "ERROR: could not open file.\n"; };

  Week week(2);

  week.isValid();
  week.printInfo(outputFile);
  week.setReserved(0, true);
  week.setReserved(1, true);
  reserve = week.getReserved(1);
  week.printReservedSlots(outputFile);


  return 0;
} 
