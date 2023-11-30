
#include <iostream>
using namespace std;

bool isLeapYear(int year);

int main()
{
	int year;
	cout << "Enter a year or Q to quit: ";
	cin >> year;

	while (!cin.fail())
	{
		if (isLeapYear(year))
			cout << year << " is a leap year." << endl;
		else
			cout << year << " is not a leap year." << endl;
		
		cout << "Enter a year or Q to quit: ";
		cin >> year;
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
