// Файл inp.txt содержит текст, состоящий из нескольких строк. Каждая строка состоит из
// слов, разделенных любым количеством пробелов (пробелы могут стоять в начале и в конце
// строки), количество слов не более 35. Слово – последовательность латинских букв
// (количество букв в слове не превышает 15). Другие символы, отличные от латинских букв и
// пробелов, в файле отсутствуют.
// Требуется создать файл out.txt, в который записать слова, содержащие подстроку ‘on’ или
// ‘no’ (каждое слово расположить на отдельной строке). Если таких слов несколько, вывести их в
// алфавитном порядке, а если таких слов нет, в файл следует записать ‘NO’


#include <iostream>
#include<fstream>
#include <cstring>
#include<string.h>

using namespace std;

const int m = 15, n = 35;

void copyWord(char to[], char from[])
{
    int len = strlen(from);
    for (int i = 0; from[i] != -52; i++)
        to[i] = from[i];
}

bool containsSubstring(char word[], char substring[])
{
    int len_word = strlen(word);
    int len_s = strlen(substring);
    bool flag = false; // true if substring is found
    int pos = -1;
    for (int i = 0; !flag && i < len_word; i++)
    {
        if (word[i] == substring[0])
        {
            pos = i;
            bool subisfound = true;
            for (int j = 0; subisfound && j < len_s; j++)
                if (word[j+pos] != substring[j])
                    subisfound = false;
            if (subisfound)
            flag = true;
        }
    }
    return flag;
}

void create_matrix(std::ifstream& file, char matrix[][m], int& row, char substring1[], char substring2[])
{
    row = 0;
    char* context = 0;
    while (!file.eof() && row < n)
    {
        char word[m];
        file >> word;
        strtok_s(word, " ,;:.-/?", &context);
        if (containsSubstring(word, substring1) || containsSubstring(word, substring2))
        {
            //matrix[row] = word;
            copyWord(matrix[row], word);
            ++row;
        }
    }
}

void print_matrix(char matrix[][m], int row, const char* message)
{
    std::cout << message << '\n';
    for (int i = 0; i < row; ++i)
    {
        std::cout << '-' << matrix[i] << '-' << '\n';
        std::cout << "------------------------\n";
    }
}

int compare(char word1[], char word2[])
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    auto signl = [](int x) {return x == 0 ? 0 : x / abs(x); };
    int len = len1 < len2 ? len1 : len2;
    int result, i = 0;
    while (i < len && word1[i] == word2[i])
        i++;
    if (i < len)
        result = signl(word1[i] - word2[i]);
    else
        result = signl(len1 - len2);
    return result;
}

template <typename T>
void swap_(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

void swapRows(char word1[], char word2[])
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int len = len1 > len2 ? len1 : len2;
    for (int i = 0; i < len; i++)
        swap_(word1[i], word2[i]);
}

void sorting(char matrix[][m], int row)
{
    for (int count = row; count > 1; count--)
        for (int i = 0; i < count - 1; i++)
            if (compare(matrix[i], matrix[i + 1]) > 0)
            {
                swapRows(matrix[i], matrix[i + 1]);
            }
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
    char matrix[n][m];
    int row = 0;
    char substring1[] = "no";
    char substring2[] = "on";
    create_matrix(file, matrix, row, substring1, substring2);
    print_matrix(matrix, row, "Original matrix:");

    ofstream output("output.txt");
    sorting(matrix, row);
    print_matrix(matrix, row, "after sort");
    file.close();
}

    std::cin.get();

    return 0;

}

