#include <iostream>
#include <string>
#include "booking.hpp"

using namespace std;

int Booking::nextID = 1;

Booking::Booking() : week(), range(), customerName("No name.") // default constructor
{
    bookingID = nextID;
    nextID++;
}

Booking::Booking(int weekNum, int beginSlot, int endSlot, string customerName) 
{
    week = Week(weekNum);
    range = SlotRange(beginSlot, endSlot);
    this->customerName = customerName;
    bookingID = nextID;
    nextID++;
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

string Booking::getCustomerName() const
{
    return customerName;
}

// setters should revalidate
void Booking::setCustomerName(string customerName)
{
    this->customerName = customerName;
}

void Booking::setWeek(int weekNum)
{
    week = Week(weekNum);
    if (week.isValid()){}
    else { return; }
}

void Booking::setSlotRange(int beginSlot, int endSlot)
{
    range = SlotRange(beginSlot, endSlot);
    if (range.isValid()) {}
    else { return; }
}

// 
void Booking::setBookingID(int val)
{
    bookingID = val;
}

// check if this booking overlaps with another (same week and overlapping slots)
bool Booking::isConflicting(const Booking &other)
{
    if (this->getWeek().getWeek() != other.getWeek().getWeek())
    {
        return false;
    }
    else // if the weeks are equal then check for slot range overlaps
    {
        // overlap: when startA < endB && Bstart < endA
        int startA = this->getSlotRange().getBeginSlot();
        int endA = this->getSlotRange().getEndSlot();
        int startB = other.getSlotRange().getBeginSlot();
        int endB = other.getSlotRange().getEndSlot();
        if ((startA < endB) && (startB < endA))
        {
            cout << "This booking overlaps with another booking (ID: " << other.getBookingID() << ")." << endl;
            return true;
        }
    }

    // otherwise, return false if week IS EQUAL and slots DO NOT OVERLAP = NOT CONFLICTING
    return false;
}

void Booking::printBookingDetails(ostream &outs) const
{
    outs << "Booking ID: " << this->bookingID << endl;
    outs << "Week: " << this->getWeek().getWeek() << endl;
    // print slots with times
    this->getSlotRange().printInfo(outs);
    outs << "Customer name: " << this->customerName << endl;
}