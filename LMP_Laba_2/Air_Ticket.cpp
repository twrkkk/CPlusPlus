#include <iostream>
#include <fstream>
#include <Windows.h>
#include "My_list.h"

bool task(DLIST& list)
{
	bool result = false;

	std::cout << "----------------------------\n";
	std::string place;
	std::cout << "Enter target\n";
	std::cin >> place;

	int day, month, year;
	std::cout << "Enter date\n";
	std::cin >> day >> month >> year;
	std::cout << "----------------------------\n";

	ptrNODE p = list.get_begin();
	while (p)
	{
		if (p->info.get_target() == place || 
			(p->info.get_day() == day && p->info.get_month() == month && p->info.get_year() == year))
		{
			list.Delete(p);
			result = true;
		}
		else
			p = p->next;
	}


	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream file("tickets.txt");
	if (file)
	{
		DLIST DL(file);
		DL.print();
		
		if (task(DL))
			DL.print();
		else
			std::cout << "no target\n";
	}
	std::cin.get();
	return 0;
}
