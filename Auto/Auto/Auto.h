#pragma once
#include <string>

class Auto
{
	std::string model;
	std::string car_brand;
	int year;
public:
	Auto();
	Auto(std::string model, std::string car_brand, int year);
	std::string get_model();
	void set_model(std::string model);
	std::string get_car_brand();
	void set_car_brand(std::string car_brand);
	int get_year();
	void set_year(int year);
	std::string info();
	bool isTheSameBrand(Auto car);
};