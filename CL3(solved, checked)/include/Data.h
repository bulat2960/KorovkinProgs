#ifndef DATA_H
#define DATA_H
class Data
{
    private:
        int year;
        int month;
        int day;
        int* monthDays;
    public:
        Data(const char*);
        int diff(const Data&);
        inline bool isLeapYear(int);
        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);
        int getDay() const;
        int getMonth() const;
        int getYear() const;
};

#endif
