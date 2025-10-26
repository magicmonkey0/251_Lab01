#ifndef BOOKING_HPP
#define BOOKING_HPP

#include <iostream>
#include <fstream>
#include <string>

#include "week.hpp"

using namespace std;

class Booking {

    private:
        int bookingID; // an auto-incrementing unique ID number; starts at 1
        static int nextID;
        Week week;
        SlotRange range;
        string customerName;

    public:
        // constructors
        Booking(); // default
        // validate using Week/SlotRange isValid(); assign the ID and next
        Booking(int weekNum, int beginSlot, int endSlot, string customerName);

        // accessors (setters) - shoudl re-validate
        int getBookingID() const;
        Week getWeek() const;
        SlotRange getSlotRange() const;
        string getCustomerName() const;

        // mutators (getters)
        void setCustomerName(string customerName);
        void setWeek(int weekNum);
        void setSlotRange(int beginSlot, int endSlot);
        void setBookingID(int val);

        // check if this booking overlaps with another (ie. same week and overlapping slots)
        bool isConflicting(const Booking &other);

        // print function using ostreams&  
        // print ID, week, slots with times, and customer name
        void printBookingDetails(ostream &outs) const;
};

#endif