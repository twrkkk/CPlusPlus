

#include <iostream>
#include "Auto.h"

Auto::Auto()
{

}

Auto::Auto(std::string model, std::string car_brand, int year)
{
    this->model = model;
    this->car_brand = car_brand;
    this->year = year;
}

std::string Auto::get_model()
{
    return model;
}

void Auto::set_model(std::string model)
{
    this->model = model;
}

std::string Auto::get_car_brand()
{
    return car_brand;
}

void Auto::set_car_brand(std::string car_brand)
{
    this->car_brand = car_brand;
}

int Auto::get_year()
{
    return year;
}

void Auto::set_year(int year)
{
    this->year = year;
}

std::string Auto::info()
{
    return "car brand: " + get_car_brand() + '\n' + "car model: " + get_model() + '\n' + "car year: " + std::to_string(get_year()) + '\n';
}

bool Auto::isTheSameBrand(Auto car)
{
    return this->get_car_brand() == car.get_car_brand();
}
