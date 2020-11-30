#include "pch.h"
#include <iostream>


void operator_overloading()
{
    /*In C++, operators are implemented as functions.
    By using function overloading on the operator functions,
    you can define your own versions of the operators
    that work with different data types
    (including classes that you’ve written).
    Using function overloading to overload operators is called operator overloading.

    */

    int xxx = 2;
    int yyy = 3;
    std::cout << xxx + yyy << '\n';

    /*The compiler comes with a built-in version of the plus operator (+)
    for integer operands -- this function adds integers x and y together
    and returns an integer result.
    When you see the expression x + y,
    you can translate this in your head to the function call operator+(x, y)
    (where operator+ is the name of the function).

    */

    double zzz = 2.0;
    double www = 3.0;
    std::cout << www + zzz << '\n';

    /*The compiler also comes with a built-in version of the plus operator (+)
    for double operands.
    Expression w + z becomes function call operator+(w, z),
    and function overloading is used to determine that the compiler
    should be calling the double version of this function instead of the
    integer version.

    Now consider what happens if we try to add two object of a user-defined class:

    Mystring string1 = "Hello, ";
    Mystring string2 = "World!";
    std::cout << string1 + string2 << '\n';

    What would you expect to happen in this case?
    The intuitive expected result is that the string “Hello, World!”
    would be printed on the screen.
    However, because Mystring is a user-defined class,
    the compiler does not have a built-in version of the plus operator
    that it can use for Mystring operands.
    So in this case, it will give us an error.
    In order to make it work like we want,
    we’d need to write an overloaded function to tell the compiler
    how the + operator should work with two operands of type Mystring.

    ///////////////////////////////////////////////////////////////////////////

    Resolving overloaded operators

    When evaluating an expression containing an operator,
    the compiler uses the following rules:

    If all of the operands are fundamental data types,
    the compiler will call a built-in routine if one exists.
    If one does not exist, the compiler will produce a compiler error.

    If any of the operands are user data types
    (e.g. one of your classes, or an enum type),
    the compiler looks to see whether the type has a matching
    overloaded operator function that it can call.
    If it can’t find one,
    it will try to convert one or more of the user-defined type operands
    into fundamental data types so it can use a matching built-in operator
    via an overloaded typecast. If that fails,
    then it will produce a compile error.

    //////////////////////////////////////////////////////////////////////////////

    What are the limitations on operator overloading?

    First, almost any existing operator in C++ can be overloaded.
    The exceptions are: conditional (?:),
    sizeof, scope (::),
    member selector (.),
    member pointer selector (.*),
    typeid, and the casting operators.

    Second, you can only overload the operators that exist.
    You can not create new operators or rename existing operators.
    For example, you could not create an operator ** to do exponents.

    Third, at least one of the operands in an overloaded operator
    must be a user-defined type.
    This means you can not overload the plus operator to work with one integer
    and one double.
    However, you could overload the plus operator to work with an integer
    and a Mystring.

    Fourth, it is not possible to change the number of operands an operator supports.

    Finally, all operators keep their default precedence and associativity
    (regardless of what they’re used for) and this can not be changed.

    ///////////////////////////////////////////////////////////////////////////////

    Some new programmers attempt to overload the bitwise XOR operator (^)
    to do exponentiation.
    However, in C++, operator^ has a lower precedence level than the
    basic arithmetic operators,
    which causes expressions to evaluate incorrectly.

    In basic mathematics, exponentiation is resolved before basic arithmetic,
    so 4 + 3 ^ 2 resolves as 4 + (3 ^ 2) => 4 + 9 => 13.

    However, in C++, the arithmetic operators have higher precedence than operator^,
    so 4 + 3 ^ 2 resolves as (4 + 3) ^ 2 => 7 ^ 2 => 49.

    You’d need to explicitly parenthesize the exponent portion (e.g. 4 + (3 ^ 2))
    every time you used it for this to work properly,
    which isn’t intuitive, and is potentially error-prone.

    Because of this precedence issue,
    it’s generally a good idea to use operators only in an analogous way
    to their original intent.

    Rule: When overloading operators, it’s best to keep the function of the
    operators as close to the original intent of the operators as possible.

    ////////////////////////////////////////////////////////////////////////////////

    Furthermore, because operators don’t have descriptive names,
    it’s not always clear what they are intended to do.
    For example, operator+ might be a reasonable choice for a string class to do
    concatenation of strings.
    But what about operator-? What would you expect that to do? It’s unclear.

    Rule: If the meaning of an operator when applied to a custom class
    is not clear and intuitive, use a named function instead.

    Within those confines, you will still find plenty of useful functionality
    to overload for your custom classes!
    You can overload the + operator to concatenate your user-defined string class,
    or add two Fraction class objects together.
    You can overload the << operator to make it easy to print your class
    to the screen (or a file).
    You can overload the equality operator (==) to compare two class objects.
    This makes operator overloading one of the most useful features in C++
    -- simply because it allows you to work with your classes in a more intuitive way.

    */
}

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

