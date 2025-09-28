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
  ofstream outputFile; // for printing outputs to file stream
  outputFile.open("output.txt");
  if (outputFile.is_open()){}
  else { cout << "ERROR: could not open file.\n"; exit(0); };

  // assuming correct input? yes
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
  week.isValid();
  slotRange.isValid();

  // changing the values 
  cout << "\nUpdating value to week 14 and slotRange 10 to 14.\n";
  week.setWeek(14);
  slotRange.setBeginSlot(10);
  slotRange.setEndSlot(14);
  // print the new values using getters
  cout << "\n=== New Objects ===\n";
  cout << "Week: " << week.getWeek() << endl;
  cout << "SlotRange: " << slotRange.getBeginSlot() << " to " << slotRange.getEndSlot() << endl;
  week.isValid();
  slotRange.isValid();

  // testing reservations
  week.setReserved(0, true);
  week.setReserved(5, true);
  cout << "\n=== New Object Updated===\n";
  week.printInfo(cout);
  cout << "Test - get reserved slot of index 0: " << week.getReserved(0) << endl;
  week.printReservedSlots(cout);
  week.printFreeSlots(cout);
  week.isValid();

  // testing: output onto file
  outputFile << "\n=== New Objects ===\n";
  week.printInfo(outputFile);
  slotRange.printInfo(outputFile);
  week.printReservedSlots(outputFile);

  return 0;
} 
