#include <iostream>

int Length = 0;
char Letters[] = "абвгдежзиклмно";

void add_letter(char* s, int n, int* Count)
{
    for (int i = 0; i < sizeof(Letters) - 1; i++) {
        if (Count[i] == 0) continue;
        else {
            s[n] = Letters[i];
            if (n == Length - 1) std::cout << s << '\n';
            else 
            {
                --Count[i];
                add_letter(s, n + 1, Count);
                ++Count[i];
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите длину слова " << '\n';
    std::cin >> Length;

    int* Count = new int[Length + 1];
    for (int i = 0; i < Length; i++)
        Count[i] = Length - 2;

    char *s = new char[Length +1]; s[Length] = 0;
    add_letter(s, 0, Count);
}
