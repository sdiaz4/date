// date.cpp : Source file for your target.
//

#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "date.hpp"



namespace util {

	Date::Date() {
		time_t t = 0;
		timeInformation = *localtime(&t);

	};

	int const Date::day() {
		return timeInformation.tm_mday;
	}

	int const Date::month() {
		return timeInformation.tm_mon;
	}

	int const Date::year() {
		return timeInformation.tm_year;
	}

	Date::Date(int day, int month, int year) {

		tm t;
		t.tm_mday = day;
		t.tm_mon = month - 1;
		t.tm_year = year - 1900;

		tm copy =  t;

		mktime(&copy);

		if (t.tm_mday == copy.tm_mday &&
			t.tm_mon == copy.tm_mon &&
			t.tm_year == copy.tm_year) {

			timeInformation = t;

		}
		else {
			throw Invalid{ day, month, year };
		}

	}

	void Date::day(int day) {
		tm copy = timeInformation;
		copy.tm_mday = day;
		tm t = copy;
		mktime(&copy);

		if (copy.tm_mday == t.tm_mday && copy.tm_mon == t.tm_mon && copy.tm_year == t.tm_year)
		{
			timeInformation = copy;
		}
		else {
			throw Invalid{ day, month(), year()};
		}
		
	}

	void Date::month(int month) {
		tm copy = timeInformation;
		copy.tm_mon = month - 1;
		tm t = copy;
		mktime(&copy);

		if (copy.tm_mday == t.tm_mday && copy.tm_mon == t.tm_mon && copy.tm_year == t.tm_year)
		{
			timeInformation = copy;
		}
		else {
			throw Invalid{ day(), month, year()};
		}

	}
	void Date::year(int year) {
		tm copy = timeInformation;
		copy.tm_year = year - 1900;
		tm t = copy;
		mktime(&copy);

		if (copy.tm_mday == t.tm_mday && copy.tm_mon == t.tm_mon && copy.tm_year == t.tm_year)
		{
			timeInformation = copy;
		}
		else {
			throw Invalid{ day(), month(), year};
		}

	}

	string const Date::dayName() {
		int day = timeInformation.tm_wday;
		switch (day) {
		case 0: return "Sunday";
		case 1: return "Monday";
		case 2: return "Tuesday";
		case 3: return "Wednesday";
		case 4: return "Thursday";
		case 5: return "Friday";
		case 6: return "Saturday";
		default: return "Invalid";
		}
				 

	}

	string const Date::monthName() {
		int month = timeInformation.tm_mon;
		switch (month) {
		case 0: return "January";
		case 1: return "February";
		case 2: return "March";
		case 3: return "April";
		case 4: return "May";
		case 5: return "June";
		case 6: return "July";
		case 7: return "August";
		case 8: return "September";
		case 9: return "October";
		case 10: return "November";
		case 11: return "December";
		default: return "Invalid";
		}
	}

	void Date::advance(int days) {
		time_t seconds = mktime(&timeInformation);
		seconds += days * 24 * 60 * 60;
		timeInformation = *localtime(&seconds);
		
	}

	Date::Order Date::order = Date::Order::MonthDayYear;
	char Date::separator = '/';

}
