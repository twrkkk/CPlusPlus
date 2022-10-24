#include <iostream>

int K = 0;
char Letters[] = "абвгдежзиклмно";
int Count[sizeof Letters] = { 0 };


void add_letter(char* s, int n)
{
    for (int i = 0; i < sizeof(Letters) - 1; i++) {
        if (Count[i] <= K - 3)
        {
            s[n] = Letters[i];
            if (n == K - 1) std::cout << s << std::endl;
            else {
                ++Count[i];
                add_letter(s, n + 1);
                --Count[i];
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите длину слова " << '\n';
    std::cin >> K;

    char* s = new char[K + 1]; s[K] = '\0';
    add_letter(s, 0);
}