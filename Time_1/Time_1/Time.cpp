#include "Time.h"

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
		else  this->seconds = stoi(token); //if  (this->seconds == -1)
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
	return this->hours * 60 + this->minutes + (this->seconds >= 30)? 1:0;
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