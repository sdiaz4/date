// date.cpp : Source file for your target.
//

#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "date.hpp"
#include <iostream>



namespace util {

	Date::Date() : Date(1, 1, 1970) {};

	int Date::day() const {
		return timeInformation.tm_mday;
	}

	int Date::month() const {
		return timeInformation.tm_mon + 1;
	}

	int Date::year() const {
		return timeInformation.tm_year + 1900;
	}

	Date::Date(int day, int month, int year) {

		tm t = {};
		t.tm_mday = day;
		t.tm_mon = month - 1;
		t.tm_year = year - 1900;
		t.tm_hour = 12;
		t.tm_min = 0;
		t.tm_sec = 0;
		t.tm_isdst = -1;
		

		tm copy =  t;

		mktime(&copy);

		if (t.tm_mday == copy.tm_mday &&
			t.tm_mon == copy.tm_mon &&
			t.tm_year == copy.tm_year) {

			timeInformation = copy;

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

	string Date::dayName() const {
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

	string Date::monthName() const {
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

	void Date::print(std::ostream& outstream) const {
		int day = timeInformation.tm_mday;
		int month = timeInformation.tm_mon + 1;
		int year = timeInformation.tm_year + 1900;
		switch (Date::order) {
		case Date::Order::MonthDayYear:
			outstream << month << separator << day << separator << year;
			break;
		case Date::Order::DayMonthYear:
			outstream << day << separator << month << separator << year;
			break;
		case Date::Order::YearMonthDay:
			outstream << year << separator << month << separator << day;
			break;
		}
	}

	Date Date::now() {
		time_t t = time(nullptr);
		tm time = *localtime(&t);
		int day = time.tm_mday;
		int month = time.tm_mon + 1;
		int year = time.tm_year + 1900;

		return Date(day, month, year);
	}

}
