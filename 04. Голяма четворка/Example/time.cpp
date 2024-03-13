#include "time.h"
#include <iostream>
#include <cassert>

Time::Time(int hour, int minute, int second)
{
	this->set_hour(hour);
	this->set_minute(minute);
	this->set_second(second);
}

Time::Time() 
{
    std::cout << "Default constructor for Time" << std::endl;
    this->set_hour(0);
	this->set_minute(0);
	this->set_second(0);
}

Time::Time(Time const& other_time) 
{
    std::cout << "Copy constructor for Time" << std::endl;
    this->set_hour(other_time.hour);
	this->set_minute(other_time.minute);
	this->set_second(other_time.second);
}

Time& Time::operator= (Time const& other_time) 
{
    std::cout << "Operator \"equals\" for Time" << std::endl;
    if (this != &other_time) {
        this->set_hour(other_time.hour);
        this->set_minute(other_time.minute);
        this->set_second(other_time.second);
    }
    return *this;
}

Time::~Time() {
    std::cout << "Destructor for Time. Nothing to do here." << std::endl;
}

int Time::get_hour()
{
	return this->hour;
}

int Time::get_minute()
{
	return this->minute;
}

int Time::get_second()
{
	return this->second;
}

void Time::set_hour(const int hour)
{
	assert(hour >= 0);
	this->hour = hour;
}

void Time::set_minute(const int minute)
{
	assert(minute >= 0 && minute < 60);
	this->minute = minute;
}

void Time::set_second(const int second)
{
	assert(second >= 0 && second < 60);
	this->second = second;
}

bool Time::is_smaller_or_equal(const Time other_time) const
{
	return this->hour < other_time.hour
		|| (this->hour == other_time.hour
			&& (this->minute < other_time.minute
				|| (this->minute == other_time.minute
					&& this->second <= other_time.second)
				)
			);
}


Time Time::find_difference(const Time other_time) const
{
	if (!this->is_smaller_or_equal(other_time)) {
		return other_time.find_difference(*this);
	}

	int diff_hour = other_time.hour - hour;
	int diff_minute = other_time.minute - minute;
	int diff_second = other_time.second - second;

	if (diff_second < 0) {
		diff_second += 60;
		diff_minute--;
	}

	if (diff_minute < 0) {
		diff_minute += 60;
		diff_hour--;
	}

	return Time(diff_hour, diff_minute, diff_second);
}

void Time::print() const
{
	std::cout << "Hours: " << hour << std::endl
		<< "Minutes: " << minute << std::endl
		<< "Seconds: " << second << std::endl;
}