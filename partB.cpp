
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);

int main()
{
	string month;
	int year;
	cout << "Enter a month and year or Q to quit: ";
	cin >> month;
	if (month == "Q")
		return 1;

	cin >> year;
	if (cin.fail())
		return 1;

	while (month != "Q")
	{
		int m;

		if (month == "January")
			m = 1;
		else if (month == "February")
			m = 2;
		else if (month == "March")
			m = 3;
		else if (month == "April")
			m = 4;
		else if (month == "May")
			m = 5;
		else if (month == "June")
			m = 6;
		else if (month == "July")
			m = 7;
		else if (month == "August")
			m = 8;
		else if (month == "September")
			m = 9;
		else if (month == "October")
			m = 10;
		else if (month == "November")
			m = 11;
		else
			m = 12;

		int day = 1;
		int weekday = dayOfWeek(m, day, year);
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

		//cout << d << ", " << m << " " << day << ", " << year << endl;
		
		


		// Sa Fr Th We Tu Mo Su
		// 00 01 02 03 04 05 06 07 08 09 10 11 12
		// 01234567890123456789012345678901234567
		string calendar[6] =
	  { "                   1  2  3  4  5  6  7 ",
		" 2  3  4  5  6  7  8  9 10 11 12 13 14 ",
		" 9 10 11 12 13 14 15 16 17 18 19 20 21 ",
		"16 17 18 19 20 21 22 23 24 25 26 27 28 ",
		"23 24 25 26 27 28 29 30 31 ",
		"30 31 " };

		int skips = (weekday - 1) * 3;


		string filename = month.substr(0,3) + to_string(year) + ".txt";
		ofstream file(filename);

		cout << endl;
		cout << month << " " << year << endl;
		cout << "Su Mo Tu We Th Fr Sa" << endl;

		file << month << " " << year << endl;
		file << "Su Mo Tu We Th Fr Sa" << endl;

		for (int i = 0; i < daysInMonth(m, year); i++)
		{
			if (dayOfWeek(m, i + 1, year) == 1)
			{
				cout << endl;
				file << endl;
			}

			//cout << dayOfWeek(m, i + 1, year) << endl;

			if (i == 0)
			{
				for (int j = 0; j < skips; j++)
				{
					cout << " ";
					file << " ";
				}
			}

			if (i < 9)
			{
				cout << " ";
				file << " ";
			}
			cout << i + 1 << " ";
			file << i + 1 << " ";
		}

		cout << endl;
		file << endl;
		cout << endl;
		file << endl;

		cout << "Output file: " << filename << endl;
		cout << endl;

		cout << "Enter a month and year or Q to quit: ";
		cin >> month;
		if (month == "Q")
			break;

		cin >> year;
		if (cin.fail())
			break;
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
