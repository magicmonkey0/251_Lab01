//week.cpp to implement your class
#include "week.hpp"
#include <iostream>

using namespace std;

Week::Week()
{
    week = 1;
    for (int i = 0; i < SLOTS_ARRAY_SIZE; i++)
    {   
        reserved[i] = false; // all slots are set to FALSE = not reserved
    }
}

Week::Week(int week)
{
    this->week = week;
    for (int i = 0; i < SLOTS_ARRAY_SIZE; i++)
    {
        reserved[i] = false;
    }
}

void Week::setReserved(int index, bool value)
{
    // cannot reserve if the week is a maintenance or peak week
    if (isMaintenance())
    {
        cout << "Week " << this->week << " is a maintenance week and cannot be reserved. Slot " << index << " was not reserved.\n";
        return;
    }
    else if (isPeak())
    {
        cout << "Week " << this->week << "is a peak week and cannot be reserved. Slot " << index << " was not reserved.\n";
        return;
    }

    // index check: cannot reserve if the index is out of range (from 0 - 23)
    if (index >= 0 && index <=23) // also check bool value?
    {
        reserved[index] = value; 
    }
    else
    {
        cout << "Reserve index out of bounds (must be 0 to 23).";
    }
}

int Week::getReserved(int index) const
{
    return reserved[index];
}

int Week::getWeek() const
{
    return week;
}

void Week::setWeek(int weekNum)
{
    week = weekNum;
}

// this function checks if the week is  valid (from 1 to 52)
bool Week::isValid() const
{
    if (this->week < 1 || this->week > 52)
    {
        cout << "ERROR: week " << this->week << " is not within the valid week range (1-52).\n";
        return false;
    }

    cout << "This week is a valid week number.\n";
    return true;
}

// checks if the week is a maintenance week (weeks 1, 13, 26, 39, 52)
bool Week::isMaintenance() const
{
    for (int i = 0; i < NUM_MAINTENANCE_WEEKS; i++)
    {
        Week maintenance_week(maintenanceWeeks[i]); // create an instance of the m week
        if (isWeekEqual(*this, maintenance_week))
        {
            return true; // no reservations allowed
        }
    }

    return false;
}

// function compares two Week objects to check whether the two weeks are the same based on the week number
bool isWeekEqual(const Week& week1, const Week& week2)
{
    return (week1.week == week2.week);
}

// checks if the week is a peak week (weeks 10, 20, 30, 40, 50)
bool Week::isPeak() const
{
    for (int i = 0; i < NUM_PEAK_WEEKS; i++)
    {
        if (week == peakWeeks[i])
        {
            return true; // no reservations allowed
        }
    }

    return false;
}

// prints output to a given output stream.
// prints info such as week number, if it is a maintenance and/or peak week
void Week::printInfo(ostream &outs) const
{
    outs << "Week " << this->week << ": ";
    if (isMaintenance()) 
    {
        outs << "Maintenance week (no reservations allowed)\n"; 
        return;
    }
    
    if (isPeak())
    {
        outs << "Peak week (no reservations allowed)\n";
        return;
    }

    if (!(isValid()))
    {
        return;
    }

    outs << "Regular week. (reservations are allowed)\n";

    // test: print the reserved array
    outs << "Reserved array: [ ";
    for (int i = 0; i < SLOTS_ARRAY_SIZE; i++)
    {
        outs << reserved[i] << " ";
    }
    outs << "]" << endl;
}

/* 
since slot times should be printed in readable format, this is a friend function that converts
slot time indices into its string format.
so, slot 0 is from midnight to 1AM, slot 1 is from 1Am to 2AM, and so on.
*/
string fromIndexToSlotTime(int index)
{
    string slot_times_str[] = {"midnight to 1AM", "1AM to 2AM", "2AM to 3AM", "4AM to 5AM", 
                                "5AM to 6AM", "6AM to 7AM", "7AM to 8AM", "8AM to 9AM", 
                                "9AM to 10AM", "10AM to 11AM", "11AM to 12PM", "12PM to 1PM", 
                                "1PM to 2PM", "2PM to 3PM", "3PM to 4PM", "4PM to 5PM", 
                                "5PM to 6PM", "6PM to 7PM", "7PM to 8PM", "8PM to 9PM", 
                                "9PM to 10PM", "10PM to 11PM", "11PM to midnight"};
    for (int i = 0; i < SLOTS_ARRAY_SIZE; i++)
    {
        if (index == i)
        {
            return slot_times_str[i];
        }
    }

    return "ERROR: No valid index was found.";
}

// this function prints all free slots of the week that haven't been reserved
// print slot times (not array indices)
void Week::printFreeSlots(ostream &outs) const
{
    string slot_time_str;

    outs << "\nHere are the following free slot times: \n";
    for (int i = 0; i < SLOTS_ARRAY_SIZE; i++)
    {
        if (this->reserved[i] == false)
        {
            slot_time_str = fromIndexToSlotTime(i);
            outs << "   - Slot " << i << ": " << slot_time_str << endl;
        }
    }
}

// this function prints all reserved slots of the week
void Week::printReservedSlots(ostream &outs) const
{
    string slot_time_str;
    int counter = 0; // this counter is to check if the reserve array is all false
    outs << "\nHere are the following reserved slot times: \n";

    for (int i = 0; i < SLOTS_ARRAY_SIZE; i++)
    {
        if (this->reserved[i] == true)
        {
            slot_time_str = fromIndexToSlotTime(i);
            outs << "   - Slot " << i << ": " << slot_time_str << endl;
            counter++;
        }
    }

    // if counter = 0 still, meaning no reserved slots, print the following message
    if (counter == 0)
    {
        outs << "There are no reservations.\n";
    }

}

// will set all slots in the range to a given status; used in add/cancel bookings
void Week::markReserved(SlotRange range, bool status)
{
    for (int i = range.getBeginSlot(); i < range.getEndSlot(); i++)
    {
        reserved[i] = status;
    }
}