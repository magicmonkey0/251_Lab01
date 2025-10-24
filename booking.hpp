#ifndef BOOKING_HPP
#define BOOKING_HPP
#include <fstream>
#include <string>
#include <vector>
#include "Week.hpp"
#include "SlotRange.hpp"

class Booking
{
private:
    /*static int keeps track of how many bookings are made (internal counter) and that they get unique ids
    week week is the object represented when the booking occursslot where range range object for the range of the booking


    */
    static int uniqueB_ID;
    int bookingID;
    Week week;
    SlotRange range;
    std::string customerName;
    std::vector<Booking> bookings;
    

public:
    //  default constructor followed by parameterized one
    Booking();
    Booking(int wNum, int beginSlot, int endSlot, const std::string &name);

    int Booking::num_of_bookings = 0;

    // Accessors: grabs the id# costomer name or range of the booking
    int getBookingID() const;
    std::string getCustomerName() const;
    SlotRange getSlotRange() const;
    Week getWeek() const;

    // Mutators:   allows for the name week and range to be set to the id# of the booking
    void setCustomerName(const std::string &name);
    void setWeek(int wNum);
    void setSlotRange(int beginSlot, int endSlot);

    
    // Functions used in main.cpp for booking management
    bool remove_booking(vector<Booking> &bookings, int bookingID);
    bool conflicts_with(const Booking &other) const;
};

#endif