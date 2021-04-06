#include <iostream>     //#2 - include iostream to access cout
#include "functions.h" //#5 - include header file
using namespace std;

int main()
{
    //#3 - call PrintName in the main function
    PrintName();
}

//#2 - function to print name on a new line
void PrintName()
{
    cout << "Kyle James" << endl;
}