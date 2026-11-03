#include <iostream>
#include <Windows.h>
#include "Lab6Dll.h"

using namespace std;
using namespace Lab6Hierarchy;

int main()
{
    // Виправлення відображення української мови в консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== Лабораторна робота № 6 (Варіант: Клас Money) ===" << endl << endl;

    // Створення об'єктів грошових сум
    Money m1(150, 75); // 150 грн 75 коп
    Money m2(45, 50);  // 45 грн 50 коп

    cout << "Сума 1: "; m1.display(); cout << endl;
    cout << "Сума 2: "; m2.display(); cout << endl << endl;

    // Додавання та віднімання
    Money sum = m1.add(m2);
    cout << "Результат додавання (Сума 1 + Сума 2): "; sum.display(); cout << endl;

    Money diff = m1.subtract(m2);
    cout << "Результат віднімання (Сума 1 - Сума 2): "; diff.display(); cout << endl << endl;

    // Ділення суми на суму
    double ratio = m1.divideByMoney(m2);
    cout << "Ділення сум (Сума 1 / Сума 2): у " << ratio << " разів більша" << endl << endl;

    // Множення та ділення на дробове число
    double factor = 2.5;
    Money prod = m2.multiplyByNumber(factor);
    cout << "Множення на дробове число (Сума 2 * " << factor << "): "; prod.display(); cout << endl;

    Money divNum = m1.divideByNumber(factor);
    cout << "Ділення на дробове число (Сума 1 / " << factor << "): "; divNum.display(); cout << endl << endl;

    // Операції порівняння
    cout << "=== Перевірка операцій порівняння ===" << endl;
    cout << "Сума 1 == Сума 2? " << (m1.isEqual(m2) ? "Так" : "Ні") << endl;
    cout << "Сума 1 > Сума 2? " << (m1.isGreater(m2) ? "Так" : "Ні") << endl;
    cout << "Сума 1 < Сума 2? " << (m1.isLess(m2) ? "Так" : "Ні") << endl;

    cout << "\nНатисніть Enter для виходу...";
    cin.get();

    return 0;
}
