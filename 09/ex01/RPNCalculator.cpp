/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPNCalculator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 05:23:27 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 05:40:51 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPNCalculator.hpp"

RPNCalculator::RPNCalculator() : operands_() {}

RPNCalculator::RPNCalculator(const RPNCalculator &copy) : operands_(copy.operands_) {}

RPNCalculator &RPNCalculator::operator=(const RPNCalculator &copy)
{
	if (this != &copy)
		operands_ = copy.operands_;
	return *this;
}

RPNCalculator::~RPNCalculator() {}

void RPNCalculator::evaluate(const std::string &expr)
{
	std::istringstream iss(expr);
	std::string token;

	while (iss >> token) {
		if (token.size() > 1) {
			std::cerr << "Error: invalid token" << std::endl;
			return;
		}
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (operands_.size() < 2) {
				std::cout << "Error: unbalanced number of operator and operand" << std::endl;
				return;
			}
			int a = operands_.top();
			operands_.pop();
			int b = operands_.top();
			operands_.pop();
			switch (token[0]) {
				case '+':
					operands_.push(b + a);
					break;
				case '-':
					operands_.push(b - a);
					break;
				case '*':
					operands_.push(b * a);
					break;
				case '/':
					if (a == 0) {
						std::cout << "Error: division by zero" << std::endl;
						return;
					}
					operands_.push(b / a);
					break;
				default:
					std::cerr << "Error: invalid token" << std::endl;
					return;
			}
		}
		else {
			if (std::isdigit(token[0])) {
				char *endptr;
				operands_.push(std::strtod(token.c_str(), &endptr));
			} else {
				std::cerr << "Error: invalid token" << std::endl;
				return;
			}
		}
	}
	if (operands_.size() != 1)
		std::cerr << "Error: too many operands" << std::endl;
	else
		std::cout << operands_.top() << std::endl;
}
