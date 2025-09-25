//header file week.hpp to declare your class
#include <iostream>
#include <fstream>
#include <string>

const int maintenanceWeeks[] = {1,13,26,39,52};

using namespace std;

class Week {

    // friend functions
    friend bool isWeekEqual(const Week& week1, const Week& week2);
    /* since the reserved array is in indices, this function converts indices to slot times
    returns a string value that is ready to be outputted */
    friend string fromIndexToSlotTime(int index); 


    private:
        int week; 
        bool reserved[24]; //bool array for reservations: 0 = false, 1 = true (is reserved)

    public:
        // constructor
        Week(); // default constructor (initilizes object when no arguments are provided during creation)
        Week(int week);

        // accessor
        int getReserved(int index) const; // parameter: array index
        int getWeek() const;

        // mutator
        void setReserved(int index, bool value); // maarks slot index as reserved or free
        void setWeek(int weekNum);

        bool isMaintenance() const; // returns true if it is a maintenance week
        bool isPeak() const;
        bool isValid() const;
        void printFreeSlots(ostream &outs) const; 
        void printReservedSlots(ostream &outs) const;
        void printInfo(ostream &outs) const; // prints week num, is maintenance/peak week, status of reservation?

};