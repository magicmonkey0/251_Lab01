//header file week.hpp to declare your class

#define TRUE 1
#define FALSE 0
const int maintenanceWeeks[] = {1,13,26,39,52};


class Week {
    private:
        int week; 
        bool reserved[24]; //bool array for reservations: 0 = false, 1 = true (is reserved)

    public:
        // function declarations
        Week(int week, bool reserved[24]);
        void setWeek(int num); // setter
        int getWeek(int index); // getter idk
        bool isMaintenance();
        bool isPeak();
        bool isValid();
        friend bool isWeekEqual(const Week& week1, int week2);
        void printInfo();

};
