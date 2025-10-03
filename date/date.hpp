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

		int const day();
		int const month();
		int const year();

		void day(int day);
		void month(int month);
		void year(int year);
		string const dayName();
		string const monthName();
		void advance(int days);
		void print(std::ostream&);
		
	
		Date(int day, int month, int year);

	private:
		tm timeInformation;
		static Order order;
		static char separator;

		
	};

	

}