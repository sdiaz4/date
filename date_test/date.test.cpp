// date.cpp : Defines the entry point for the application.
//
#include "date.hpp"
#include <gtest/gtest.h>

TEST(DefaultCtor, HasCorrectValue) {

	util::Date d;

	EXPECT_EQ(d.day(), 1);
	EXPECT_EQ(d.month(), 1);
	EXPECT_EQ(d.year(), 1970);

}

TEST(ValueCtor, CorrectValues) {

	util::Date d(12, 4, 2024);
	EXPECT_EQ(d.day(), 12);
	EXPECT_EQ(d.month(), 4);
	EXPECT_EQ(d.year(), 2024);
}


TEST(Setters, CorrectValues) {
	util::Date d(1, 1, 2020);
	d.day(12);
	d.month(12);
	d.year(2021);

	EXPECT_EQ(d.day(), 12);
	EXPECT_EQ(d.month(), 12);
	EXPECT_EQ(d.year(), 2021);

}

TEST(Props, CorrectValues) {
	util::Date d(3, 10, 2025);
	
	EXPECT_EQ(d.dayName(), "Friday");
	EXPECT_EQ(d.monthName(), "October");
}


TEST(Advance, CorrectValuesDefault) {
	util::Date d(3, 10, 2025);
	d.advance();

	EXPECT_EQ(d.day(), 4);
}

TEST(Advance, CorrectValuesback) {
	util::Date d(3, 10, 2025);
	d.advance(-1);

	EXPECT_EQ(d.day(), 2);
}

TEST(Advance, CorrectValuesForwardSeven) {
	util::Date d(3, 10, 2025);
	d.advance(7);

	EXPECT_EQ(d.day(), 10);
}

TEST(Print, CorrectValues) {
	util::Date d(4, 7, 2015);
	util::Date::order = util::Date::Order::MonthDayYear;
	util::Date::separator = '/';

	std::ostringstream out;
	d.print(out);
	EXPECT_EQ(out.str(), "7/4/2015");
}

//TEST(Now, CorrectValues) {
//
//}






