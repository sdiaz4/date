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




}
