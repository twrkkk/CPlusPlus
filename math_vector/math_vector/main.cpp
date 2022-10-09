#include <iostream>
#include "math_vector.h"

using std::cin;
using std::cout;

int main()
{
	setlocale(0,"Russian");
	cout << "Enter size" << '\n';
	int size;
	cin >> size;
	Vector vec(size), vec2(size);
	cout << "Enter " << size << " coord" << '\n';
	cin >> vec;
	cout << vec;
	cout << "Enter " << size << " coord" << '\n';
	cin >> vec2;
	cout << vec2;

	Vector vec3;
	vec3 = vec + vec2;
	cout << "'\n'Sum " << '(' << vec << ')' << " and " << '(' << vec2 << ')' << " = ";
	cout << '(' << vec3 << ')';

	cout << "multiplication by 2" << '\n';
	vec3 = vec3 * 2;
	cout << vec3;

	cout << "division by 3" << '\n';
	vec3 = vec3 / 3;
	cout << vec3;

	cout << "subtraction first and second Vector" << '\n';
	vec3 = vec - vec2;
	cout << vec3;

}