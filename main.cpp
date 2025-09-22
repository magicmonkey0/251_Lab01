//main.cpp,  
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream>

#include "week.hpp"
#include "slotRange.hpp"

using namespace std;


int main(){
  Week week;
  int weekNum = 0;

  cout << "Enter a week number: ";
  cin >> weekNum;
  week.setWeek(weekNum);
  if (week.isValid() == FALSE)
  {
    cout << "ERROR: week " << week.getWeek() << "is not within the valid week range (1-52).";
    exit(0);
  }
  //idk

  return 0;
} 
