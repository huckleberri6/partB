
#include <iostream>
using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);

int main()
{
	int month;
	int year;
	cout << "Enter a month and year or Q to quit: ";
	cin >> month >> year;

	while (!cin.fail())
	{
		int days = daysInMonth(month, year);
		if (month == 1)
			cout << "January " << year << " has " << days << " days" << endl;
		else if (month == 2)
			cout << "February " << year << " has " << days << " days" << endl;
		else if (month == 3)
			cout << "March " << year << " has " << days << " days" << endl;
		else if (month == 4)
			cout << "April " << year << " has " << days << " days" << endl;
		else if (month == 5)
			cout << "May " << year << " has " << days << " days" << endl;
		else if (month == 6)
			cout << "June " << year << " has " << days << " days" << endl;
		else if (month == 7)
			cout << "July " << year << " has " << days << " days" << endl;
		else if (month == 8)
			cout << "August " << year << " has " << days << " days" << endl;
		else if (month == 9)
			cout << "September " << year << " has " << days << " days" << endl;
		else if (month == 10)
			cout << "October " << year << " has " << days << " days" << endl;
		else if (month == 11)
			cout << "November " << year << " has " << days << " days" << endl;
		else if (month == 12)
			cout << "December " << year << " has " << days << " days" << endl;

		
		cout << "Enter a month and year or Q to quit: ";
		cin >> month >> year;
	}
}

/**
isLeapYear – determines whether a given year is a leap year
under the Gregorian calendar.
@param year the year; expected to be >= 1582
@return true if year is a leap year; false otherwise
*/
bool isLeapYear(int year) 
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0 && year % 400 != 0)
			return false;
		return true;
	}
	else
		return false;
}


/**
daysInMonth – determines the number of days in a specified month
@param month the month; expected to be in the range [1..12]
@param year the year; expected to be >= 1582
@return either 28, 29, 30, or 31, based on month and (leap) year
*/
int daysInMonth(int month, int year)
{
	if (month == 1)
	{
		return 31;
	}
	else if (month == 2)
	{
		if (isLeapYear(year))
		{
			return 29;
		}
		else
			return 28;
	}
	else if (month == 3)
		return 31;
	else if (month == 4)
		return 30;
	else if (month == 5)
		return 31;
	else if (month == 6)
		return 30;
	else if (month == 7)
		return 31;
	else if (month == 8)
		return 31;
	else if (month == 9)
		return 30;
	else if (month == 10)
		return 31;
	else if (month == 11)
		return 30;
	else if (month == 12)
		return 31;

	return -1;

}