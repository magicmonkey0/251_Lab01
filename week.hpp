//header file week.hpp to declare your class
class Week {
    private:
        int week; 
        bool reserved[24]; //bool array for reservations: 0 = false, 1 = true (is reserved)

    public:
        Week::Week(int week, bool reserved[24])
        {
            // initialize reserved array to false values
            for (int i =0; i<sizeof(reserved); i++)
            {
                reserved[i] = 0;
            }
        }

        // setter
        void setReserved(int index)
        {
            // idk
        }

        // getter
        int getReserved(int index)
        {
            return reserved[index];
        }


};
