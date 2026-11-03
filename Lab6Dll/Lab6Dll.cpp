#include "pch.h"
#include "Lab6Dll.h"
#include <iostream>
#include <iomanip>
#include <cmath>

namespace Lab6Hierarchy
{
    void Money::normalize()
    {
        long total_kopecks = hryvnia * 100 + (int)kopeck;
        if (total_kopecks < 0)
        {
            hryvnia = 0;
            kopeck = 0;
        }
        else
        {
            hryvnia = total_kopecks / 100;
            kopeck = (unsigned char)(total_kopecks % 100);
        }
    }

    Money::Money() : hryvnia(0), kopeck(0) {}

    Money::Money(long h, int k)
    {
        hryvnia = h;
        if (k < 0) k = 0;
        hryvnia += k / 100;
        kopeck = (unsigned char)(k % 100);
        normalize();
    }

    void Money::display() const
    {
        // Виведення з комою, копійки завжди двоцифрові (наприклад, 5,06 або 10,50)
        std::cout << hryvnia << "," << std::setw(2) << std::setfill('0') << (int)kopeck << " грн.";
    }

    Money Money::add(const Money& other) const
    {
        long h = this->hryvnia + other.hryvnia;
        int k = (int)this->kopeck + (int)other.kopeck;
        return Money(h, k);
    }

    Money Money::subtract(const Money& other) const
    {
        long total1 = this->hryvnia * 100 + (int)this->kopeck;
        long total2 = other.hryvnia * 100 + (int)other.kopeck;
        long diff = total1 - total2;
        if (diff < 0) return Money(0, 0);
        return Money(diff / 100, diff % 100);
    }

    double Money::divideByMoney(const Money& other) const
    {
        double total1 = this->hryvnia + (int)this->kopeck / 100.0;
        double total2 = other.hryvnia + (int)other.kopeck / 100.0;
        if (total2 == 0.0) return 0.0;
        return total1 / total2;
    }

    Money Money::divideByNumber(double number) const
    {
        if (number == 0.0) return Money(0, 0);
        double total = (this->hryvnia + (int)this->kopeck / 100.0) / number;
        long h = (long)total;
        int k = std::round((total - h) * 100);
        return Money(h, k);
    }

    Money Money::multiplyByNumber(double number) const
    {
        double total = (this->hryvnia + (int)this->kopeck / 100.0) * number;
        long h = (long)total;
        int k = std::round((total - h) * 100);
        return Money(h, k);
    }

    bool Money::isEqual(const Money& other) const
    {
        return (this->hryvnia == other.hryvnia && (int)this->kopeck == (int)other.kopeck);
    }

    bool Money::isGreater(const Money& other) const
    {
        long t1 = this->hryvnia * 100 + (int)this->kopeck;
        long t2 = other.hryvnia * 100 + (int)other.kopeck;
        return t1 > t2;
    }

    bool Money::isLess(const Money& other) const
    {
        long t1 = this->hryvnia * 100 + (int)this->kopeck;
        long t2 = other.hryvnia * 100 + (int)other.kopeck;
        return t1 < t2;
    }
}
