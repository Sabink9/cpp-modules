#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN()
{
}

RPN::RPN(const RPN &other) : _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

void RPN::applyOperator(char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");

	long right = _stack.top();
	_stack.pop();
	long left = _stack.top();
	_stack.pop();

	long result = 0;
	switch (op)
	{
		case '+':
			result = left + right;
			break;
		case '-':
			result = left - right;
			break;
		case '*':
			result = left * right;
			break;
		case '/':
			if (right == 0)
				throw std::runtime_error("Error");
			result = left / right;
			break;
		default:
			throw std::runtime_error("Error");
	}
	_stack.push(result);
}

long RPN::evaluate(const std::string &expr)
{
	while (!_stack.empty())
		_stack.pop();

	std::istringstream	iss(expr);
	std::string			token;

	while (iss >> token)
	{
		if (token.size() != 1)
			throw std::runtime_error("Error");

		char c = token[0];
		if (std::isdigit(static_cast<unsigned char>(c)))
			_stack.push(c - '0');
		else if (c == '+' || c == '-' || c == '*' || c == '/')
			applyOperator(c);
		else
			throw std::runtime_error("Error");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return (_stack.top());
}