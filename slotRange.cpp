//slotRange.cpp to implement your class
#include "slotRange.hpp"
#include <iostream>

SlotRange::SlotRange() 
{
    beginSlot = 0;
    endSlot = 0;
}

SlotRange::SlotRange(int beginSlot, int endSlot)
{
    this->beginSlot = beginSlot;
    this->endSlot = endSlot;
}

int SlotRange::getBeginSlot() const
{
    return beginSlot;
}

int SlotRange::getEndSlot() const
{
    return endSlot;
}

void SlotRange::setBeginSlot(int beginSlot)
{
    this->beginSlot = beginSlot;
}

void SlotRange::setEndSlot(int endSlot)
{
    this->endSlot = endSlot;
}

string fromIndexToSlotRangeHours(int index)
{
    // validate index
    if (index < 0 || index > 23)
    {
        return "Invalid index (0-23).";
    }

    string slot_time_hours[] = {"midnight", "1AM", "2AM", "3AM", 
                                "4AM", "5AM", "6AM", "7AM", 
                                "8AM", "9AM", "10AM", "11AM", 
                                "12PM", "1PM", "2PM", "3PM", 
                                "4PM", "5PM", "6PM", "7PM", 
                                "8PM", "9PM", "10PM", "11PM"};

    for (int i = 0; i < 24; i++)
    {
        if (index == i)
        {
            return slot_time_hours[i];
        }
    }

    return "ERROR: No valid index was found.\n";
}

void SlotRange::printInfo(ostream &outs) const
{
    outs << "Slot range: " << fromIndexToSlotRangeHours(this->beginSlot) << " to " << fromIndexToSlotRangeHours(this->endSlot) << endl;
    // if (isValid())
    // {
    //     cout << " (valid)" << endl;
    // }
    // else
    // {
    //     cout << " (invalid)" << endl;
    // }
}

/* 
valid checks:
    - check if the user input beginning time and end time are a multiple of 2 hours
        - (endSlot - beginSlot) is a multiple of 2 hours
    - fall within the valid slot range (0 to 23) 
    - endSlot > beginSlot 
*/
bool SlotRange::isValid() const
{
    if (endSlot < beginSlot)
    {
        cout << "ERROR: The slot range is invalid. end slot < begin slot.\n";
        return false;
    }

    if (((endSlot - beginSlot) % 2) != 0)
    {
        cout << "ERROR: The slot range in invalid. The range is not a multiple of 2.\n";
        return false;
    }

    if (beginSlot < 0 || endSlot > 23)
    {
        cout << "ERROR: The slot range is invalid. The begin/end slot is out of bounds (0-23).\n";
        return false;
    }

    // if it passes all checks, then the slot range is valid, so, return true
    cout << "The slot range is valid.\n";
    return true;
}