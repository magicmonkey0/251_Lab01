#include "bookingsystem.hpp"
#include <iostream>
using namespace std;

// function for reserving a booking
Booking BookingSystem::reserve_function()
{
    // creates variables for use in the function
    // followed by a call and response for user input
    string customer_name;
    int week_num, begin_slot, end_slot;
    string y_n;

    cout<< "Would you still like to make a booking? *yes* or *no* \n";
    cin >> y_n;
    if (y_n == "no")
    {
        cout << "Thank you for stopping by. Goodbye!\n";
        exit(0);
    }
    else if y_n != ("yes"||"no") {
        cout << "Invalid option. Please try again.....\n\n\n";
        return reserve_function();
    }
    else {

        cout << "What name would you like to book under? \n";
        cin >> customer_name;

        cout << "What week number would you like to book? (1-52) \n";
        cin >> week_num;
        Week week(week_num);
        
        // uses the week class functions to check for valid week number
        if (!week.isValid() || week.isMaintenanceWeek() || week.isPeak())
        {
            std::cout << "Invalid week number. Please try again.....\n\n\n";
            return reserve_function();
        }
    
        cout << "What begin slot would you like to book? (0-23) \n";
        cin >> begin_slot;
        cout << "What end slot would you like to book? (0-23) \n";
        cin >> end_slot;
        SlotRange range(begin_slot, end_slot);
        
        // uses the slotRange class function to check for valid slot range
        if (!range.isValid())
        {
            std::cout << "Invalid slot range. Please try again.....\n\n\n";
            return reserve_function();
        }
        Booking newbooking(name, week, range);

        for (const auto &booking : bookings)
        {
            if (newbooking.conflicts_with(booking))
            {
                std::cout << "Booking conflicts with an existing booking. Please try again.....\n\n\n";
                return reserve_function();
            }
        }
        bookings.push_back(newbooking);
        cout << "Booking successful! Your booking ID is: " << booking.getBookingID() << "\n";
        cout << "The Booking is under" << booking.getCustomerName() << "for week" << booking.getWeek().getWeek() << "from slot"
              << booking.getSlotRange().getBeginSlot() << "to" << booking.getSlotRange().getEndSlot() << "\n";
        
              return newbooking;
    }
    
}
//--------------------------------------------------------
// removes a booking based on booking ID
bool BookingSystem::cancel_booking(){
    if bookings.empty() {
        cout << "There are no bookings to cancel.\n";
        return false;
    }
    int cbookingID;
    cout << "Enter the booking ID to cancel: \n";
    cin >> cbookingID;

    if Booking::remove_booking(bookings, cbookingID) {
        cout << "Booking with ID " << cbookingID << " has been cancelled.\n";
        return true;
    } else {
        cout << "No booking found with ID " << cbookingID << ".\n";
        return false;
    }
}
//--------------------------------------------------------
// Displays all the current bookings
void BookingSystem::display_all_bookings()const{
    if (bookings.empty()) {
        cout << "There are no current bookings.\n";
        return;
    }
    cout << "Here are all the current bookings:\n";
    for (const auto &booking : bookings) {
        cout << "Booking ID: " << booking.getBookingID()
             << ", Name: " << booking.getCustomerName()
             << ", Week: " << booking.getWeek().getWeek()
             << ", Slot Range: " << booking.getSlotRange().getBeginSlot()
             << " to " << booking.getSlotRange().getEndSlot() << "\n";
    }
}
//--------------------------------------------------------
// checks the details of a booking based on booking ID
void BookingSystem::query_booking() const {
    if (bookings.empty()) {
        cout << "There are no bookings to check on.\n";
        return;
    }
    int qbookingID;
    cout << "Enter the booking ID you'd like to check on: \n";
    cin >> qbookingID;

    for (const auto &booking : bookings) {
        if (booking.getBookingID() == qbookingID) {
            cout << "Booking Details:\n" <<
            "Booking ID: " << booking.getBookingID() <<
            "Customer Name: " << booking.getCustomerName()  <<
            "Week Number: " << booking.getWeek().getWeek()  <<
            "Slot Range: " << booking.getSlotRange().getBeginSlot() << " to " << booking.getSlotRange().getEndSlot() << "\n";
            return;
        }
    }
    cout << "No booking found with ID " << qbookingID << ".\n";
}
//--------------------------------------------------------