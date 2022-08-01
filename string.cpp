// Файл inp.txt содержит текст, состоящий из нескольких строк. Каждая строка состоит из
// слов, разделенных любым количеством пробелов (пробелы могут стоять в начале и в конце
// строки), количество слов не более 35. Слово – последовательность латинских букв
// (количество букв в слове не превышает 15). Другие символы, отличные от латинских букв и
// пробелов, в файле отсутствуют.
// Требуется создать файл out.txt, в который записать слова, содержащие подстроку ‘on’ или
// ‘no’ (каждое слово расположить на отдельной строке). Если таких слов несколько, вывести их в
// алфавитном порядке, а если таких слов нет, в файл следует записать ‘NO’

#include <iostream>
#include <fstream>
#include <string>
const int n = 30; // количество слов
const int m = 15; // длина слова
const std::string token(" ,.!:;-\n");
void create_matrix(std::ifstream& file, std::string matrix[], int& row, std::string sub1, std::string sub2)
{
	auto skip_token = [&](char& c)
	{
		while (!file.eof() && token.find(c) != std::string::npos)
			c = file.get();

	};
	auto read_word = [&](char& c)->std::string
	{
		std::string result = "";
		result.reserve(m);
		while (!file.eof() && token.find(c) == std::string::npos)
		{
			result += c;
			c = file.get();
		}
		return result;
	};
	row = 0;
	char c = file.get();
	while (!file.eof() && row < n)
	{
		skip_token(c);
		if (token.find(c) == std::string::npos)
		{
			matrix[row] = read_word(c);
			if (matrix[row].length() >= sub1.length() && matrix[row].find(sub1) != 0 ||
				matrix[row].length() >= sub2.length() && matrix[row].find(sub2) != 0)
				++row;

		}
	}
}
void print_matrix(std::string matrix[], int row, const char* message)
{
	std::cout << message << '\n';
	for (int i = 0; i < row; ++i)
		std::cout << '-' << matrix[i] << '-' << '\n';

}
void sorting(std::string matrix[], int row)
{
	for (int count = row; count > 1; --count)
		for (int i = 0; i < count - 1; ++i)
			if (matrix[i] > matrix[i + 1])
				matrix[i].swap(matrix[i + 1]);

}

int main()
{
	std::ifstream file("input.txt");
	if (!file)
	{
		std::cout << "File error\n";
	}
	else
	{
		std::string matrix[n];
		int row = 0;
		/*std::string end;
		std::cout << "Input the ending:\n";
		std::cin >> end; std::cin.ignore();*/
		std::string sub1 = "no";
		std::string sub2 = "on";
		create_matrix(file, matrix, row, sub1, sub2);
		sorting(matrix, row);
		print_matrix(matrix, row, "Sorting matrix:");
		file.close();
	}
	std::cin.get();
	return 0;
}