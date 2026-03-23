#include "date.h"
#include <iostream>
#include <ctime>
//#define _CRT_SECURE_NO_WARNINGS

//'localtime': This function or variable may be unsafe.Consider using localtime_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details. 

void Date::setDefaultDate()
{
    time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t);  
    day = now.tm_mday;
    month = now.tm_mon + 1;
    year = now.tm_year + 1900;
}
bool Date::isValidDate(int d, int m, int y) const
{
	if (y < 1900 || m < 1 || m>12 || d < 1 || d>31) return false;

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) daysInMonth[1] = 29;
	return d <= daysInMonth[m - 1];
}

Date::Date()
{
	setDefaultDate();
}


Date::Date(int d, int m, int y)
{
	if (isValidDate(d, m, y))
	{
		day = d;
		month = m;
		year = y;
	}
	else
	{
		std::cout << "Invalid date provided. Setting to default date.\n";
		setDefaultDate();
	}
}

Date::Date(const std::string& dateStr)
{
    int d = 0, m = 0, y = 0;
    int dotCount = 0;
    bool validFormat = true;

    try
    {
        size_t start = 0;
        int partIndex = 0;

        for (size_t i = 0; i <= dateStr.length(); i++)
        {
            if (i == dateStr.length() || dateStr[i] == '.')
            {
                if (i > start)
                {
                    std::string numStr = dateStr.substr(start, i - start);

                
                    if (numStr.empty())
                    {
                        throw std::invalid_argument("Empty part");
                    }

                    int value = 0;
                    for (char c : numStr)
                    {
                        if (c < '0' || c > '9')
                        {
                            throw std::invalid_argument("Non-digit character");
                        }
                        value = value * 10 + (c - '0');
                    }

                    if (partIndex == 0) d = value;
                    else if (partIndex == 1) m = value;
                    else if (partIndex == 2) y = value;
                    else
                    {
                        throw std::invalid_argument("Too many parts");
                    }
                    partIndex++;
                }
                start = i + 1;
                if (i < dateStr.length()) dotCount++;
            }
        }

    
        if (dotCount != 2 || partIndex != 3)
        {
            throw std::invalid_argument("Invalid format (need DD.MM.YYYY)");
        }

        
        if (!isValidDate(d, m, y))
        {
            throw std::invalid_argument("Invalid date values");
        }

        day = d;
        month = m;
        year = y;
    }
    catch (const std::exception& e)
    {
        
        setDefaultDate();
    }
}

void Date::setDay(int d)
{
    if (isValidDate(d, month, year)) day = d;
    else std::cout << "Invalid day. No changes made.\n";
}

void Date::setMonth(int m)
{
    if (isValidDate(day, m, year)) month = m;
    else std::cout << "Invalid month. No changes made.\n";
}

void Date::setYear(int y)
{
    if (isValidDate(day, month, y)) year = y;
    else std::cout << "Invalid year. No changes made.\n";
}

void Date::printDate() const
{
    std::cout << (day < 10 ? "0" : "") << day << "."
        << (month < 10 ? "0" : "") << month << "."
        << year << std::endl;
}
