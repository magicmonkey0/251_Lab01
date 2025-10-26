#ifndef SLOTRANGE_HPP
#define SLOTRANGE_HPP

//header file slotRange.hpp to declare your class
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SlotRange {

    friend string fromIndexToSlotRangeHours(int index);

    private:
        int beginSlot;
        int endSlot;
    public:
        // constructors
        SlotRange(int beginSlot, int endSlot);
        SlotRange();

        // accessors
        int getBeginSlot() const;
        int getEndSlot() const;

        // mutators
        void setBeginSlot(int beginSlot);
        void setEndSlot(int endSlot);

        // other member functions
        void printInfo(ostream &outs) const;
        bool isValid() const;
};

#endif