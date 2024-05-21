#ifndef DATE_H
#define DATE_H

#include <string>

class Date{
    private:
        int month;
        int year;
        int day;
    public:
        Date();
        Date(int aDay, int aMonth, int aYear);

        // exception declarations
        class InvalidMonth{
            
        };
        class InvalidDay{
            
        };
        class InvalidYear{
            
        };

        int getMonth() const;
        int getYear() const;
        int getDay() const;
        void setMonth(int aMonth);
        void setYear(int aYear);
        void setDay(int aDay);
        std::string toString();
};

#endif