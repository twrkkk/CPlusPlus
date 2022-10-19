#include "Triangle.h"

Triangle::Triangle()
{
	AB = 0;
	BC = 0;
	AC = 0;

	angleA = 0;
	angleB = 0;
	angleC = 0;
}



Triangle::Triangle(double A, double B, double C, int choice)
{
	double kayf;
	switch (choice)
	{
	case 1:
		AB = A;
		BC = B;
		AC = C;

		angleA = acos((AB * AB + AC * AC - BC * BC) / (2 * AB * AC)) * 180.0 / PI;
		angleB = acos((AB * AB + BC * BC - AC * AC) / (2 * AB * BC)) * 180.0 / PI;
		angleC = acos((BC * BC + AC * AC - AB * AB) / (2 * BC * AC)) * 180.0 / PI;

		break;
	case 2:
		double cosB;

		AB = A;
		BC = B;
		angleB = C;

		if (angleB <= 90)
		{
			cosB = cos(angleB * 180.0 / PI);
		}
		else
		{
			cosB = -cos(180 - angleB * 180.0 / PI);
		}

		AC = sqrt(AB * AB + BC * BC - 2 * AB * BC * cosB);
		angleA = acos((AB * AB + AC * AC - BC * BC) / (2 * AB * AC)) * 180.0 / PI;
		angleC = acos((BC * BC + AC * AC - AB * AB) / (2 * BC * AC)) * 180.0 / PI;

		break;
	case 3:
		angleA = A;
		angleB = B;
		AB = C;

		angleC = 180.0 - angleA - angleB;
		kayf = AB / sin(angleC * 180.0 / PI);
		BC = sin(angleA * 180.0 / PI) * kayf;
		AC = sin(angleB * 180.0 / PI) * kayf;

		break;
	default:
		AB = 0;
		BC = 0;
		AC = 0;

		angleA = 0;
		angleB = 0;
		angleC = 0;

		break;
	}

	if (!CheckSides() || !CheckAngles())
	{
		AB = 0;
		BC = 0;
		AC = 0;

		angleA = 0;
		angleB = 0;
		angleC = 0;
	}
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
	AB = p1.distance_to_point(p2);
	BC = p2.distance_to_point(p3);
	AC = p1.distance_to_point(p3);
	angleA = acos((AB * AB + AC * AC - BC * BC) / (2 * AB * AC)) * 180.0 / PI;
	angleB = acos((AB * AB + BC * BC - AC * AC) / (2 * AB * BC)) * 180.0 / PI;
	angleC = acos((BC * BC + AC * AC - AB * AB) / (2 * BC * AC)) * 180.0 / PI;
}

//void Triangle::SetTwoSidesAndAngle(double A, double B, double C)
//{
//	double cosB;
//
//	sideAB = A;
//	sideBC = B;
//	angleB = C;
//
//	if (angleB <= 90)
//	{
//		cosB = cos(angleB * 180.0 / PI);
//	}
//	else
//	{
//		cosB = -cos(180 - angleB * 180.0 / PI);
//	}
//
//	sideAC = sqrt(sideAB * sideAB + sideBC * sideBC - 2 * sideAB * sideBC * cosB);
//	angleA = acos((sideAB * sideAB + sideAC * sideAC - sideBC * sideBC) / (2 * sideAB * sideAC)) * 180.0 / PI;
//	angleC = acos((sideBC * sideBC + sideAC * sideAC - sideAB * sideAB) / (2 * sideBC * sideAC)) * 180.0 / PI;
//
//	if (!CheckSides() || !CheckAngles())
//	{
//		sideAB = 0;
//		sideBC = 0;
//		sideAC = 0;
//
//		angleA = 0;
//		angleB = 0;
//		angleC = 0;
//	}
//}

//void Triangle::SetTwoAnglesAndSide(double A, double B, double C)
//{
//	angleA = A;
//	angleB = B;
//	sideAB = C;
//
//	angleC = 180.0 - angleA - angleB;
//	double kayf = sideAB / sin(angleC * 180.0 / PI);
//	sideBC = sin(angleA * 180.0 / PI) * kayf;
//	sideAC = sin(angleB * 180.0 / PI) * kayf;
//
//	if (!CheckSides() || !CheckAngles())
//	{
//		sideAB = 0;
//		sideBC = 0;
//		sideAC = 0;
//
//		angleA = 0;
//		angleB = 0;
//		angleC = 0;
//	}
//}

void Triangle::Set_sideAB(double _sideAB)
{
	AB = _sideAB;
}

void Triangle::Set_sideBC(double _sideBC)
{
	BC = _sideBC;
}

void Triangle::Set_sideAC(double _sideAC)
{
	AC = _sideAC;
}

void Triangle::Set_angleA(double _angleA)
{
	angleA = _angleA;
}

void Triangle::Set_angleB(double _angleB)
{
	angleB = _angleB;
}

void Triangle::Set_angleC(double _angleC)
{
	angleC = _angleC;
}

bool Triangle::CheckSides()
{
	if ((AB <= 0 || BC <= 0 || AC <= 0) || (AB + BC <= AC || BC + AC <= AB || AC + AB <= BC))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Triangle::CheckAngles()
{
	if ((abs(angleA) <= E || angleA - 180.0 >= E) || (abs(angleB) <= E || angleB - 180.0 >= E) ||
		(abs(angleC) <= E || angleC - 180.0 >= E) || (abs(angleA + angleB + angleC - 180.0) < E))
	{
		return false;
	}
	else
	{
		return true;
	}
}

double Triangle::Get_sideAB()
{
	return AB;
}

double Triangle::Get_sideBC()
{
	return BC;
}

double Triangle::Get_sideAC()
{
	return AC;
}

double Triangle::Get_angleA()
{
	return angleA;
}

double Triangle::Get_angleB()
{
	return angleB;
}

double Triangle::Get_angleC()
{
	return angleC;
}

double Triangle::CalcArea()
{
	double area;
	double h_perim = CalcPerim() / 2;

	return sqrt(h_perim * (h_perim - AB) * (h_perim - BC) * (h_perim - AC));
}

double Triangle::CalcPerim()
{
	return AB + BC + AC;
}

void Triangle::CalcHeights(double& h1, double& h2, double& h3)
{
	h1 = AB * sin(angleA * PI / 180.0);
	h2 = BC * sin(angleB * PI / 180.0);
	h3 = AC * sin(angleC * PI / 180.0);
}

std::string Triangle::TriType()
{
	std::string type;

	if (angleA - 90.0 < E && angleB - 90.0 < E && angleC - 90.0 < E)
	{
		type = "Остроугольный треугольник\n";
	}
	//else if (angleA - 90.0 > E || angleB - 90.0 > E || angleC - 90.0 > E)
	else if (abs(AB * AB + BC * BC - AC * AC) < E || abs(AC * AC + BC * BC - AB * AB) < E
		|| abs(AB * AB + AC * AC - BC * BC) < E)
	{
		type = "Прямоугольный треугольник\n";
	}
	else
	{
		type = "Тупоугольный треугольник\n";
	}

	return type;
}

std::string Triangle::toString()
{
	return "Сторона AB = " + std::to_string(AB) + "\nСторона BC = " + std::to_string(BC) + "\nСторона AC = " + std::to_string(AC) +
		"\nУгол А = " + std::to_string(angleA) + "\nУгол B = " + std::to_string(angleB) + "\nУгол C = " + std::to_string(angleC) + "\n";
}
