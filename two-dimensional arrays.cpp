//Дана целочисленная прямоугольная матрица.
//1) Найти номер второй строки, в которой чисел, оканчивающихся на 3 более половины;
//2) Удалить строки, содержащие четные максимумы, оставшиеся строки переместить вверх, освободившиеся строки заполнить 0.

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>

using namespace std;


bool isGoodRow(int* begin, int* end, int col, int lastDigit) 
{
	int count = 0;
	int count_row = 0;
	bool result = false;
	for (int* i = begin; i < end; i++)
	{
		if (abs(*i % 10) == lastDigit)
		{
			count++;
		}
	}

	if (count > col / 2)
		result = true;

	return result;
}

//task 1
int number_of_row(int a[][6], int row, int col, int lastDigit)
{
	int index = -1; // number of the second row
	int count_row = 0; // count of the row with count > col/2
	
	int* ptr_end = a[0];
	int i = 0;
	while (count_row < 2 && i < row)
	{
		int* ptr_begin = ptr_end;
		ptr_end = ptr_begin + col;

		if (isGoodRow(ptr_begin, ptr_end, col, lastDigit))
			count_row++;
			
		if (count_row == 2)
			index = i;

		++i;
	}
	return index;
}

void memory_allocation(int**& a, int row, int col)
{
	a = new int* [row];
	for (int i = 0; i < row; i++)
	{
		a[i] = new int[col];
	}
}
void delete_array(int**& a, int row)
{
	for (int i = 0; i < row; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	a = nullptr;
}

int max_in_line(int** a, int row, int col, int n_str)
{
	int max = a[n_str][0];
	
	for (int j = 0; j < col; j++)
	{
		if (a[n_str][j] > max)
		{
			max = a[n_str][j];
		}
	}
	
	return max;
}

void copy_row(int **a, int col, int from, int to)
{
	/*int* tmp = a[to];
	a[to] = a[from];
	a[from] = tmp;*/
	for (int j = 0; j < col; j++)
	{
		a[to][j] = a[from][j];
	}
}

void fill_null(int **&a, int col, int row_n) 
{
	for (int j = 0; j < col; j++)
	{
		a[row_n][j] = 0;
	}
}

//task 2
void delete_rows_with_even_max(int**& a, int row, int col)
{
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		if (max_in_line(a, row, col, i) % 2)
		{
			if (i != count)
				copy_row(a,col, i, count);
			count++;
		}
	}

	for (int i = count; i < row; i++)
	{
		fill_null(a, col, i);
	}


	//bool flag;
	//int count = 0;
	//int max = even_max(a, row, col,2);
	//int* bad_rows = new int[row];
	//for (int i = 0; i < row; i++)
	//{
	//	int j = 0;
	//	flag = false;
	//	while (j < col && !flag)
	//	{
	//		if (a[i][j] == max)
	//		{
	//			//delete[] a[i];
	//			bad_rows[count++] = i;
	//			flag = true;
	//		}
	//		++j;
	//	}
	//}

	//if (count != 0)
	//{
	//	int** new_a = nullptr;
	//	memory_allocation(new_a, row, col);
	//	//fill new array good rows
	//	/*for (int i = 0; i < row - count; i++)
	//	{
	//		new_a[i] = a[i];
	//	}
	//	for (int i = row - count; i < row; i++)
	//	{
	//		for (int j = 0; j < col; j++)
	//		{
	//			new_a[i][j] = 0;
	//		}
	//	}*/
	//	int ind_old = 0, ind_new = 0;
	//	for (int i = 0; i < row; i++)
	//	{
	//		if (bad_rows[ind_old] != i)
	//		{
	//			new_a[ind_new] = a[i];
	//			ind_new++;
	//		}
	//		else
	//		{
	//			ind_old++;
	//		}
	//	}

	//	for (int i = row - count; i < row; i++)
	//	{
	//		for (int j = 0; j < col; j++)
	//		{
	//			new_a[i][j] = 0;
	//		}
	//	}

	//	a = new_a;
	//}

}


template <typename T>
void fill_from_stream(T a, int row, int col, istream& stream = cin)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			stream >> a[i][j];
		}
	}
}

template <typename T>
void fill_random(T a, int row, int col)
{
	srand(GetTickCount64());
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			a[i][j] = rand() % 200 - 100;
		}
	}
}

template <typename T>
void print_array(T a, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}



int task_menu()
{
	int choice = 0;
	do {
		std::cout << "1. Найти номер второй строки, в которой чисел, оканчивающихся на 3 более половины\n";
		std::cout << "2. Удалить строки, содержащие четные максимумы, оставшиеся строки переместить вверх, освободившиеся строки заполнить 0\n";
		std::cout << "3. Завершение работы\n";

		bool isError = false;
		do
		{
			//проверяем подходит ли введенное число в диапазон 
			std::cout << "->";
			std::cin >> choice;
			if (std::cin.fail() || choice < 1 || choice>3)
			{
				isError = true;
				std::cout << "Ошибка ввода,значение должно быть в диапазоне от 1 до 3\n";
				std::cin.clear();
				std::cin.ignore(255, '\n');
			}
			else
				isError = false;
		} while (isError);
		return choice;
	} while (choice != 3);
}

