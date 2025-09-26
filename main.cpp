//main.cpp,  
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream>

#include "week.hpp"
#include "slotRange.hpp"

using namespace std;

// info is taken from user input and needs to be validated
int main(){

  Week week;
  SlotRange slotRange;
  int weekNum, beginSlot, endSlot = 0;

  // asuming correct input?
  cout << "Enter week number (1-52): ";
  cin >> weekNum;
  week = Week(weekNum);

  cout << "For the slot range, the range needs to be in the range (0-23) and a multiple of 2.\n";
  cout<< "Enter a begin slot value: ";
  cin >> beginSlot;
  cout << "Enter an end slot value: ";
  cin >> endSlot;
  slotRange = SlotRange(beginSlot, endSlot);

  // original objects from user input
  cout << "\n=== Original Objects ===\n";
  week.printInfo(cout);
  slotRange.printInfo(cout);



  // testing 
  // int reserve = 0;
  // bool reserved[24];
  // fstream outputFile;

  // outputFile.open("output.txt");
  // if (outputFile.is_open()){}
  // else { cout << "ERROR: could not open file.\n"; };

  // Week week(2);

  // week.isValid();
  // week.printInfo(outputFile);
  // week.setReserved(0, true);
  // week.setReserved(1, true);
  // reserve = week.getReserved(1);
  // week.printReservedSlots(outputFile);


  return 0;
} 
