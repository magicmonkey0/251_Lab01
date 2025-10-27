#ifndef BOOKING_SYSTEM_HPP
#define BOOKING_SYSTEM_HPP

#include <iostream>
#include <string>

#include "booking.hpp"

using namespace std;

class BookingSystem
{
    private:
        Booking bookings[200];
        int bookingCount; // to track number of bookings
        Week weeks[52]; // initializes to false; set maintenance weeks

    public:
        BookingSystem();

        Week getWeek(int weekNum) const;
        int getBookingCount() const;

        // validate week/range; check not maintenance/peak; scan bookings array for conflicts in that week; check reserved slots are free
        bool canReserve(int weekNum, SlotRange range); 
        // if canReserve is true: create Booking, add to bookings array, incredment bookingCount
        // mark reserved[] trie in the Week
        // return bookingID or -1 on failure and print error message
        // if array is full (bookingCount >= 200) return -1 and print error message
        int addBooking(int weekNum, SlotRange range, string customerName);
        // find and print the Booking details in the bookings array; return true if found
        bool queryBooking(int bookingID);
        // find Booking in array, mark as inactive (set BookingId to -1 or use a flag)
        // unmark reserved[] in Week
        // return true on success (print confirmation/error message)
        bool cancelBooking(int bookingID);
        // print the free/reserved slots for the specified week
        void checkWeek(int weekNum);
};

#endif