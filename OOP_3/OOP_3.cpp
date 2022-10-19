/*
* реализовать класс Triangle с полями-координатами вершин
* для представления координат вершин используйте класс Point
*/


#include "Triangle.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Triangle User_Input()
{
	int choice = 0;
	cout << "Выберите способ инициализации треугольника\n" <<
		"1.По трем сторонам\n" <<
		"2.По двум сторонам и углу\n" <<
		"3.По стороне и двум углам\n" <<
		"4.По координатам точек\n" <<
		"5.Выход\n";

	double a, b, c;
	Point p1, p2, p3;
	do
	{
		bool error = false;
		do
		{
			cin >> choice;
			if (choice < 1 || choice > 5)
				error = true;
		} while (error);

		if (choice == 5) exit(0);

		bool first_init = choice == 1 || choice == 2 || choice == 3;

		cout << "Введите значения\n";

		switch (first_init)
		{
		case true:

			cin >> a >> b >> c;
			
			break;
		case false:

			cin >> p1 >> p2 >> p3;
			
			break;
		}
		if(first_init)
			return Triangle(a, b, c, choice);
		else
			return Triangle (p1, p2, p3);

	} while (choice != 5);
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Triangle triangle = User_Input();
	//Triangle triangle(3, 3, 3, 1); // 1 - три стороны. 2 - 2 стороны, угол. 3 - сторона, два угла
	double h1, h2, h3;
	triangle.CalcHeights(h1, h2, h3);
	std::cout << triangle.toString() << triangle.TriType() << triangle.CalcArea() << "\n" << triangle.CalcPerim();
}
