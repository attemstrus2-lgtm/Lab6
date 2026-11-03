#pragma once

#ifdef LAB6DLL_EXPORTS
#define LAB6DLL_API __declspec(dllexport)
#else
#define LAB6DLL_API __declspec(dllimport)
#endif

namespace Lab6Hierarchy
{
    class LAB6DLL_API Money
    {
    private:
        long hryvnia;
        unsigned char kopeck; // зберігає число від 0 до 99

        // Допоміжний метод для нормалізації (наприклад, якщо копійок стало >= 100 або < 0)
        void normalize();

    public:
        // Конструктори
        Money();
        Money(long h, int k);

        // Метод виведення
        void display() const;

        // Операції додавання та віднімання сум
        Money add(const Money& other) const;
        Money subtract(const Money& other) const;

        // Ділення суми на суму (повертає дробове число — у скільки разів одна сума більша за іншу)
        double divideByMoney(const Money& other) const;

        // Ділення та множення суми на дробове число
        Money divideByNumber(double number) const;
        Money multiplyByNumber(double number) const;

        // Операції порівняння
        bool isEqual(const Money& other) const;
        bool isGreater(const Money& other) const;
        bool isLess(const Money& other) const;
    };
}
