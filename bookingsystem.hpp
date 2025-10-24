#ifndef BOOKINGSYSTEM_HPP
#define BOOKINGSYSTEM_HPP

#include <vector>
#include "booking.hpp"
#include "week.hpp"
#include "slotRange.hpp"

class BookingSystem {
    public:
    //  allows for the booking functions to be accessed
        std::vector<Booking> bookings;
        Booking reserve_function();
        bool cancel_booking();
        void display_all_bookings() const;
};

#endif // BOOKINGSYSTEM_HPP