# CMakeList.txt : CMake project for date, include source and define
# project specific logic here.
#


target_include_directories(date PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/date)

# Add source to this project's executable.
add_executable (date_test "date.test.cpp" )

target_link_libraries(date_test "gtest_main" "date")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET date_test PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
