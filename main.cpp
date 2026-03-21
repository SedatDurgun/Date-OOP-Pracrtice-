#include <iostream>
#include "date.h"

int main()
{
	std::cout << "****DATE CLASS TEST ****\n\n";

	Date d1;
	std::cout << "Default date: ";
	d1.printDate();

	Date d2(29, 2, 2020);
	std::cout << "Valid date (29.02.2020): ";
	d2.printDate();

	Date d3(31, 4, 2021);
	std::cout << "Invalid date (31.04.2021): ";
	d3.printDate();

	Date d4("15.08.1947");
	std::cout << "Valid date from string (15.08.1947): ";
	d4.printDate();

	Date d5("31.02.2021");
	std::cout << "Invalid date from string (31.02.2021): ";
	d5.printDate();

	Date d6("invalid date");
	d6.setDay(10);
	d6.setMonth(10);
	d6.setYear(2020);
	d6.printDate();
	

	
}

