#ifndef WEEK_HPP
#define WEEK_HPP

//header file week.hpp to declare your class
#include <iostream>
#include <fstream>
#include <string>

#include "slotRange.hpp"

// macros for more clean index requirements
#define SLOTS_ARRAY_SIZE 24
#define NUM_MAINTENANCE_WEEKS 5
#define NUM_PEAK_WEEKS 5

// global const defined int array for the maintenance and peak weeks
const int maintenanceWeeks[] = {1,13,26,39,52};
const int peakWeeks[] = {10,20,30,40,50};

using namespace std;

class Week {

    // friend functions
    friend bool isWeekEqual(const Week& week1, const Week& week2);

    private:
        int week; 
        bool reserved[24]; //bool array for reservations: false = free, true = reserved

    public:
        // constructors
        Week(); // default constructor (initilizes object when no arguments are provided during creation)
        Week(int week);
        // Week(int week, bool reserved[24]); maybe not add? need to check week and reservations

        // accessors
        int getReserved(int index) const; // parameter: array index
        int getWeek() const;

        // mutators
        void setReserved(int index, bool value); // marks slot index as reserved or free
        void setWeek(int weekNum);

        // other member functions
        bool isMaintenance() const; // returns true if it is a maintenance week
        bool isPeak() const;
        bool isValid() const;
        void printFreeSlots(ostream &outs) const; 
        void printReservedSlots(ostream &outs) const;
        void printInfo(ostream &outs) const; // prints week num, is maintenance/peak week, status of reservation?

        // set/unset multiple reserved slots at once used in add/cancel
        void markReserved(SlotRange range, bool status);

        // converts slot time to actual time slots
        string fromIndexToSlotTime(int index) const;

};

#endif