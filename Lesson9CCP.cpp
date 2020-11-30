#include "pch.h"
#include <iostream>
#include "Lesson9Header.h"


class Pennys
{
private:
    int m_pennys;

public:
    Pennys(int pennys) { m_pennys = pennys; }

    // Add Pennys + Pennys using friend functions
    friend Pennys operator+(const Pennys& p1, const Pennys& p2);

    // Subtract Pennys -
    friend Pennys operator-(const Pennys& p1, const Pennys& p2);

    // multyply Pennys *
    friend Pennys operator*(const Pennys& p1, const Pennys& p2);

    // divide Pennys /
    friend Pennys operator/(const Pennys& p1, Pennys& p2);

    int getPennys() const { return m_pennys; }
};

// this is not a member function +
Pennys operator+(const Pennys& p1, const Pennys& p2)
{
    // use the Pennys constructor and opeator+(int, int)
    // we can access m_pennys direcly because this ia a friend function
    return Pennys(p1.m_pennys + p2.m_pennys);
}

// -
Pennys operator-(const Pennys& p1, const Pennys& p2)
{
    return Pennys(p1.m_pennys - p2.m_pennys);
}

// *
Pennys operator*(const Pennys& p1, const Pennys& p2) 
{
    return Pennys(p1.m_pennys * p2.m_pennys);
}

// /
Pennys operator/(const Pennys& p1, Pennys& p2)
{
    return Pennys(p1.m_pennys / p2.m_pennys);
}

/////////////////////////////////////////////////////////////////////////////////////

class Cents0
{
private:
    int m_cents;

public:
    Cents0(int cents) { m_cents = cents; }

    // add Cents + Cents using a friend function
        // This function is not considered a member of the class, even though the definition is inside the class
    friend Cents0 operator+(const Cents0& c1, const Cents0& c2)
    {
        // use the Cents constructor and operator+(int, int)
        // we can access m_cents directly because this is a friend function
        return Cents0(c1.m_cents + c2.m_cents);
    }

    int getCents() const { return m_cents; }
};

//////////////////////////////////////////////////////////////////////////////////////

class Cents1
{
private:
    int m_cents;
public:
    Cents1(int cents) { m_cents = cents; }

    // add cents usuing friend function
    friend Cents1 operator+(const Cents1& c1, int value);

    friend Cents1 operator+(int value, const Cents1& c1);

    int getCents() const { return m_cents; }
};

Cents1 operator+(const Cents1& c1, int value)
{
    // use the Cents constructor and operator+(int, int)
    // we can access m_cents directly because this is a friend function
    return { c1.m_cents + value };
}

Cents1 operator+(int value, const Cents1& c1)
{
    return { c1.m_cents + value };
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
    Pennys penny3{ 5 };
    Pennys penny4{ 3 };
    
    Pennys pennysSum{ penny1 + penny2 };
    std::cout << "+ " << pennysSum.getPennys() << " pennys.\n";

    Pennys pennysMinus{ penny3 - penny4 };
    std::cout << "- " << pennysMinus.getPennys() << " pennys. \n";

    Pennys pennysTimes{ penny4 * penny3 };
    std::cout << "* " << pennysTimes.getPennys() << " pennys.\n";

    Pennys pennysDivide{ penny1 / penny4 };
    std::cout << "/ " << pennysDivide.getPennys() << " pennys. \n";

    /*Overloading the plus operator (+) is as simple as declaring a function 
    named operator+, giving it two parameters of the type of the operands
    we want to add, picking an appropriate return type, 
    and then writing the function.

    In the case of our Pennys object, implementing our operator+() function
    is very simple. First, the parameter types: 
    in this version of operator+, 
    we are going to add two Pennys objects together, 
    so our function will take two objects of type Pennys.
    
    Second, the return type: our operator+ is going to return a result of type Pennys, 
    so that’s our return type.

    Finally, implementation: to add two Cents objects together,
    we really need to add the m_pennys member from each Pennys object.
    Because our overloaded operator+() function is a friend of the class, 
    we can access the m_pennys member of our parameters directly. 
    Also, because m_pennys is an integer,
    and C++ knows how to add integers together using the built-in version 
    of the plus operator that works with integer operands, 
    we can simply use the + operator to do the adding.

    Overloading the subtraction operator (-) is simple as well:

    Overloading the multiplication operator (*) and the division operator
    (/) is as easy as defining functions for operator* and operator/ respectively.
    
    */

    /*    
    Pennys pennysSum{ penny1 + penny2 };
    std::cout << "+ " << pennysSum.getPennys() << " pennys.\n";

    Pennys pennysMinus{ penny3 - penny4 };
    std::cout << "- " << pennysMinus.getPennys() << " pennys. \n";
    */

    ///////////////////////////////////////////////////////////////////////////

    /*Friend functions can be defined inside the class

    Even though friend functions are not members of the class,
    they can still be defined inside the class if desired
    
    */

    Cents0 cents01{ 6 };
    Cents0 cents02{ 8 };
    Cents0 centsSum0{ cents01 + cents02 };
    std::cout << "I have " << centsSum0.getCents() << " cents.\n";

    ///////////////////////////////////////////////////////////////////////////////

    /*Overloading operators for operands of different types

    Often it is the case that you want your overloaded operators to work with operands
    that are different types. 
    For example, if we have Cents(4),
    we may want to add the integer 6 to this to produce the result Cents(10).

    When C++ evaluates the expression x + y, x becomes the first parameter,
    and y becomes the second parameter.
    When x and y have the same type, 
    it does not matter if you add x + y or y + x -- either way,
    the same version of operator+ gets called. 
    
    However, 
    when the operands have different types, x + y 
    does not call the same function as y + x.

    For example, 
    Cents(4) + 6 would call operator+(Cents, int), 
    and 6 + Cents(4) would call operator+(int, Cents). 
    
    Consequently, 
    whenever we overload binary operators for operands of different types,
    we actually need to write two functions -- one for each case.
    
    */

    Cents1 c1{ Cents1{ 4 } + 6 };
    Cents1 c2{ 6 + Cents1{ 4 } };

    std::cout << "I have " << c1.getCents() << " cents.\n";
    std::cout << "I have " << c2.getCents() << " cents.\n";

    /*Note that both overloaded functions have the same implementation
    -- that’s because they do the same thing, 
    they just take their parameters in a different order.
    
    ///////////////////////////////////////////////////////////////////////////////


    */
}

int main()
{
    overloading_arithmetic_operators_using_friend_functions();
    //operator_overloading();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