class MinMax0
{
private:
    int m_min; // The min value seen so far
    int m_max; // The max value seen so far

public:
    MinMax0(int min, int max)
    {
        m_min = min;
        m_max = max;
    }

    int getMin0() const { return m_min; }
    int getMax0() const { return m_max; }

    friend MinMax0 operator+(const MinMax0& m1, const MinMax0& m2);
    friend MinMax0 operator+(const MinMax0& m, int value);
    friend MinMax0 operator+(int value, const MinMax0& m);
};

MinMax0 operator+(const MinMax0& m1, const MinMax0& m2)
{
    // Get the minimum value seen in m1 and m2
    int min{ m1.m_min < m2.m_min ? m1.m_min : m2.m_min };

    // Get the maximum value seen in m1 and m2
    int max{ m1.m_max > m2.m_max ? m1.m_max : m2.m_max };

    return { min, max };
}

MinMax0 operator+(const MinMax0& m, int value)
{
    // Get the minimum value seen in m and value
    int min{ m.m_min < value ? m.m_min : value };

    // Get the maximum value seen in m and value
    int max{ m.m_max > value ? m.m_max : value };

    return { min, max };
}

MinMax0 operator+(int value, const MinMax0& m)
{
    // call operator+(MinMax, int)
    return { m + value };
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

    */

    MinMax0 m1{ 10, 15 };
    MinMax0 m2{ 8, 11 };
    MinMax0 m3{ 3, 12 };

    MinMax0 mFinal0{ m1 + m2 + 5 + 8 + m3 + 16 };

    std::cout << "Result: (" << mFinal0.getMin0() << ", " <<
        mFinal0.getMax0() << ")\n";

    /*The MinMax class keeps track of the minimum and maximum
    values that it has seen so far.
    We have overloaded the + operator 3 times,
    so that we can add two MinMax objects together,
    or add integers to MinMax objects.

    Let’s talk a little bit more about how “
    MinMax mFinal = m1 + m2 + 5 + 8 + m3 + 16” evaluates.
    Remember that operator+ has higher precedence than operator=,
    and operator+ evaluates from left to right,
    so m1 + m2 evaluate first.

    This becomes a call to operator+(m1, m2),
    which produces the return value MinMax(8, 15).
    Then MinMax(8, 15) + 5 evaluates next.
    This becomes a call to operator+(MinMax(8, 15), 5),
    which produces return value MinMax(5, 15).

    Then MinMax(5, 15) + 8 evaluates in the same way to produce MinMax(5, 15).
    Then MinMax(5, 15) + m3 evaluates to produce MinMax(3, 15).
    And finally, MinMax(3, 15) + 16 evaluates to MinMax(3, 16).
    This final result is then assigned to mFinal.

    In other words, this expression evaluates as
    “MinMax mFinal = (((((m1 + m2) + 5) + 8) + m3) + 16)”,
    with each successive operation returning a
    MinMax object that becomes the left-hand operand for the following operator.

    /////////////////////////////////////////////////////////////////////////////////

    Implementing operators using other operators

    In the above example,
    note that we defined operator+(int, MinMax)
    by calling operator+(MinMax, int)
    (which produces the same result).
    This allows us to reduce the implementation of operator+(int, MinMax)
    to a single line,
    making our code easier to maintain by minimizing redundancy
    and making the function simpler to understand.

    It is often possible to define overloaded operators by calling other
    overloaded operators.
    You should do so if and when doing so produces simpler code.
    In cases where the implementation is trivial (e.g. a single line)
    it’s often not worth doing this,
    as the added indirection of an additional function call
    is more complicated than just implementing the function directly.

    //////////////////////////////////////////////////////////////////////////////////

    */
}
