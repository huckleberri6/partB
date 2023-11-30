
#include <iostream>
using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);

int main()
{
	int day;
	int month;
	int year;
	cout << "Enter a date or Q to quit: ";
	cin >> month >> day >> year;

	while (!cin.fail())
	{
		string m;

		if (month == 1)
			m = "January";
		else if (month == 2)
			m = "February";
		else if (month == 3)
			m = "March";
		else if (month == 4)
			m = "April";
		else if (month == 5)
			m = "May";
		else if (month == 6)
			m = "June";
		else if (month == 7)
			m = "July";
		else if (month == 8)
			m = "August";
		else if (month == 9)
			m = "September";
		else if (month == 10)
			m = "October";
		else if (month == 11)
			m = "November";
		else
			m = "December";

		int weekday = dayOfWeek(month, day, year);
		string d;
		if (weekday == 0)
			d = "Saturday";
		else if (weekday == 1)
			d = "Sunday";
		else if (weekday == 2)
			d = "Monday";
		else if (weekday == 3)
			d = "Tuesday";
		else if (weekday == 4)
			d = "Wednesday";
		else if (weekday == 5)
			d = "Thursday";
		else
			d = "Friday";

		cout << d << ", " << m << " " << day << ", " << year << endl;
		
		cout << "Enter a date Q to quit: ";
		cin >> month >> day >> year;
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

/**
dayOfWeek - Computes the weekday of a given date.
@param year the year
@param month the month (1 = January ... 12 = December)
@param day the day of the month
@return the weekday (0 = Saturday ... 6 = Friday)
*/
int dayOfWeek(int month, int day, int year)
{
	if (month < 3)
	{
		month += 12;
		year--;
	}

	int weekday = (day + ( ( (month + 1) * 26 ) / 10 ) + year + ( year / 4 ) + 6 * ( year / 100 ) + ( year / 400) ) % 7;
	//int weekday = (day + (13 * (month + 1)) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
	return weekday;
}