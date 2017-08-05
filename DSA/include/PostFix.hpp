/*
 * PostFix.h
 *
 *  Created on: 05-Aug-2017
 *      Author: gsharma
 */

#ifndef POSTFIX_HPP_
#define POSTFIX_HPP_

#include "Stack.hpp"
#include <string>

/**
 * Assumes that the postfix expression has single digits as operands.
 */
class PostFix {
	Stack<double> stack;
	std::string postfixExpression;

	enum LiteralType
	{
		OPERAND,
		OPERATOR,
		UNKNOWN
	};

	LiteralType getLiteralType(char ch);

	bool isOperand(char ch) { return getLiteralType(ch) == OPERAND; }
	bool isOperator(char ch) { return getLiteralType(ch) == OPERATOR; }

	void evaluate(char ch);
public:
	PostFix(std::string expr);
	virtual ~PostFix();

	double evaluate();
};

#endif /* POSTFIX_HPP_ */
