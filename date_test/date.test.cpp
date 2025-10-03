// date.cpp : Defines the entry point for the application.
//
#include "date.hpp"
#include <gtest/gtest.h>

TEST(DefaultCtor, HasCorrectValue) {

	util::Date d;

	EXPECT_EQ(d.day(), 31);
	EXPECT_EQ(d.month(), 12);
	EXPECT_EQ(d.year(), 1969);

}

TEST(ValueCtor, CorrectValues) {

	util::Date d(12, 4, 2024);
	EXPECT_EQ(d.day(), 12);
	EXPECT_EQ(d.month(), 4);
	EXPECT_EQ(d.year(), 2024);
}


TEST(Setters, RightValues) {
	util::Date d(1, 1, 2020);
	d.day(12);
	d.month(12);
	d.year(2021);

	EXPECT_EQ(d.day(), 12);
	EXPECT_EQ(d.month(), 12);
	EXPECT_EQ(d.year(), 2021);

}






