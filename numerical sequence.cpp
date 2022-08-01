// Дана последовательность из N целых чисел.
// Предусмотреть выбор пользователем варианта создания последовательности:
// – ввод из файла;
// – ввод с клавиатуры;
// – генерация случайным образом

// 1. Найти количество максимальных элементов.
// 2. Найти номер третьего числа кратного 5.

#include<iostream>
#include<fstream>
#include<Windows.h>
#include<sstream>

int task_menu();
int choice_input_method(int choice);
int task_1(int param, size_t size, std::istream& stream = std::cin);
int task_2(int param, size_t size, std::istream& stream = std::cin);
int input(int param, std::istream& stream = std::cin);

int main()
{
	int result_1 = 0;
	int result_2 = 0;
	SetConsoleOutputCP(1251);
	srand(GetTickCount64());
	int task_number = 0;
	do
	{
		task_number = task_menu();
		if (task_number != 3)
		{
			if (task_number == 1)//решение первой задачи
			{
				result_1 = choice_input_method(task_number);
				std::cout << "Количество максимальных элементов = " << result_1 << ".\n";
			}
			else //решение второй задачи
					
			{
				result_2 = choice_input_method(task_number);
				if (result_2 == -1)
					std::cout << "Такого элемента нет.\n";
				else
					std::cout << result_2+1 << ".\n";
			}

			char isExit;
			std::cout << "Завершить работу? (Y-да, любой другой знак-нет):\n";
			std::cin >> isExit;
			if (isExit == 'Y' || isExit == 'y')
				task_number = 3;
		}
	} while (task_number != 3);
	
}


int task_menu()
{
	int choice = 0;
	do {
		std::cout << "1. Найти количество максимальных элементов.\n";
		std::cout << "2. Найти номер третьего числа кратного 5.\n";
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
int choice_input_method(int choice)
{
	size_t size = 0;
	int result;
	int answer;
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
			isError_p = true;
			std::cout << "Ошибка ввода,значение должно быть в диапазоне от 1 до 3\n";
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else
			isError_p = false;
	} while (isError_p);
	switch (result)
	{
		{case 1:
			std::ifstream file("C:/Users/Evgeny/source/repos/ConsoleApplication6/data.txt");
			
			
			if (!file)
				std::cout << "Файл не найден\n";
			else
			{
				file >> size;
				if (choice == 1)
					answer = task_1(1, size, file);
				else
					answer = task_2(1, size, file);

				file.close();
			}
			break;
		}
		case 2:
			std::cout << "Введите количество элементов\n";
			std::cin >> size;
			std::cout << "Введите " << size << " элементов\n";
			if (choice == 1)
				answer = task_1(1, size);
			else
				answer = task_2(1, size);
			break;

		case 3:
			std::cout << "Введите количество элементов\n";
			std::cin >> size;
			if (choice == 1)
				answer = task_1(0, size);
			else
				answer = task_2(0, size);
			break;
	}
	return answer;
}
int task_1(int param, size_t size, std::istream& stream)
{
	int max_elem = input(param, stream);
	int max_count = 1;
	int curr_count = 0;
	for (size_t i = 1; i < size; i++)
	{
		int curr_elem = input(param, stream);
		if (curr_elem > max_elem)
		{
			max_elem = curr_elem;
		
			max_count = 1;
		}
		else if (curr_elem == max_elem)
		{
			max_count++;
			//max_count = max(max_count, curr_count);
		}
	}
	
	return max_count;
	//result_1 = max_count;
	std::cout << "\n";
}

int task_2(int param, size_t size, std::istream& stream)
{
	int result = -1;
	int count = 0;
	size_t i = 0;

	while (count != 3 && i < size)
	{
		int curr_elem = input(param, stream);
		//if (curr_elem % 5 == 0 && count < 3) // делится на 5 
		//	count++;
		//else if (count == 3) //нашлось три элемента кратных 5
		//{
		//	result_2 = i + 1;
		//	break;
		//}

		if (curr_elem % 5 == 0)
		{
			count++;
		}
		i++;
	}
	if (count == 3)
		result = i-1;

return result;
	//std::cout << "\n";
	//return -1;
}

int input(int param, std::istream& stream)
{
	int x = 0;
	if (param)
		stream >> x;
	else
	{
		x = rand() % 100;
		std::cout << x << ' ';
	}
	return x;
}