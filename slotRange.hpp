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
        // constructor
        SlotRange(int beginSlot, int endSlot);
        SlotRange();

        // accessor
        int getBeginSlot() const;
        int getEndSlot() const;

        // mutator
        void setBeginSlot(int beginSlot);
        void setEndSlot(int endSlot);

        void printSlotRangeInfo(ostream &outs) const;
        bool isValid() const;
};
