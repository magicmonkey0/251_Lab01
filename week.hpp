//header file week.hpp to declare your class
#include <iostream>
#include <fstream>
#include <string>

#define TRUE 1
#define FALSE 0
const int maintenanceWeeks[] = {1,13,26,39,52};

using namespace std;

class Week {
    private:
        int week; 
        bool reserved[24]; //bool array for reservations: 0 = false, 1 = true (is reserved)

    public:
        // constructor
        Week(int week, bool reserved[24]);
        Week(); // default constructor (initilizes object when no arguments are provided during creation)
        Week(int week);

        // accessor
        int getReserved(int index) const; // parameter: array index
        int getWeek();

        // mutator
        void setReserved(int index, bool value); // maarks slot index as reserved or free
        void setWeek(int weekNum);

        bool isMaintenance() const; // returns true if it is a maintenance week
        bool isPeak() const;
        bool isValid() const;
        friend bool isWeekEqual(const Week& week1, const Week& week2);
        void printFreeSlots(); 
        void printReservedSlots();
        void printInfo(ostream &outs) const; // prints week num, is maintenance/peak week, status of reservation?

        // since the reserved array is in indices, this function converts indices to slot times
        // returns a string value that is ready to be outputted 
        friend string fromIndexToSlotTime(int index); 

};
