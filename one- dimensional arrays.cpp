// В одномерном массиве, состоящем из n целых элементов, вычислить:
// 1) количество нечетных элементов массива, оканчивающихся на 7;
// 2) сумму элементов массива, расположенных до последнего положительного элемента.
// 3) упорядочить элементы массива по убыванию методом простых вставок.



#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstdlib>

using namespace std;

int* memory_allocation(int size)
{
	return new int[size];
}

void free_memory(int* &a)
{
	delete[] a;
	a = nullptr;
}

void fill_random(int* a, int size)
{
	srand(GetTickCount64());
	for (int i = 0; i < size; ++i)
		a[i] = rand() % 200 - 100;
}

void fill_from_stream(int* a, int size, istream& stream = cin)
{
	for (int i = 0; i < size; ++i)
		stream >> a[i];
}

void print_array(const int* a, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << *(a + i) << ' ';
	}
	cout << '\n';
}

int count_of_numbers(const int* a, int size, int number)
{
	int count = 0;
	for (int i = 0; i < size; ++i)
		if (abs(*(a + i) % 10) == number)
			count++;
	return count;
}

int sum_of_numbers_before_positive(const int* a, int index_last_positive)
{
	int sum = 0;
	for (int i = 0; i < index_last_positive; ++i)//сумма до последнего положительного
	{
		sum += *(a + i);
	}
	return sum;
}

int index_last_positive_elem(const int* a, int size)
{
	int index = -1;
	/*for (int i = size - 1; i >= 0; --i)
		if (*(a + i) >= 0)
		{
			index = i;
			return index;
		}
	return index;*/

	int i = size - 1;
	while (index == -1 && i >= 0)
	{
		if (*(a + i) > 0)
		{
			index = i;
		}
		--i;
	}
	return index;
}

void sort(int* a, int size)
{
	/*for (int i = 1; i < size; ++i)
		for (int j = i; j > 0 && *(a + j - 1) < *(a + j); --j)
		{
			int tmp = *(a + j - 1);
			*(a + j - 1) = *(a + j);
			*(a + j) = tmp;
		}*/
	int tmp = 0;
	int j = 0;
	for (int i = 1; i < size; ++i)
	{
		if (*(a + i) > *(a + i - 1))
		{

			tmp = *(a + i);
			j = i - 1;
			while (j >= 0 && *(a + j) < tmp)
			{
				*(a + j + 1) = *(a + j);
				j--;
			}
				*(a + j + 1) = tmp;
		}
	}

}

int task_menu()
{
	int choice = 0;
	int wrong_count = 0;
	do {
		std::cout << "1. Вычислить количество нечетных элементов массива, оканчивающихся на 7.\n";
		std::cout << "2. Вычислить сумму элементов массива, расположенных до последнего положительного элемента\n";
		std::cout << "3. Упорядочить элементы массива по убыванию методом простых вставок\n";
		std::cout << "4. Завершить работу\n";

		bool isError = false;
		do
		{
			//проверяем подходит ли введенное число в диапазон 
			std::cout << "->";
			std::cin >> choice;
			if (std::cin.fail() || choice < 1 || choice>4)
			{
				if (wrong_count != 2)
				{
					isError = true;
					wrong_count++;
					std::cout << "Ошибка ввода,значение должно быть в диапазоне от 1 до 4\n";
					std::cout << "Осталось попыток " << 3 - wrong_count << '\n';
					std::cin.clear();
					std::cin.ignore(255, '\n');
				}
				else
					exit(0);
			}
			else
				isError = false;
		} while (isError );
		return choice;
	} while (choice != 4 && wrong_count != 3);
}

int choice_input_method()
{
	size_t size = 0;
	int result;
	int wrong_count = 0;
	std::cout << "1. Ввод из файла\n";
	std::cout << "2. Ввод с клавиатуры\n";
	std::cout << "3. Генерация случайным образом\n";
	bool isError_p = false;
	do
	{
		//проверяем подходит ли введенное число в диапазон 
		std::cout << "->";
		std::cin >> result;
		if (std::cin.fail() || result < 1 || result>3)
		{
			if (wrong_count != 2)
			{
				isError_p = true;
				wrong_count++;
				std::cout << "Ошибка ввода,значение должно быть в диапазоне от 1 до 3\n";
				std::cout << "Осталось попыток " << 3 - wrong_count << '\n';
				std::cin.clear();
				std::cin.ignore(255, '\n');
			}
			else
				exit(0);
		}
		else
			isError_p = false;
	} while (isError_p);
	return result;
}

int main()
{
	SetConsoleOutputCP(1251);
	int input_method = 0;
	do 
	{
		int task = task_menu();
		input_method = choice_input_method();
		int size = 0;
		int* a = nullptr;

		switch (input_method)
		{
		case 1:
		{	
			std::ifstream file("C:/Users/Evgeny/source/repos/LR4.21/data.txt");


			if (!file)
				std::cout << "Файл не найден\n";
			else
			{
				file >> size;
				a = memory_allocation(size);
				fill_from_stream(a, size, file);
				print_array(a, size);

				file.close();
			}
			break; 
		}
		case 2:
			std::cout << "Введите количество элементов\n";
			std::cin >> size;
			std::cout << "Введите " << size << " элементов\n";
			a = memory_allocation(size);
			fill_from_stream(a, size, cin);
		
			break;

		case 3:
			std::cout << "Введите количество элементов\n";
			std::cin >> size;
			a = memory_allocation(size);
			fill_random(a, size);
			print_array(a, size);
			break;
		}
		switch (task)
		{
		case 1:
			cout<< "Кол-во элементов, оканчивающихся на 7 = " << count_of_numbers(a, size, 7) << '\n';
			
			break;
		case 2:
		{

			int index = index_last_positive_elem(a, size);
			if (index != -1)
				cout << "Сумма до последнего положительного = " << sum_of_numbers_before_positive(a, index) << '\n';
			else
				cout << "Такого элемента нет " << '\n';
			break; 
		}
		case 3:
			sort(a, size);
			cout << "Отсортированный массив: " << '\n';
			print_array(a, size);
			
			break;
		}
		free_memory(a);

		char isExit;
		std::cout << "Завершить работу? (Y-да, любой другой знак-нет):\n";
		std::cin >> isExit;
		if (isExit == 'Y' || isExit == 'y')
			input_method = 4;
	} while (input_method != 4);

}