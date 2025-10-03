// date.h : Header file for your target.

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>
#include "date.hpp"
using std::string;


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

		int day() const;
		int month() const;
		int year() const;

		void day(int day);
		void month(int month);
		void year(int year);
		string dayName() const;
		string monthName() const;
		void advance(int days = 1);
		void print(std::ostream&) const;
		
	
		Date(int day, int month, int year);
		static Date now();

		static Order order;
		static char separator;

	private:
		tm timeInformation;
	};

	

}