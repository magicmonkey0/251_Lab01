//header file slotRange.hpp to declare your class
class SlotRange {
    private:
        int beginSlot;
        int endSlot;
    public:
        // constructor
        SlotRange(int beginSlot, int endSlot);
        SlotRange();

        // accessor
        int getBeginSlot();
        int getEndSlot();

        // mutator
        void setBeginSlot(int num);
        void setEndSlot(int num);

        void printSlotRangeInfo(int beginSlot, int endSlot);
        /* check if the user input beginning time and end time are a multiple of 2 hours
        (endSlot - beginSlot) is a multiple of 2 hours basically
        fall within the valid slot range (0 to 23) 
        endSlot > beginSlot
        */
        bool isValid(int slotIndex); 
        void printFreeSlots();
        void printReservedSlots();

};
