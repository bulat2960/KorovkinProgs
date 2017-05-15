#include "Data.h"

Data::Data(const char* str)
{
    monthDays = new int[12]; // Дни во всех месяцах
    monthDays[0] = 31; monthDays[1] = 28; monthDays[2] = 31; monthDays[3] = 30; monthDays[4] = 31; monthDays[5] = 30;
	monthDays[6] = 31; monthDays[7] = 31; monthDays[8] = 30; monthDays[9] = 31; monthDays[10] = 30; monthDays[11] = 31;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // Проверка года на високосность
    {
        monthDays[1] = 29;
    }

	int i = 0; // Счетчик строки
	int k = 0; // Переменная состояния - содержит информацию о том, какие данные считавыаются сейчас(день, месяц или год)
	while (str[i] != '\0') // Читаем пока не конец строки
	{
	    // static_cast<T>(anything), используемый ниже - то же самое, что и (T)(anything), обычное приведение типов
		if (str[i] == ' ') // Если пробел - переходим на следующий символ и меняем состояние
        {
            i++;
            k++;
        }
		if (k == 0) // Читаем день
		{
			day = static_cast<int>(str[i] - '0') * 10 + static_cast<int>(str[i + 1] - '0');
			i = i + 2;
		}
		if (k == 1) // Читаем месяц
		{
			month = static_cast<int>(str[i] - '0') * 10 + static_cast<int>(str[i + 1] - '0');
			i = i + 2;
		}
		if (k == 2) // Читаем год
		{
			year = static_cast<int>(str[i] - '0') * 1000 + static_cast<int>(str[i + 1] - '0') * 100
                 + static_cast<int>(str[i + 2] - '0') * 10 + static_cast<int>(str[i + 3] - '0');
			i = i + 4;
			break;
		}
	}
}

inline bool Data::isLeapYear(int _year) // Проверка года на високосность
{
    return (_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0 ? true : false;
}

int Data::diff(const Data& data) // Вычисление разницы между датами
{
    int result = 0;
    int temp = 0;

    if (year < data.year) // Если первый год меньше второго
    {
        temp = year;
        while (temp < data.year) // Прибавляем дни до тех пор, пока первый год не станет равным второму
        {
            isLeapYear(temp) ? result += 366 : result += 365;
            temp++;
        }
    }
    else // Если первый год больше второго
    {
        temp = data.year;
        while (temp < year) // Аналогично, только для второго года
        {
            isLeapYear(temp) ? result += 366 : result += 365;
            temp++;
        }
    }

    if (month < data.month) // Если первый месяц меньше второго
	{
		temp = month;
		while (temp < data.month) // Прибавляем дни из списка дней в месяцах года
		{
			result += monthDays[temp - 1];
			temp++;
		}
	}
	else // Если первый больше второго
	{
		temp = data.month;
		while (temp < month) // Аналогично, только для второго месяца
		{
			result += monthDays[temp - 1];
			temp++;
		}
	}

	if (day > data.day) // Примерно похожие действия с днями
	{
		result -= day - data.day;
	}
	else
	{
		result += data.day - day;
	}
    return result;
}

void Data::operator++() // Префиксный инкремент
{
	if (day + 1 > monthDays[month - 1]) // Если пересекаем границу месяца
	{
	    day = 1;
		if (month == 12) // Если пересекаем границу года
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

void Data::operator++(int) // Абсолютно одинаковый с префиксным
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

void Data::operator--() // Префискный декремент
{
	if (day == 1) // Если пересекаем границу месяца
	{
	    day = monthDays[month - 1];
		if (month == 1) // Если пересекаем границу года
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

void Data::operator--(int) // Абсолютно одинаковый с префиксным
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
