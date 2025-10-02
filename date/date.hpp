// date.h : Header file for your target.

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "date.hpp"


namespace util {

	class Date
	{
	public:
		Date();

		struct Invalid {
			int day;
			int month;
			int year;
		};

		enum class Order {
			MonthDayYear,
			DayMonthYear,
			YearMonthDay
		};

		int const day();
		int const month();
		int const year();

		Date(int day, int month, int year);

	private:
		tm timeInformation;
	};

	

}