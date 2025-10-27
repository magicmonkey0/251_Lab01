// main.cpp,
// you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream>
#include <string>

#include "booking.hpp"
#include "week.hpp"
#include "slotRange.hpp"
#include "booking.hpp"
#include "BookingSystem.hpp"

using namespace std;

/*Function Declaration Prison----------------------------
Booking reserve_function();
bool remove_booking(vector<Booking> &bookings);
void display_bookings(const)


*/

// info is taken from user input and needs to be validated
// checks for valid input for doing a task like reserving or cancelling a booking
// calls member functions from other classes to perform the task
int main()
{
  // new tests for Lab2
  BookingSystem bookingSystem = BookingSystem();
  bool running  = true;
  SlotRange range;
  int weekNum = 0;
  int beginSlot = 0;
  int endSlot = 0;
  int choice = 0;
  int bookingIDtemp = 0;
  string customerName;

  // loop: read commands: reserve, query, cancel, check, exit
  // after each reserve/cancel/query command, print the week's free/reserved slots
  // handle invalid inputs (eg. overlaps, invalid weeks) with crashing
  while (running)
  {
    bookingIDtemp = 0;
    weekNum = 0;

    cout << "\n========== OPTIONS ============\n";
    cout << "1. reserve [week] [beginSlot] [endSlot] \n2. query [bookingID] \n3. cancel [bookingID] \n4. check [week] \n5. exit\nChoose an option: ";
    cin >> choice;
    cout << "===============================\n";

    switch (choice)
    {
      // after each reserve/query/cancel command, print the week's free/reserved slots
      case 1:
        // reserve a slot and print ID
        cout << "Enter a week to reserve: ";
        cin >> weekNum;
        cout << "Enter a begin slot: ";
        cin >> beginSlot;
        cout << "Enter an end slot: ";
        cin >> endSlot;
        range = SlotRange(beginSlot, endSlot);
        cout << "Enter a name for the booking: ";
        cin >> customerName;
        cout << "===============================\n";

        bookingIDtemp = bookingSystem.addBooking(weekNum, range, customerName);

        if (bookingIDtemp == -1)
        {
          cout << "ERROR: cannot reserve this booking. Booking list is full." << endl;
        }
        else if (bookingIDtemp == -2)
        {
          cout << "ERROR: cannot reserve this booking. Reservation invalid." << endl;
        }
        else
        {
          cout << "Booking successful. ID = " << bookingIDtemp << endl;
        }

        bookingSystem.checkWeek(weekNum);

        break;
      case 2:
        // query: print booking details of given ID
        cout << "Enter booking ID you would like to query: ";
        cin >> bookingIDtemp;
        bookingSystem.queryBooking(bookingIDtemp);

        bookingSystem.checkWeek(bookingSystem.getWeek(weekNum).getWeek());

        break;
      case 3:
        // cancel: remove the booking ID and print message indicating success (i think function already does that)
        cout << "Enter booking ID you would like to cancel: ";
        cin >> bookingIDtemp;
        bookingSystem.cancelBooking(bookingIDtemp);

        break;
      case 4:
        // check: print free/reserved slots for the week
        cout << "Enter week you would like to check: ";
        cin >> weekNum;
        bookingSystem.checkWeek(weekNum);

        break;
      case 5:
        // exit: exit program
        running = false;
        cout << "Exiting program." << endl;
        break;
      default:
        cout << "Invalid choice." << endl;
    }
  }

    return 0;
}
  

