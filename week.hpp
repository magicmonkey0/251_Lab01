//header file week.hpp to declare your class
#include <iostream>
#include <fstream>

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

        // accessor
        int getReserved(int index) const; // parameter: array index
        int getWeek();

        // mutator
        void setReserved(int index); 
        void setWeek(int weekNum);

        bool isMaintenance();
        bool isPeak();
        bool isValid();
        friend bool isWeekEqual(const Week& week1, const Week& week2);
        void printFreeSlots(); 
        void printReservedSlots();
        void printInfo(ostream &out) const; 

};
