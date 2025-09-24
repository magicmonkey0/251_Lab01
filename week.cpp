//week.cpp to implement your class
#include "week.hpp"
#include <iostream>

using namespace std;

Week::Week()
{
    week = 0;
    for (int i = 0; i < 24; i++)
    {
        reserved[i] = FALSE; // all slots are set to FALSE = not reserved
    }
}

Week::Week(int week, bool reserved[24]) // constructor
{
    for (int i = 0; i < 24; i++)
    {
        reserved[i] = FALSE; // all slots are set to FALSE = not reserved
    }

    this->week = week;

}

Week::Week(int week)
{
    this->week = week;
}

void Week::setReserved(int index, bool value)
{
    // can only reserve if the var index is valid (0 to 23), is not maintence or peak week
    if (index >= 0 && index <=23) // also check bool value?
    {
        reserved[index] = value; 
    }
    else
    {
        throw runtime_error("Reserve index out of bounds (must be 0 to 23).");
    }
}

int Week::getReserved(int index) const
{
    return reserved[index];
}

int Week::getWeek()
{
    return week;
}

void Week::setWeek(int weekNum)
{
    week = weekNum;
}

bool Week::isValid() const
{
    if (week < 1 || week > 52)
    {
        cout << "ERROR: week " << this->week << "is not within the valid week range (1-52).";
        return FALSE;
    }

    cout << "This week is a valid week number.";
    return TRUE;
}

bool Week::isMaintenance() const
{
    for (int i = 0; i < 5; i++)
    {
        Week maintenance_week(maintenanceWeeks[i]); // create an instance of the m week
        if (isWeekEqual(*this, maintenance_week))
        {
            return TRUE; // no reservations allowed
        }
    }

    return FALSE;
}

// function compares two Week objects to check whether the two weeks are the same based on the week number
bool isWeekEqual(const Week& week1, const Week& week2) // i dont understand how to use this for isMaintenance
{
    return (week1.week == week2.week);
}

bool Week::isPeak() const
{
    int peakWeeks[] = {10,20,30,40,50};
    for (int i = 0; i < 5; i++)
    {
        if (week == peakWeeks[i])
        {
            return TRUE; // no reservations allowed
        }
    }

    return FALSE;
}

void Week::printInfo(ostream &outs) const
{
    outs << "Week: " << this->week << endl;
    if (!isValid()) {
        outs << "ERROR: Invalid week.";
        return;
    }
    if (isMaintenance()) 
    {
        outs << " - this is a maintenance week. (no reservations allowed)\n"; 
    }
    if (isPeak())
    {
        outs << " - this is a peak week. (no reservations allowed)\n";
    }
    else
    {
        outs << " - this is a regular week. (reservations are allowed)\n";
    }

}

string fromIndexToSlotTime(int index)
{
    string slot_times_str[] = {"12AM to 1AM", "1AM to 2AM", "2AM to 3AM", "4AM to 5AM", 
                                "5AM to 6AM", "6AM to 7AM", "7AM to 8AM", "8AM to 9AM", 
                                "9AM to 10AM", "10AM to 11AM", "11AM to 12PM", "12PM to 1PM", 
                                "1PM to 2PM", "2PM to 3PM", "3PM to 4PM", "4PM to 5PM", 
                                "5PM to 6PM", "6PM to 7PM", "7PM to 8PM", "8PM to 9PM", 
                                "9PM to 10PM", "10PM to 11PM", "11PM to midnight"};
    for (int i = 0; i < 24; i++)
    {
        if (index == i)
        {
            return slot_times_str[i];
        }
    }
}

// this function prints all free slots of the week that haven't been reserved
// print slot times (not array indices)
void Week::printFreeSlots()
{
    string slot_time_str;

    cout << "Here are the following free slot times: \n";
    for (int i = 0; i < 24; i++)
    {
        if (this->reserved[i] == FALSE)
        {
            slot_time_str = fromIndexToSlotTime(i);
            cout << "Slot " << i << ": " << slot_time_str << endl;
        }
    }
}

// this function prints all reserved slots of the week
void Week::printReservedSlots()
{
    string slot_time_str;
    cout << "Here are the following reserved slot times: \n";
    for (int i = 0; i < 24; i++)
    {
        if (this->reserved[i] == TRUE)
        {
            slot_time_str = fromIndexToSlotTime(i);
            cout << "Slot " << i << ": " << slot_time_str << endl;
        }
    }
}