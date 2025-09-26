//header file week.hpp to declare your class
#include <iostream>
#include <fstream>
#include <string>

const int maintenanceWeeks[] = {1,13,26,39,52};

using namespace std;

class Week {

    // friend functions
    friend bool isWeekEqual(const Week& week1, const Week& week2);
    friend string fromIndexToSlotTime(int index); 

    private:
        int week; 
        bool reserved[24]; //bool array for reservations: false = free, true = reserved

    public:
        // constructors
        Week(); // default constructor (initilizes object when no arguments are provided during creation)
        Week(int week);

        // accessors
        int getReserved(int index) const; // parameter: array index
        int getWeek() const;

        // mutators
        void setReserved(int index, bool value); // maarks slot index as reserved or free
        void setWeek(int weekNum);

        // other member functions
        bool isMaintenance() const; // returns true if it is a maintenance week
        bool isPeak() const;
        bool isValid() const;
        void printFreeSlots(ostream &outs) const; 
        void printReservedSlots(ostream &outs) const;
        void printInfo(ostream &outs) const; // prints week num, is maintenance/peak week, status of reservation?
};