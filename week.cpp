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

void Week::setReserved(int index)
{
    // can only reserve if the var index is valid (0 to 23), is not maintence or peak week
    if (index >= 0 && index <=23)
    {
        reserved[index] = TRUE;
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

bool Week::isValid()
{
    if (week < 1 || week > 52)
    {
        return FALSE;
    }

    return TRUE;
}

bool Week::isMaintenance()
{
    for (int i = 0; i < 5; i++)
    {
        if (week == maintenanceWeeks[i])
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

bool Week::isPeak()
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

void Week::printInfo(ostream &out) const
{
    out << "Week: " << week << endl;
}


// this function prints all free slots of the week that haven't been reserved
// print slot times (not array indices)
void Week::printFreeSlots()
{

}

// this function prints all reserved slots of the week
void Week::printReservedSlots()
{

}

