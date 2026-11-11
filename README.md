# Date Class (C++)

A C++ `util::Date` class for creating, checking, changing and printing calendar dates, built as a static library and tested with GoogleTest. It's built on the C standard library's `<ctime>` (`std::tm` and `mktime`), which handles month lengths, leap years and days of the week.

## Example

```cpp
#include "date.hpp"
using util::Date;

Date d(28, 2, 2024);                 // day, month, year
d.dayName();                         // "Wednesday"
d.monthName();                       // "February"
d.print(std::cout);                  // 2/28/2024

d.advance();                         // move forward one day (leap year)
d.print(std::cout);                  // 2/29/2024

Date::order = Date::Order::YearMonthDay;
Date::separator = '-';
d.print(std::cout);                  // 2024-2-29

try {
    Date bad(31, 4, 2025);           // April has no 31st
} catch (Date::Invalid const& e) {
    // e.day == 31, e.month == 4, e.year == 2025
}
```

## Features

| Member | Description |
| --- | --- |
| `Date()` | Defaults to January 1, 1970. |
| `Date(day, month, year)` | Creates a date. Throws `Date::Invalid` (holding the bad day, month and year) if the date doesn't exist. |
| `Date::now()` | Today's date from the system clock. |
| `day()`, `month()`, `year()` | Getters. |
| `day(int)`, `month(int)`, `year(int)` | Setters. Each validates the new date and throws `Invalid` without changing anything if it's not real. |
| `dayName()`, `monthName()` | Names such as `"Friday"` and `"October"`. |
| `advance(days = 1)` | Moves the date forward or backward (negative values) by a number of days. |
| `print(ostream&)` | Prints the date using the shared `Date::order` and `Date::separator` settings. |
| `Date::order` | `MonthDayYear` (default), `DayMonthYear` or `YearMonthDay`. |
| `Date::separator` | Character between the parts (default `/`). |

**How validation works:** the requested date is copied into a `tm` and run through `mktime`, which normalizes impossible dates (April 31 becomes May 1). If the normalized day, month or year differs from what was requested, the date was invalid.

## Project layout

| Path | Description |
| --- | --- |
| `date/date.hpp`, `date/date.cpp` | The `util::Date` class. |
| `date_test/date.test.cpp` | GoogleTest tests for the constructors, setters, day and month names, `advance` (forward, backward and by a week), and `print`. |
| `CMakeLists.txt` | Top-level CMake project. Downloads GoogleTest with `FetchContent`. |
| `CMakePresets.json` | Build presets for Windows, Linux and macOS. |

## Building and testing

Requires CMake 3.8 or later and a C++20 compiler.

**Visual Studio:** open the folder as a CMake project, choose a preset such as **x64 Debug**, and run the tests from **Test Explorer**.

**Command line:**

```
cmake -S . -B build
cmake --build build
ctest --test-dir build
```

## Project notes

- **Project:** Date
- **Author:** Simon Diaz
- **Description:** A date class with methods to change and check the date, with tests covering each method.
- **External resources:** [Constructors (C++), Microsoft Learn](https://learn.microsoft.com/en-us/cpp/cpp/constructors-cpp?view=msvc-170)
- **Special instructions:** None.
- **Shortcomings:** With more time, I'd plan ahead for how long the project needs and use resources more diligently.
- **Strengths:** Functional and efficient code.
