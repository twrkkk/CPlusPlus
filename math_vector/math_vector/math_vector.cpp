
#include <iostream>
#include "math_vector.h"
#include <string>
#include <algorithm>


Vector::Vector() 
{
	n = 3;
	ptr = memory_alloc(3);
};
//Vector::Vector(int l, ...)
//{
//	n = l;
//	ptr = memory_alloc(l);
//	va_list args;
//	va_start(args, l);
//
//	while (l)
//	{
//		ptr[n-l] = va_arg(args, double);
//		--l;
//	}
//	va_end(args);
//}
Vector::Vector(int l)
{
	n = l;
	ptr = memory_alloc(n);
}
Vector::Vector(Vector& vec)
{	
	int size = vec.get_size();
	n = size;
	ptr = memory_alloc(size);
	for (int i = 0; i < size; i++)
	{
		ptr[i] = vec.ptr[i];
	}
}
void Vector::set_vector(std::istream& stream)
{
	for (int i = 0; i < n; i++)
	{
		stream >> ptr[i];
	}
}
//void Vector::set_vector(double* values)
//{
//	ptr = values;
//}
double* Vector::memory_alloc(int n)
{
	//if(ptr) delete ptr;
	return new double[n];
}

std::string Vector::ToString()
{
	std::string result;
	for (int i = 0; i < n; i++)
	{
		result += std::to_string (ptr[i]) + ' ';
	}
	result += '\n';
	return result;
}

int Vector::get_size()
{
	return n;
}

double Vector::get_length()
{
	double result = 0.;
	for (int i = 0; i < n; i++)
	{
		result += ptr[i] * ptr[i];
	}
	return sqrt(result);
}

//Vector::~Vector()
//{
//	delete ptr;
//}

Vector Vector::operator + (const Vector& vec)
{
	int size = n;
	Vector tmp(size);
	for (int i = 0; i < size; i++)
	{
		tmp.ptr[i] = ptr[i] + vec.ptr[i];
	}
	return tmp;

}

Vector Vector::operator - (const Vector& vec)
{
	int size = n;
	Vector tmp(size);
	for (int i = 0; i < size; i++)
	{
		tmp.ptr[i] = ptr[i] - vec.ptr[i];
	}
	return tmp;

}
Vector Vector::operator * (int multiplayer)
{
	for (int i = 0; i < n; i++)
	{
		ptr[i] *= multiplayer;
	}
	return *this;
}

Vector Vector::operator / (int divider)
{
	for (int i = 0; i < n; i++)
	{
		ptr[i] /= divider;
	}
	return *this;
}

Vector& Vector::operator = (const Vector& vec)
{
	int size = n;
	for (int i = 0; i < size; i++)
	{
		ptr[i] = vec.ptr[i];
	}
	return *this;

}

int Vector::compare( Vector vec)
{
	int result = 0;
	double len_1 = get_length();
	double len_2 = vec.get_length();
	
	if (len_1 > len_2)
		result = 1;
	else if (len_1 < len_2)
		result = -1;

	return result;
}

std::ostream& operator << (std::ostream& stream, const Vector& vec)
{
	int size = vec.n;
	for (int i = 0; i < size; i++)
	{
		stream << vec.ptr[i] << ' ';
	}
	stream << '\n';
	return stream;
}

std::istream& operator >> (std::istream& stream, const Vector& vec)
{
	int size = vec.n;
	for (int i = 0; i < size; i++)
	{
		stream >> vec.ptr[i];
	}
	return stream;
}