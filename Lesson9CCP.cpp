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

    // We don't want to pass by value, because copying is slow.
    // We can't and shouldn't pass by non-const reference, because then
    // our functions wouldn't work with r-values.
    friend Fraction1 operator*(const Fraction1& f1, const Fraction1& f2);
    friend Fraction1 operator*(const Fraction1& f1, int value);
    friend Fraction1 operator*(int value, const Fraction1& f1);
};

Fraction1 operator*(const Fraction1& f1, const Fraction1& f2)
{
    return { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction1 operator*(const Fraction1& f1, int value)
{
    return { f1.m_numerator * value, f1.m_denominator };
}

Fraction1 operator*(int value, const Fraction1& f1)
{
    return { f1.m_numerator * value, f1.m_denominator };
}

////////////////////////////////////////////////////////////////////////////////

class Fraction44
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction44(int numerator = 0, int denominator = 1) :
        m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    // We don't want to pass by value, because copying is slow.
    // We can't and shouldn't pass by non-const reference, because then
    // our functions wouldn't work with r-values.
    friend Fraction44 operator*(const Fraction44& f1, const Fraction44& f2);
    //friend Fraction operator*(const Fraction& f1, int value);
    //friend Fraction operator*(int value, const Fraction& f1);

    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

Fraction44 operator*(const Fraction44& f1, const Fraction44& f2)
{
    return { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

//Fraction operator*(const Fraction& f1, int value)
//{
//    return { f1.m_numerator * value, f1.m_denominator };
//}

//Fraction operator*(int value, const Fraction& f1)
//{
//    return { f1.m_numerator * value, f1.m_denominator };
//}

// This version of the Fraction class auto-reduces fractions
class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator{ numerator }, m_denominator{ denominator }
    {
        // We put reduce() in the constructor to ensure any fractions we make get reduced!
        // Since all of the overloaded operators create new Fractions, we can guarantee this will get called here
        reduce();
    }

    // We'll make gcd static so that it can be part of class Fraction without requiring an object of type Fraction to use
    static int gcd(int a, int b)
    {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }

    void reduce()
    {
        if (m_numerator != 0 && m_denominator != 0)
        {
            int gcd{ Fraction::gcd(m_numerator, m_denominator) };
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int value);
    friend Fraction operator*(int value, const Fraction& f1);

    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f1, int value)
{
    return { f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f1)
{
    return { f1.m_numerator * value, f1.m_denominator };
}

////////////////////////////////////////////////////////////////////////////////

void lesson92quiz()
{
    /*Question #1

    a) Write a class named Fraction that has a integer 
    numerator and denominator member. 
    Write a print() function that prints out the fraction.
    
    */

    Fraction0 f19{ 1, 4 };
    f19.print();

    Fraction0 f29{ 1, 2 };
    f29.print();

    Fraction1 f39{ 2, 6 };
    f39.print();

    Fraction1 f49{ 1, 3 };
    f49.print();

    std::cout << "------------------" << '\n';

    /*b) Add overloaded multiplication operators to handle multiplication 
    between a Fraction and integer, 
    and between two Fractions. 
    Use the friend function method.

    Hint: To multiply two fractions, 
    first multiply the two numerators together, 
    and then multiply the two denominators together. 
    To multiply a fraction and an integer, 
    multiply the numerator of the fraction by the integer 
    and leave the denominator alone.
    
    */

    Fraction1 f11{ 2, 5 };
    f11.print();

    Fraction1 f21{ 3, 8 };
    f21.print();

    Fraction1 f31{ f11 * f21 };
    f31.print();

    Fraction1 f41{ f11 * 2 };
    f41.print();

    Fraction1 f51{ 2 * f21 };  
    f51.print();

    Fraction1 f61{ Fraction1{1, 2} *Fraction1{2, 3} *Fraction1{3, 4} };
    f61.print();

    std::cout << "------------------" << '\n';

    /*c) Why does the program continue to work correctly if we remove
    the operators for integer multiplication from the previous solution?

    // We can remove these operators, and the program continues to work

    Fraction operator*(const Fraction &f1, int value);
    Fraction operator*(int value, const Fraction &f1);

    We still have

    Fraction operator*(const Fraction &f1, const Fraction &f2);

    The Fraction(int, int) constructor will be used to construct a new Fraction
    from 2. This new Fraction is then multiplied by f2 using the 
    Fraction * Fraction operator.

    The additional conversion from 2 to a Fraction slows down the program,
    making it slower than the implementation with overloaded operators for 
    integer multiplication.
    
    */

    Fraction44 f144{ 2, 5 };
    f144.print();

    Fraction44 f244{ 3, 8 };
    f244.print();

    Fraction44 f344{ f144 * f244 };
    f344.print();

    Fraction44 f444{ f144 * 2 };
    f444.print();

    Fraction44 f544{ 2 * f244 };
    f544.print();

    Fraction44 f644{ Fraction44{1, 2} *Fraction44{2, 3} *Fraction44{3, 4} };
    f644.print();

    std::cout << "------------------" << '\n';

    /*d) If we remove the const from the Fraction * Fraction operator, 
    the following line from the main function no longer works. Why?

    The non-const multiplication operator looks like this

    Fraction operator*(Fraction &f1, Fraction &f2)

    This doesn't work anymore

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };

    We’re multiplying temporary Fraction objects,
    but non-const references cannot bind to temporaries.
    
    e) Extra credit: the fraction 2/4 is the same as 1/2, 
    but 2/4 is not reduced to the lowest terms. 
    We can reduce any given fraction to lowest terms by finding the greatest
    common divisor (GCD) between the numerator and denominator, 
    and then dividing both the numerator and denominator by the GCD.

    int gcd(int a, int b) {
    return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);

    Add this function to your class, 
    and write a member function named reduce() 
    that reduces your fraction. 
    Make sure all fractions are properly reduced.

    */

    Fraction f1{ 2, 5 };
    f1.print();

    Fraction f2{ 3, 8 };
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
    f6.print();

    Fraction f7{ 0, 6 };
    f7.print();


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
