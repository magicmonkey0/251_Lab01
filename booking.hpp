#include <iostream>
#include <fstream>
#include <string>

#include "week.hpp"
#include "slotRange.hpp"

using namespace std;

class Booking {

    private:
        int bookingID; // an auto-incrementing unique ID number; starts at 1
        Week week;
        SlotRange range;
        string *customerName;

    public:
        // constructors
        Booking(); // default
        // validate using Week/SlotRange isValid(); assign the ID and next
        Booking(int week, int beginSlot, int endSlot, string customerName[]);

        // accessors (setters) - shoudl re-validate
        int getBookingID() const;
        Week getWeek() const;
        SlotRange getSlotRange() const;
        string getCustomerName() const;

        // mutators (getters)

        // check if this booking overlaps with another (ie. same week and overlapping slots)
        bool isConflicting(const Booking& other);

        // print function using ostreams&


};