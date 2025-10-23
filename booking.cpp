#include "mbooking.hpp"
#include "SlotRange.hpp"
// wNum is the week number and uniqueB_ID is unique booking id so it can be found later
//  called when the object is created and assigns it a booking id
int Booking::uniqueB_ID = 0;

Booking::Booking() : week(), range(), customerName("No name.")
{
    bookingID = ++uniqueB_ID;
    ++num_of_bookings;
}
// initializes the week slot range and costomer name members
Booking::Booking(int wNum, int beginSlot, int endSlot, const std::string &name)
    : week(wNum), range(beginSlot, endSlot), customerName(name)
{
    bookingID = ++uniqueB_ID;
}

int Booking::getBookingID() const {
     return bookingID; 
    }
std::string Booking::getCustomerName() const {
     return customerName; 
    }
Week Booking::getWeek() const {
     return week;
    }
SlotRange Booking::getSlotRange() const {
     return range;
    }

void Booking::setCustomerName(const std::string &name) {
     customerName = name; 
    }
void Booking::setWeek(int wNum) {
     week = Week(wNum);
    }
void Booking::setSlotRange(int beginSlot, int endSlot) {
    range = SlotRange(beginSlot, endSlot);
}


// checks if two bookings conflict first by week then by time slot
bool Booking::conflicts_with(const Booking &other) const
{
    if (week.getWeek() != other.week.getWeek())
    {

        return false;
        // for different weeks that dont conflict
    }

    int start_w_1 = range.getBeginSlot();
    int end_w_1 = range.getEndSlot();
    int start_w_2 = other.range.getBeginSlot();
    int end_w_2 = other.range.getEndSlot();
    
    if (week.getWeek() == other.week.getWeek())
    {
    if (end_w_1 < start_w_2 || end_w_2 < start_w_1)
        return false;
        // for same week where the time slot doesnt conflict
        
    }

    else
    {
        return true;
        // any other scenario the times conflict
    }
}

//Remove booking function to delete a booking based on its ID
bool Booking::remove_booking(std::vector<Booking>& bookings, int bookingID)
{
    for (auto it = bookings.begin(); it != bookings.end(); ++it)
    {
        if (it->getBookingID() == bookingID)
        {
            bookings.erase(it);
            return true;
        }
    }
    return false;
}