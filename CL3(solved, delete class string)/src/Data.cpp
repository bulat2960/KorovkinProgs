#include "Data.h"

Data::Data(const char* str)
{
    monthDays = new int[12];
    monthDays[0] = 31; monthDays[1] = 28; monthDays[2] = 31; monthDays[3] = 30; monthDays[4] = 31; monthDays[5] = 30;
	monthDays[6] = 31; monthDays[7] = 31; monthDays[8] = 30; monthDays[9] = 31; monthDays[10] = 30; monthDays[11] = 31;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        monthDays[1] = 29;
    }

	int i = 0;
	int k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
        {
            i++;
            k++;
        }
		if (k == 0)
		{
			day = static_cast<int>(str[i] - '0') * 10 + static_cast<int>(str[i + 1] - '0');
			i = i + 2;
		}
		if (k == 1)
		{
			month = static_cast<int>(str[i] - '0') * 10 + static_cast<int>(str[i + 1] - '0');
			i = i + 2;
		}
		if (k == 2)
		{
			year = static_cast<int>(str[i] - '0') * 1000 + static_cast<int>(str[i + 1] - '0') * 100
                 + static_cast<int>(str[i + 2] - '0') * 10 + static_cast<int>(str[i + 3] - '0');
			i = i + 4;
			break;
		}
	}
}

inline bool Data::isLeapYear(int _year)
{
    return (_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0 ? true : false;
}

int Data::diff(const Data& data)
{
    int result = 0;
    int temp = 0;

    if (year < data.year)
    {
        temp = year;
        while (temp < data.year)
        {
            isLeapYear(temp) ? result += 366 : result += 365;
            temp++;
        }
    }
    else
    {
        temp = data.year;
        while (temp < year)
        {
            isLeapYear(temp) ? result += 366 : result += 365;
            temp++;
        }
    }

    if (month < data.month)
	{
		temp = month;
		while (temp < data.month)
		{
			result += monthDays[temp - 1];
			temp++;
		}
	}
	else
	{
		temp = data.month;
		while (temp < month)
		{
			result += monthDays[temp - 1];
			temp++;
		}
	}

	if (day > data.day)
	{
		result -= day - data.day;
	}
	else
	{
		result += data.day - day;			//прибавляем разницу в днях
	}
    return result;
}

void Data::operator++()
{
	if (day + 1 > monthDays[month - 1])
	{
	    day = 1;
		if (month == 12)
		{
			month = 1;
			year++;
			if (isLeapYear(year))
            {
                monthDays[1] = 29;
            }
		}
		else
        {
            month++;
        }
	}
	else
    {
        day++;
    }
}

void Data::operator++(int)
{
	if (day + 1 > monthDays[month - 1])
	{
	    day = 1;
		if (month == 12)
		{
			month = 1;
			year++;
			isLeapYear(year) ? monthDays[1] = 29 : monthDays[1] = 28;
		}
		else
        {
            month++;
        }
	}
	else
    {
        day++;
    }
}

void Data::operator--()
{
	if (day == 1)
	{
	    day = monthDays[month - 1];
		if (month == 1)
		{
			month = 12;
			year--;
			isLeapYear(year) ? monthDays[1] = 29 : monthDays[1] = 28;
		}
		else
        {
            month--;
        }
	}
	else
    {
        day--;
    }
}

void Data::operator--(int)
{
	if (day == 1)
	{
	    day = monthDays[month - 1];
		if (month == 1)
		{
			month = 12;
			year--;
			isLeapYear(year) ? monthDays[1] = 29 : monthDays[1] = 28;
		}
		else
        {
            month--;
        }
	}
	else
    {
        day--;
    }
}

int Data::getDay() const
{
	return day;
}

int Data::getMonth() const
{
	return month;
}

int Data::getYear() const
{
	return year;
}
