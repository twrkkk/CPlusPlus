//пользователем вводятся координаты 3х точек треугольника. Программа определяет, является ли треугольник остроугольным и разносторонним
#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	//ввод координат
	double x1, y1, x2, y2, x3, y3;
	std::cout << "Ведите координаты трёх точек: \n ";
	std::cout << "1-я точка:\n ";
	std::cin >> x1 >> y1;
	std::cout << "2-я точка:\n ";
	std::cin >> x2 >> y2;
	std::cout << "3-я точка:\n ";
	std::cin >> x3 >> y3;
	//вычисление длин сторон треугольника
	double a, b, c;
	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	//a<b<c
	if (a > b)
		std::swap(a, b);
	if (b > c)
		std::swap(b, c);
	if (a + b > c)
	{
		double cos_a = (b * b + c * c - a * a) / (2 * b * c);
		double cos_b = (a * a + c * c - b * b) / (2 * a * c);
		double cos_c = (b * b + a * a - c * c) / (2 * a * b);

		if (cos_a > 0 && cos_a < 1 && cos_b > 0 && cos_b < 1 && cos_c > 0 && cos_c < 1 && a != b && b != c && a != c)
		{
			std::cout << "Треугольник остроугольный и разносторонний \n";
			double S = a * b / 2 * sqrt(1 - cos_c * cos_c);
			double h1 = 2 * S / a;
			double h2 = 2 * S / b;
			double h3 = 2 * S / c;
			std::cout << "Высоты треугольника равны " << h1 << " " << h2 << " " << h3;
		}
	}
	else
	{
		std::cout << "Треугольник не существует \n";
	}
}

