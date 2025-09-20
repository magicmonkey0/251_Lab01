//header file slotRange.hpp to declare your class
class SlotRange {
    private:
        int beginSlot;
        int endSlot;
    public:
        SlotRange(int beginSlot, int endSlot);
        int getReserved(int slotIndex);
        void setReserved(int slotIndex, bool reserve);
        void printSlotRangeInfo(int beginSlot, int endSlot);
        bool isValid(int slotIndex); // check if the user input beginning time and end time are a multiple of 2 hours nd fall within the valid slot range (0 to 23) 
        void printFreeSlots();
        void printReservedSlots();
};
