#include "pch.h"
#include <iostream>
#include "Lesson9Header.h"


class Fraction0
{
private:
    int m_num;
    int m_dom;

public:
    Fraction0(int num, int dom) { m_num = num; m_dom = dom; }

    void print()
    {
        std::cout << m_num << "\\" << m_dom << '\n';
    }
};

class Fraction1
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    Fraction1(int numerator = 0, int denominator = 1) :
        m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

void lesson92quiz()
{
    /*Question #1

    a) Write a class named Fraction that has a integer 
    numerator and denominator member. 
    Write a print() function that prints out the fraction.
    
    */

    Fraction0 f10{ 1, 4 };
    f10.print();

    Fraction0 f20{ 1, 2 };
    f20.print();

    Fraction1 f11{ 2, 6 };
    f11.print();

    Fraction1 f21{ 1, 3 };
    f21.print();
}

int main()
{

    lesson92quiz();

    //overloading_arithmetic_operators_using_friend_functions();
    //operator_overloading();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
