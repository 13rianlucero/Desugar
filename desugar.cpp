// Brian Lucero
// CPSC-439 Theory of Computation
// Using starter code provided by Professor Avery:
// https://gist.github.com/ProfAvery/ac1a68b7cc737348bd41853611f23ba0
// Friday, Mar 4, 2022
/*
    Give a “proof by code” of Theorem 4.6: a program in a programming language of your choice 
    that transforms a NAND-CIRC-IF program P into a “sugar-free” NAND-CIRC program P'
    that computes the same function.
*/

#include <iostream>
/*
    C++ version of
    https://nbviewer.org/github/boazbk/tcscode/blob/master/Chap_04_Syntactic_Sugar.ipynb#Even-more-sugar
*/

using namespace std;

string NAND(string a, string b)
{
    static auto counter = 1;

    auto v = "temp_" + to_string(counter++);
    cout << v << " = NAND(" << a << "," << b << ")" << endl;
    return v;
}

string NOT(string a)
{
    return NAND(a, a);
}

string AND(string a, string b)
{
    auto temp = NAND(a, b);
    return NOT(temp);
}

string OR(string a, string b)
{
    auto temp1 = NOT(a);
    auto temp2 = NOT(b);
    return NAND(temp1, temp2);
}

string MAJ(string a, string b, string c)
{
    auto and1 = AND(a, b);
    auto and2 = AND(a, c);
    auto and3 = AND(b, c);
    auto or1 = OR(and1, and2);
    return OR(or1, and3);
}

string IF(string cond, string a, string b)
{
    auto notcond = NAND(cond, cond);
    auto temp = NAND(b, notcond);
    auto temp1 = NAND(a, cond);
    return NAND(temp, temp1);
}

string LOOKUP1(string a, string b, string c)
{
    return IF(c, b, a);
}

string LOOKUP2(string a, string b, string c, string d, string e, string f)
{
    auto temp = LOOKUP1(c, d, f);
    auto temp1 = LOOKUP1(a, b, f);
    return IF(e, temp, temp1);
}

int main()
{
    // MAJ("X[0]", "X[1]", "X[1]");

    /*
        When IF, LOOKUP1, and LOOKUP2 have been implemented correctly,
        you should be able to run the following instead:
            LOOKUP2("X[0]", "X[1]", "X[2]", "X[3]", "I[0]", "I[1]");
    */
   LOOKUP2("X[0]", "X[1]", "X[2]", "X[3]", "I[0]", "I[1]");
    return 0;
}