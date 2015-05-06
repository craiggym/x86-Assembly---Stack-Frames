/*************************************************************************************************************************************************************
*Author:  Craig Marroquin
*Email:   CraigMarroquin@yahoo.com
*Course:  CPSC 240
*Assignment:  7
*Due date:   May 9, 2015
*
*Name of this file:  c2.cpp
*
*GNU compiler:  g++ -m64 -Wall c2.cpp -c -o Output_Files/c2.o
*
*Purpose:  This is subprogram number <2> out of 6 designed for the purpose of investigating the role of the system stack in process of calling subprograms.
************************************************************************************************************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;

extern "C" long c2();
extern "C" long c3(long);

long c2()
{
long christine2 = -4;
long *danielle2 = new long(-1);
long emily2 = 7;

printf("christine2 = %li \ndanielle2 = %li \nemily2 = %li \n", christine2, *danielle2, emily2);

emily2 = c3(christine2);

return *danielle2;
}
