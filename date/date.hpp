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

	private:
		tm timeInformation;

	};

	

}