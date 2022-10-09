#pragma once

class Vector
{
private:
	int n;
	double* ptr;
	double* memory_alloc(int n);
public:
	Vector();
	//Vector(int l, ...);
	Vector(int l);
	Vector(Vector& vec);
	void set_vector(std::istream& stream);
	//void set_vector(double* values);
	std::string ToString();
	int get_size();
	double get_length();
	//~Vector();
	Vector operator + (const Vector& vec);
	Vector operator - (const Vector& vec);
	Vector operator * (int multiplayer);
	Vector operator / (int divider);
	Vector& operator = (const Vector& vec);
	int compare( Vector vec);
	friend std::ostream& operator << (std::ostream& stream, const Vector& vec);
	friend std::istream& operator >> (std::istream& stream, const Vector& vec);
};
