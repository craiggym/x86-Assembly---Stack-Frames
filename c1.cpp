/*************************************************************************************************************************************************************
*Author:  Craig Marroquin
*Email:   CraigMarroquin@yahoo.com
*Course:  CPSC 240
*Assignment:  7
*Due date:   May 9, 2015
*
*Name of this file:  c1.cpp
*
*GNU compiler:  g++ -m64 -Wall c1.cpp -c -o Output_Files/c1.o
*
*Purpose:  This is subprogram number <1> out of 6 designed for the purpose of investigating the role of the system stack in process of calling subprograms.
************************************************************************************************************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;

extern "C" long c2();

int main()
{
// Long variable declaration using female names in alphabetical order with the number associated to the program //
long alice1 = 3, bernice1 = 8;

//cout << "alice1 = " << alice1 << '\n' << "bernice1 = " << bernice1 << endl;
printf("alice1 = %li\nbernice1 = %li\n", alice1, bernice1);

alice1 = c2(); //Recycling variables after being done using them //


}
