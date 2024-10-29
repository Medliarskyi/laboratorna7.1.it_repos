#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Оголошення функцій
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел
    int Low = -12;
    int High = 37;
    int rowCount = 7; // Кількість рядків
    int colCount = 9; // Кількість стовпців

    // Динамічне виділення пам'яті для двовимірного масиву
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // Створення масиву з випадковими значеннями
    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount); // Виведення масиву

    // Сортування масиву
    Sort(a, rowCount, colCount);
    Print(a, rowCount, colCount); // Виведення відсортованого масиву

    int S = 0; // Сума позитивних елементів
    int k = 0; // Кількість позитивних елементів
    Calc(a, rowCount, colCount, S, k); // Обчислення S та k
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    Print(a, rowCount, colCount); // Виведення масиву після обчислень

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

// Функція для створення масиву з випадковими значеннями
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Функція для виведення масиву
void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j]; // Вивід з фіксованою шириною
        cout << endl;
    }
    cout << endl;
}

// Функція для сортування масиву
void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
    {
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
        {
            // Сортування за першим, другим та третім елементами рядка
            if ((a[i1][0] < a[i1 + 1][0]) ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1]) ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && (colCount > 3 && a[i1][3] > a[i1 + 1][3])))
            {
                Change(a, i1, i1 + 1, colCount); // Зміна рядків
            }
        }
    }
}

// Функція для обміну рядками
void Change(int** a, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)
    {
        tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

// Функція для обчислення суми та кількості позитивних елементів
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (a[i][j] > 0 && (a[i][j] % 3 != 0)) // Умова для позитивних елементів
            {
                S += a[i][j]; // Додавання до суми
                k++; // Збільшення лічильника
                a[i][j] = 0; // Замінити елемент на 0
            }
}