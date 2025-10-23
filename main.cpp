// main.cpp,
// you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream>
#include "booking.hpp"
#include "week.hpp"
#include "slotRange.hpp"
#include "booking.hpp"

using namespace std;

// info is taken from user input and needs to be validated
int main()
{
    vector<Booking> bookings = {};
    Booking booking;
    std::string b_option;

    std::cout << "Hello would you like to *reserve* a booking? \n"
              << "or would you like to *check* for availability or even *cancel* a booking? \n"
              << "or perhaps you have a *query* about an existing booking? \n"
              << "and if you'd like to *exit* the program we hope to see you again soon. \n";
    std::cin >> b_option;

    if (b_option == "reserve")
    {
        // code for reserving a booking
    }
    else if (b_option == "check")
    // code for checking a booking
    {
        std::cout << "Here's a list of all bookings:\n";
        if (booking.num_of_bookings == 0)
        {
            std::cout << "There are no bookings \n"
            <<"Only the maintenance weeks are unavailable. Have a great day!\n";
            return 0;
        }
        for (int i = 0; i < booking.num_of_bookings; i++)
        {
            std::cout << "Booking ID: " << booking.getBookingID() 
            << ", Week: " << booking.getWeek().getWeek() 
            << ", Slot Range: " << booking.getSlotRange().getBeginSlot() 
            << " to " << booking.getSlotRange().getEndSlot() << "\n";
        }
    }
    else if (b_option == "cancel")
    {
        int cancel_num;
        if (booking.getBookingID() == 0)
        {
            std::cout << "There are no bookings to cancel.\n";
            return 0;
        }
        // code for cancelling a booking
        std::cout << "What is the booking Number? \n";
        cin >> cancel_num;

        if (remove_booking(bookings, cancel_num) == true)
        {
            // code to cancel the booking
            std::cout << "Booking under " << cancel_num << " has been cancelled.\n";
        }
        else
        {
            std::cout << "Booking ID " << cancel_num << " never existed.\n";
        }
    }
    else if (b_option == "query")
    // code for querying a booking
    {

    else if (b_option == "exit")
    {
        std::cout << "Thank you for Stopping in. Goodbye!\n";
        return 0;
    }
    else
    {
    std::cout << "Invalid option. Please try again.\n";
 }






}




























/*{

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

