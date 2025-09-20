//week.cpp to implement your class
#include "week.hpp"
#include <iostream>

using namespace std;

Week::Week(int week, bool reserved[24]) // constructor
{
    for (int i = 0; i < sizeof(reserved); i++)
    {
        reserved[i] = FALSE; // all slots are set to FALSE = not reserved
    }

    this->week = week;

}

void Week::setWeek(int num)
{
    week = num;
}

bool Week::isValid()
{
    if (week < 1 || week > 52)
    {
        cout << "ERROR: week " << week << "is not within the valid week range (1-52).";
        return FALSE;
    }

    cout << "Week " << week << "is valid.";
    return TRUE;
}

// bool Week::isMaintenance()
// {
//     for (int i = 0; i < 5; i++)
//     {
//         if (isWeekEqual(week, maintenanceWeeks[i]) == TRUE)
//         {
//             return TRUE; // no reservations allowed
//         }
//     }

//     return FALSE;
// }

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

