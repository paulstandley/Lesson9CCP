#include "pch.h"
#include <iostream>
#include "Lesson9Header.h"


class Pennys
{
private:
    int m_pennys;

public:
    Pennys(int pennys) { m_pennys = pennys; }

    // Add Pennys + Pennys using friend function
    friend Pennys operator+(const Pennys& p1, const Pennys& p2);

    int getPennys() const { return m_pennys; }
};

// this is not a member function
Pennys operator+(const Pennys& p1, const Pennys& p2)
{
    // use the Pennys constructor and opeator+(int, int)
    // we can access m_pennys direcly because this ia a friend function
    return Pennys(p1.m_pennys + p2.m_pennys);
}


void overloading_arithmetic_operators_using_friend_functions()
{
    /*Some of the most commonly used operators in C++ are the arithmetic operators
    -- that is, the plus operator (+), minus operator (-),
    multiplication operator (*), and division operator (/).

    Note that all of the arithmetic operators are binary operators 
    -- meaning they take two operands -- one on each side of the operator. 
    All four of these operators are overloaded in the exact same way.

    It turns out that there are three different ways to overload operators: 
    
    the member function way, 
    the friend function way, 
    and the normal function way. 
    
    The friend function
    (because it’s more intuitive for most binary operators). 
    
    */

    Pennys penny1{ 6 };
    Pennys penny2{ 8 };
    
    Pennys pennysSum{ penny1 + penny2 };
    std::cout << "I have " << pennysSum.getPennys() << " pennys.\n";

}

int main()
{
    overloading_arithmetic_operators_using_friend_functions();
    operator_overloading();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
