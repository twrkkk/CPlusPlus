#include "Auto.h"
#include <iostream>

const int SIZE = 4;

bool isGoodCar(Auto car)
{
	return car.get_year() > 2020;
}

int main()
{
	Auto cars[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Enter car model" << '\n';
		std::string model;
		std::cin >> model;
		cars[i].set_model(model);

		std::cout << "Enter car brand" << '\n';
		std::string brand;
		std::cin >> brand;
		cars[i].set_car_brand(brand);

		std::cout << "Enter car year" << '\n';
		int year;
		std::cin >> year;
		cars[i].set_year(year);
	}

	for (int i = 0; i < SIZE; i++)
	{
		if (isGoodCar(cars[i]))
			std::cout<<cars[i].info();
	}


	
}

