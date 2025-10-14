#include <iostream>
#include <string>
#include "booking.hpp"

using namespace std;

int uniqueBookingID = 0;

Booking::Booking() // idk
{
    uniqueBookingID++;
    bookingID = uniqueBookingID;
    // customerName = "No name."; FIXME
    week = Week();
    range = SlotRange();
}

Booking::Booking(int week, int beginSlot, int endSlot, string customerName[])
{
    uniqueBookingID++;
    bookingID = uniqueBookingID;

    this->week = Week(week);
    if (this->week.isValid()){}
    else { return; }

    range = SlotRange(beginSlot, endSlot);
    if (range.isValid()) {}
    else { return; }

    // okay so gonna have to dyn allocate space and use strcpy (?) is this the approach
    this->customerName = new string[sizeof(customerName) + 1];
    // strcpy(this->customerName, customerName[]); FIXME

}

int Booking::getBookingID() const
{
    return bookingID;
}

Week Booking::getWeek() const
{
    return week;
}

SlotRange Booking::getSlotRange() const
{
    return range;
}

