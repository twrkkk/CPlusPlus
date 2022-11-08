#pragma once
#include <string>
#include <iostream>
#include <fstream>

//using Date = int[3];

struct Ticket
{
private:
	std::string target, plane_model, FIO;
	int number;
	int day, month, year;
public:
	Ticket() {};
	Ticket(std::ifstream&);

	int compare(const Ticket&);

	std::string get_target() const;
	std::string get_plane_model() const;
	std::string get_FIO() const;
	int get_number() const;
	int get_day() const;
	int get_month() const;
	int get_year() const;
	
	void print();
};