int choice_input_method()
{
	size_t size = 0;
	int result;
	std::cout << "1. Ввод из файла\n";
	std::cout << "2. Ввод с клавиатуры\n";
	std::cout << "3. Генерация случайным образом\n";
	bool isError_p = false;
	do
	{

		std::cout << "->";
		std::cin >> result;
		if (std::cin.fail() || result < 1 || result>3)
		{
			isError_p = true;
			std::cout << "Ошибка ввода,значение должно быть в диапазоне от 1 до 3\n";
			std::cin.clear();
			std::cin.ignore(255, '\n');


		}
		else
			isError_p = false;
	} while (isError_p);
	return result;
}


int main()
{

	SetConsoleOutputCP(1251);
	//размер статического массива
	const int i = 5;
	const int j = 6;

	int input_method = 0;
	int task = 0;
	int row, col;


	/*int** ptr = nullptr;
	memory_allocation(ptr, 3, 3);
	fill_random(ptr, 3, 3);
	print_array(ptr, 3, 3);
	copy_row(ptr, 2, 1);
	print_array(ptr, 3, 3);*/
	//swap(ptr, 2, 1);
	//print_array(ptr, 3, 3);
	//swap(ptr, 2, 1);
	//print_array(ptr, 3, 3);
	//swap(ptr, 0, 1);
	//print_array(ptr, 3, 3);
	//fill_null(ptr, 3, 1);
	//print_array(ptr, 3, 3);



	do
	{
		int** a = nullptr;
		//memory_allocation(a, 2, 3);
		//fill_random(a, 2, 3);
		//int b[i][j];
		//fill_from_stream(b, i, j);
		////fill_random(b, i, j);
		//print_array(b, i, j);
		//cout<<number_of_row(b, 5, 6, 3);


		task = task_menu();
		//input_method = choice_input_method();

		switch (choice_input_method())
		{
		case 1:
		{
			std::ifstream file("C:/Users/Evgeny/source/repos/LR5.6/data.txt");


			if (!file)
				std::cout << "Файл не найден\n";
			else
			{
				file >> row >> col;
				if (task == 1)
				{
					int a[i][j];
					std::cout << "Файл должен содержать >= " << i * j << " элементов\n";
					fill_from_stream(a, i, j, file);
					print_array(a, i, j);

					int result = number_of_row(a, i, j, 3);
					if (result == -1)
						cout << "Такой строки нет\n";
					else
						cout << "Номер строки " <<  result + 1 << '\n';
				}
				else
				{
					std::cout << "Файл должен содержать >= " << row * col << " элементов\n";
					memory_allocation(a, row, col);
					fill_from_stream(a, row, col, file);
					print_array(a, row, col);

					delete_rows_with_even_max(a, row, col);
					cout << "Новый массив \n";
					print_array(a, row, col);
				}

				file.close();
			}
			break;
		}
		case 2:
			if (task == 1)
			{
				int a[i][j];
				std::cout << "Введите " << i * j << " элементов\n";
				fill_from_stream(a, i, j, cin);
				print_array(a, i, j);

				int result = number_of_row(a, i, j, 3);
				if (result == -1)
					cout << "Такой строки нет\n";
				else
					cout << "Номер строки " <<  result + 1 << '\n';
			}
			else
			{
				std::cout << "Введите количество строк и столбцов\n";
				std::cin >> row >> col;
				std::cout << "Введите " << row * col << " элементов\n";

				memory_allocation(a, row, col);
				fill_from_stream(a, row, col, cin);
				//print_array(a, row, col);

				delete_rows_with_even_max(a, row, col);
				cout << "Новый массив \n";
				print_array(a, row, col);
			}

			break;

		case 3:

			if (task == 1)
			{
				int a[i][j];
				std::cout << "Введите " << i * j << " элементов\n";
				fill_random(a, i, j);
				print_array(a, i, j);

				int result = number_of_row(a, i, j, 3);
				if (result == -1)
					cout << "Такой строки нет\n";
				else
					cout << "Номер строки " <<  result + 1 << '\n';
			}
			else
			{
				std::cout << "Введите количество строк и столбцов\n";
				std::cin >> row >> col;
				memory_allocation(a, row, col);
				fill_random(a, row, col);
				print_array(a, row, col);

				delete_rows_with_even_max(a, row, col);
				cout << "Новый массив \n";
				print_array(a, row, col);
			}

			break;
		}
		if (a)
			delete_array(a, row);

		char isExit;
		std::cout << "Завершить работу? (Y-да, любой другой знак-нет):\n";
		std::cin >> isExit;
		if (isExit == 'Y' || isExit == 'y')
			task = 3;
	} while (task != 3);

}