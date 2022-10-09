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
	int hours = 0, minutes = 0, seconds = 0;

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

int Time::get_hours()
{
	return this->hours;
}
void Time::set_hours(int h)
{
	this->hours = h;
}
int Time::get_minutes()
{
	return this->minutes;
}
void Time::set_minutes(int m)
{
	this->hours = m;
}
int Time::get_seconds()
{
	return this->seconds;
}
void Time::set_seconds(int s)
{
	this->hours = s;
}

Time::Time(int hours, int minutes, int seconds)
{
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

Time::Time(string time)
{
	std::string delimiter = ":";

	size_t pos = 0;
	std::string token;
	while ((pos = time.find(delimiter)) != std::string::npos) {
		token = time.substr(0, pos);
		if (this->hours == -1) this->hours = stoi(token);
		else if (this->minutes == -1) this->minutes = stoi(token);
		else this->seconds = stoi(token);
		time.erase(0, pos + delimiter.length());
	}
}

Time::Time(int seconds)
{
	this->hours = seconds / 3600;
	this->minutes = seconds % 3600 / 60;
	this->seconds = seconds % 3600 % 60;

	/*this->hours = seconds / 3600;
	this->minutes = (seconds - hours * 3600) / 60;
	this->seconds = seconds - hours * 3600 - minutes * 60;*/
}

int Time::calculateDifference(Time anotherTime)
{
	return abs(this->toSeconds() - anotherTime.toSeconds());
}

int Time::toSeconds()
{
	return this->hours * 3600 + this->minutes * 60 + this->seconds;
}

int Time::toMinutes()
{
	return this->hours * 60 + this->minutes + ((this->seconds >= 30) ? 1 : 0);
}

void Time::addSeconds(int sec)
{
	int newSec = this->toSeconds() + sec;
	this->hours = newSec / 3600;
	this->minutes = newSec % 3600 / 60;
	this->seconds = newSec % 3600 % 60;
}

void Time::subtractingSeconds(int sec)
{
	int newSec = this->toSeconds() - sec;
	this->hours = newSec / 3600;
	this->minutes = newSec % 3600 / 60;
	this->seconds = newSec % 3600 % 60;
}

int Time::compareTime(Time anotherTime)
{
	int result = 0;
	int sec1 = this->toSeconds();
	int sec2 = anotherTime.toSeconds();

	if (sec1 > sec2)
		result = 1;
	else if (sec1 < sec2)
		result = -1;

	return result;
}

std::string Time::toString()
{
	return std::to_string(this->get_hours()) + " : hours, " + std::to_string(this->get_minutes()) + " : minutes " + std::to_string(this->get_seconds()) + " : seconds.";

}

using std::cin;
using std::cout;
int main()
{
	cout << "Enter first time" << '\n';
	int h, m, s;
	cin >> h >> m >> s;
	Time time(h, m, s);
	cout << time.toMinutes();

	cout << "Enter second time" << '\n';
	cin >> h >> m >> s;
	Time time2(h, m, s);

	cout << time.toString() << '\n';
	cout << time2.toString() << '\n';

	cout << "Difference between two times: " << time.calculateDifference(time2) << '\n';

	cout << "How many seconds will you add?" << '\n';
	int sec;
	cin >> sec;
	cout << "First time between changes: " << time.toString() << '\n';
	time.addSeconds(sec);
	cout << "First time after changes: " << time.toString() << '\n';

	cout << "Second time between changes: " << time2.toString() << '\n';
	time2.addSeconds(sec);
	cout << "Second time after changes: " << time2.toString() << '\n';

	cout << "compare time: " << time.compareTime(time2) << '\n';
}

