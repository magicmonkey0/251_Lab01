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
        void setReserved(int index); // setter
        int getReserved(int index); // getter
        bool isMaintenance(int week);
        bool isPeak(int week);
        bool isValid(int week);

};
