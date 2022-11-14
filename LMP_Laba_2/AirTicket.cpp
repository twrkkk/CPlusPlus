#include "AirTicket.h"

Ticket::Ticket(std::ifstream& file)
{
	std::getline(file, target);
	std::getline(file, plane_model);
	std::getline(file, FIO);
	file >> number;
	file >> day >> month >> year;
	file.ignore();
	std::string delim_line;
	std::getline(file, delim_line);
}

int Ticket::compare(const Ticket& ticket)
{
	auto compare_date = [](const Ticket& tik1, const Ticket& tik2)
	{
		int result = 1;
		(tik1.get_year() > tik2.get_year()) ? result = 1 : (tik1.get_month() < tik2.get_month()) ? result = -1 :
			(tik1.get_month() > tik2.get_month()) ? result = 1 : (tik1.get_month() < tik2.get_month()) ? result = -1 :
			(tik1.get_day() > tik2.get_day()) ? result = 1 : (tik1.get_day() < tik2.get_day()) ? result = -1 : result = 0;
		return result;
	};

	int result = 1;
	if (target < ticket.get_target() ||
		target == ticket.get_target() && (compare_date(*this, ticket) < 0) ||
		target == ticket.get_target() && (compare_date(*this, ticket) == 0) && number < ticket.get_number())
		result = -1;
	else if (target == ticket.get_target() && (compare_date(*this, ticket) == 0) && number == ticket.get_number())
		result = 0;

	return result;
}

std::string Ticket::get_target() const
{
	return target;
}

std::string Ticket::get_plane_model()const
{
	return plane_model;
}

std::string Ticket::get_FIO()const
{
	return FIO;
}

int Ticket::get_number() const
{
	return number;
}

int Ticket::get_day() const
{
	return day;
}

int Ticket::get_month() const
{
	return month;
}

int Ticket::get_year() const
{
	return year;
}


void Ticket::print()
{
	std::cout << target << '\n';
	std::cout << number << '\n';
	std::cout << plane_model << '\n';
	std::cout << FIO << '\n';
	std::cout << day << ' ' << month << ' ' << year << '\n';
	std::cout << '\n';
}