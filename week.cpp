//week.cpp to implement your class
#include "week.hpp"
#include <iostream>

using namespace std;

Week::Week(int week, bool reserved[24]) // constructor
{
    for (int i = 0; i < sizeof(reserved); i++)
    {
        reserved[i] = FALSE;
    }
}

int Week::getReserved(int index)
{
    return reserved[index];
}

bool Week::isValid(int week)
{
    if (week < 1 || week > 52)
    {
        cout << "ERROR: week " << week << "is not within the valid week range (1-52).";
        return FALSE;
    }
}