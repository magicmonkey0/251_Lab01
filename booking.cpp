#include "mbooking.hpp"
#include "SlotRange.hpp"
// wNum is the week number and uniqueB_ID is unique booking id so it can be found later
//  called when the object is created and assigns it a booking id
int Booking::uniqueB_ID = 0;

Booking::Booking() : week(), range(), customerName("No name.") // default constructor
{
    bookingID = nextID++;
}

Booking::Booking(int weekNum, int beginSlot, int endSlot, string customerName) 
    : week(weekNum), range(beginSlot, endSlot), customerName(customerName)
{
    bookingID = nextID++;
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
    if (this->getWeek().getWeek() == other.getWeek().getWeek())
    {
        return true;
    }

    // check for time overlaps
    // overlap: when startA < endB && Bstart < endA
    int startA = this->getSlotRange().getBeginSlot();
    int endA = this->getSlotRange().getEndSlot();
    int startB = other.getSlotRange().getBeginSlot();
    int endB = other.getSlotRange().getEndSlot();
    if ((startA < endB) && (startB < endA))
    {
        cout << "The bookings overlap." << endl;
        return true;
    }

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