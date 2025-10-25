// main.cpp,
// you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream>
#include "booking.hpp"
#include "week.hpp"
#include "slotRange.hpp"
#include "bookingsystem.hpp"
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
    // establishes the booking vector and b_option string
    // b-option is the user selected task stands for booking option
    //vector<Booking> bookings;
    //string b_option;

    // first call and response section to select a task
    std::cout << "Hello would you like to *reserve* a booking? \n"
              << "or would you like to *check* for availability or even *cancel* a booking? \n"
              << "or perhaps you have a *query* about an existing booking? \n"
              << "and if you'd like to *exit* the program we hope to see you again soon. \n";
    //--------------------------------------------------------
    // while loop to allow the program to continue until the user decides to exit or booking task is completed successfully
    while (true){
        cout << "Your option: ";
        std::cin >> b_option;
        //sets procedure based on user selected task and calls associated bookingsystem task
        if (b_option == "reserve")
        {
            bookingsystem.reserve_function();
        }
        else if (b_option == "check"){
            display_all_bookings(bookings);
        }
        else if (b_option == "cancel"){
            bookingsystem.remove_booking(bookings);
        }
    
        else if (b_option == "query")
        // code for checking a booking's details
        {
            bookingsystem.query_booking();
        }
        else if (b_option == "exit"){
            std::cout << "Thank you for Stopping in. Goodbye!\n";
            return 0;
        }
        else {
            std::cout << "Invalid option. Please try again.\n";
            return 0;
        }
    }


}






/* function for displaying all the bookings in the vector
void display_all_bookings(const vector<Booking> &bookings){
    // if case for if the booking vector is empty (state is true)
    if (bookings.empty()) {
        std::cout << "There are no bookings available.\n";
        return;
    }
    // displays all in the booking vector when not empty
    // shows booking ID, customer name, week number, and slot range
    std::cout << "Here's a list of all bookings so far:\n";
    for(const auto &booking : bookings){
        std::cout << "Booking ID: " << booking.getBookingID() <<
        "Customer Name: " << booking.getCustomerName() <<
        "Week Number: " << booking.getWeek().getWeek() <<
        "Slot Range: " << booking.getSlotRange().getBeginSlot() << " to " << booking.getSlotRange().getEndSlot() << "\n";
        std::cout << "--------------------------\n";
    }
}
//--------------------------------------------------------
















{

    Week week;
    SlotRange slotRange;
    int weekNum, beginSlot, endSlot = 0;
    ofstream outputFile; // for printing outputs to file stream
    outputFile.open("output.txt");
    if (outputFile.is_open())
    {
    }
    else
    {
        cout << "ERROR: could not open file.\n";
        exit(0);
    };

    // assuming correct input? yes
    cout << "Enter week number (1-52): ";
    cin >> weekNum;
    week = Week(weekNum);

    // cout << "For the slot range, the range needs to be in the range (0-23) and a multiple of 2.\n";
    cout << "Enter a begin slot value (0-23): ";
    cin >> beginSlot;
    cout << "Enter an end slot value (0-23): ";
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

