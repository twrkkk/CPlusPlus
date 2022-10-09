//the first laboratory work task 10
/*
class Time <23:59:59>
initialize by string, numbers, seconds, time
   *calculate difference between two times in seconds
   *sum of time and seconds
   *subtracting seconds from time
   * compare two times
   * translation to minutes(rounding to a whole), seconds

*/

#pragma once

#include <string>
#include <iostream>

using string = std::string;
class Time
{
	int hours = -1, minutes = -1, seconds = -1;

public:
	int get_hours();
	void set_hours(int h);
	int get_minutes();
	void set_minutes(int m);
	int get_seconds();
	void set_seconds(int s);

	Time(int hours, int minutes, int seconds);
	Time(string time);
	Time(int seconds);
	Time() {};

	int calculateDifference(Time anotherTime); // in sec 
	void addSeconds(int sec);
	void subtractingSeconds(int sec);
	int compareTime(Time anotherTime);
	int toSeconds();
	int toMinutes();
	std::string toString();
};