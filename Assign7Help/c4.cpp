/*************************************************************************************************************************************************************
*Author:  Craig Marroquin
*Email:   CraigMarroquin@yahoo.com
*Course:  CPSC 240
*Assignment:  7
*Due date:   May 9, 2015
*
*Name of this file:  c4.cpp
*
*GNU compiler:  g++ -m64 -Wall c4.cpp -c -o Output_Files/c4.o
*
*Purpose:  This is subprogram number <4> out of 6 designed for the purpose of investigating the role of the system stack in process of calling subprograms.
************************************************************************************************************************************************************/
#include <iostream>
using namespace std;

extern "C" long c4(long);
extern "C" long c5(long);

long c4(long x)
{
long hannah4 = 13;

long irene4 = hannah4 - x;

hannah4 = c5(irene4);

return hannah4;
}

