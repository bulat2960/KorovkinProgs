#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class Time
{
    private:
        unsigned year1, year2;
        unsigned month1, month2;
        unsigned day1, day2;
    public:
        Time(string data1, string data2)
        {
            day1 = atoi(data1.substr(0, 2).c_str());
            month1 = atoi(data1.substr(4, 2).c_str());
            year1 = atoi(data1.substr(6, 4).c_str());

            day2 = atoi(data2.substr(0, 2).c_str());
            month2 = atoi(data2.substr(4, 2).c_str());
            year2 = atoi(data2.substr(6, 4).c_str());
        }

        int getDiff()
        {
            int diffYear, diffMonth, diffDay;

            diffYear = year1 - year2;
            if (diffYear > 0)
            {
                diffMonth = month1 - month2;
                diffDay = day1 - day2;
            }
            else
            {
                diffMonth = month2 - month1;
                diffDay = day2 - day1;
            }
            if (diffMonth < 0)
            {
                diffYear--;
                diffMonth += 12;
            }
            if (diffDay < 0)
            {
                diffMonth--;
                diffDay += 30;
            }

            int data = diffDay + 30 * diffMonth + 365 * diffYear;
            return data;
        }
};

int main()
{
    Time time("09.04.2016", "07.03.2017");
    int data = time.getDiff();
    cout << data;
    return 0;
}
