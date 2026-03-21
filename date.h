#pragma once
#include <string>


class  Date
{
private:
	int day;
	int month;
	int year;

	bool isValidDate(int d, int m, int y) const;
    void setDefaultDate();

public:
	 Date();
	 Date(int d, int m, int y);
	 Date(const std::string& dateStr);


	 void setDay(int d);
	 void setMonth(int m);
	 void setYear(int y);


	 void printDate() const;


};

