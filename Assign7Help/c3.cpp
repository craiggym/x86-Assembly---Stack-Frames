/*************************************************************************************************************************************************************
*Author:  Craig Marroquin
*Email:   CraigMarroquin@yahoo.com
*Course:  CPSC 240
*Assignment:  7
*Due date:   May 9, 2015
*
*Name of this file:  c3.cpp
*
*GNU compiler:  g++ -m64 -Wall c3.cpp -c -o Output_Files/c3.o
*
*Purpose:  This is subprogram number <3> out of 6 designed for the purpose of investigating the role of the system stack in process of calling subprograms.
************************************************************************************************************************************************************/
#include <iostream>
using namespace std;

extern "C" long c3(long);
extern "C" long c4(long);

long c3(long x)
{
long francis3 = -16;
long gina3 = francis3 + x;

francis3 = c4(gina3); // Recycling the variable francis3 to call on function c4 since we're done using francis3 //

return francis3;
}
