//============================================================================
// Name        : AckermanFunction.cpp
// Author      : gsharma
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "include/AckermanFunction.hpp"

#include <iostream>
using namespace std;

/*
 *	The function
 *
 *  a(x, y) = y+1 if x == 0, a(x-1, 1) if y == 0, a(x-1, a(x, y-1)) otherwise
 */
 
int ackerman(int x, int y)
{
	cout<< "ackerman("<<x<<", "<<y<<")."<<endl;
	if(x == 0)
		return y + 1;
		
	if(y == 0)
		return ackerman(x - 1, 1);
		
	return ackerman(x - 1, ackerman(x, y-1));
}
