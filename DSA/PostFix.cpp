/*
 * PostFix.cpp
 *
 *  Created on: 05-Aug-2017
 *      Author: gsharma
 */

#include "include/PostFix.hpp"
#include <cmath>
using namespace std;

PostFix::PostFix(string expr) : postfixExpression(expr)
{
	// TODO Auto-generated constructor stub

}

PostFix::~PostFix()
{
	// TODO Auto-generated destructor stub
}

double PostFix::evaluate()
{
	double retVal = 0;

	for(size_t i = 0; i < postfixExpression.length(); i++)
	{
		switch(getLiteralType(postfixExpression[i]))
		{
		case PostFix::OPERAND:
			stack.push(postfixExpression[i] - '0');
			break;
		case PostFix::OPERATOR:
			evaluate(postfixExpression[i]);
			break;
		case PostFix::UNKNOWN:
			break;
		}
	}

	retVal = stack.pop();

	return retVal;
}

PostFix::LiteralType PostFix::getLiteralType(char ch)
{
	if(isdigit(ch))
		return PostFix::OPERAND;

	switch(ch)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
			return PostFix::OPERATOR;
	}

	return PostFix::UNKNOWN;
}

void PostFix::evaluate(char ch)
{
	double op2 = stack.pop();
	double op1 = stack.pop();
	switch(ch)
	{
	case '+': stack.push(op1 + op2); break;
	case '-': stack.push(op1 - op2); break;
	case '*': stack.push(op1 * op2); break;
	case '/': stack.push(op1 / op2); break;
	case '^': stack.push(pow(op1, op2)); break;
	}
}
