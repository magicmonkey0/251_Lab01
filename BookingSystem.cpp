#include <iostream>

#include "BookingSystem.hpp"

using namespace std;


BookingSystem::BookingSystem()
{
    bookingCount = 0;
    for (int i = 0; i < 52; i++)
    {
        weeks[i] = Week(i + 1);
    }
}

Week BookingSystem::getWeek(int weekNum) const 
{
    return weeks[weekNum - 1];
}

int BookingSystem::getBookingCount() const
{
    return bookingCount;
}

bool BookingSystem::canReserve(int weekNum, SlotRange range)
{
    Booking bookingTemp = Booking(weekNum, range.getBeginSlot(), range.getEndSlot(), "No name.");

    if (weekNum < 1 || weekNum > 52)
    {
        cout << "Invalid week number (1-52)." << endl;
        return false;
    }
    else if (weeks[weekNum - 1].isPeak() || weeks[weekNum - 1].isMaintenance())
    {
        cout << "The week is a peak/maintenance week and cannot be reserved." << endl;
        return false;
    }
    else if (!range.isValid())
    {
        return false;
    }

    for (int i = 0; i < bookingCount; i++)
    {
        if (bookingTemp.isConflicting(bookings[i]))
        {
            cout << "There is a conflicting booking." << endl;
            return false;
        }
    }

    // if all checks pass then the booking can be reserved
    return true;
}

int BookingSystem::addBooking(int weekNum, SlotRange range, string customerName)
{

    if (bookingCount >= 200)
    {
        return -1;
    }
    else if (!canReserve(weekNum, range))
    {
        return -2;
    }

    // check for and reuse cancelled index
    for (int i = 0; i < bookingCount; i++)
    {
        if (bookings[i].getBookingID() == -1)
        {
            Booking newBooking = Booking(weekNum, range.getBeginSlot(), range.getEndSlot(), customerName);
            bookings[i] = newBooking;
            bookingCount++;

            // mark the slots as reserved in the Week object
            weeks[weekNum - 1].markReserved(range, true);
            return newBooking.getBookingID();
        }
    }

    // is canReserve returns true, a booking can be made --> create booking
    Booking newBooking = Booking(weekNum, range.getBeginSlot(), range.getEndSlot(), customerName);
    bookings[bookingCount] = newBooking;
    bookingCount++;

    // mark the slots as reserved in the Week object
    weeks[weekNum - 1].markReserved(range, true);

    return newBooking.getBookingID();
}

bool BookingSystem::queryBooking(int bookingID)
{

    for (int i = 0; i < bookingCount; i++)
    {
        if (bookingID == bookings[i].getBookingID())
        {
            cout << "====================\n";
            cout << "Booking found. Here is the booking information: " << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "Booking ID: " << bookingID << endl;
            cout << "Customer Name: " << bookings[i].getCustomerName() << endl;
            // change to actual slot time
            bookings[i].getSlotRange().printInfo(cout);
            cout << "Week: " << bookings[i].getWeek().getWeek();
            cout << "\n====================\n";
            
            return true;
        }
    }

    cout << "There are not bookings found for: " << bookingID << endl << endl;;
    return false;
}

// find booking in array, mark as inactive (set bookingID to -1), unmark reserved in Week (set to false)
// return true on successa and print confirmation/error
bool BookingSystem::cancelBooking(int bookingID)
{
    for (int i = 0; i < bookingCount; i++)
    {
        if (bookingID == bookings[i].getBookingID())
        {
            bookings[i].setBookingID(-1);
            bookings[i].getWeek().markReserved(bookings[i].getSlotRange(), false);
            bookingCount--;

            cout << "Booking for " << bookingID << " has succesfully been cancelled." << endl;
            return true;
        }
    }

    cout << "Booking for " << bookingID << " was not found." << endl;
    return false;
}
 
// print the free/reserved slots for the specified week
void BookingSystem::checkWeek(int weekNum)
{
    if (weekNum < 1 || weekNum > 52)
    {
        cout << "Invalid week number (1-52)." << endl;
        return;
    }

    // print free slots
    weeks[weekNum - 1].printFreeSlots(cout);

    // print reserved slots
    weeks[weekNum - 1].printReservedSlots(cout);
}