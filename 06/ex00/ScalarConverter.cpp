/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 06:47:03 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 18:20:26 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::str_;
short ScalarConverter::impossible_;
bool ScalarConverter::c_nonPrintable_;
short ScalarConverter::type_;
double ScalarConverter::tod_;
char ScalarConverter::c_;
int ScalarConverter::i_;
float ScalarConverter::f_;
double ScalarConverter::d_;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	if (this != &src) {
		str_ = src.str_;
		impossible_ = src.impossible_;
		type_ = src.type_;
		c_ = src.c_;
		i_ = src.i_;
		f_ = src.f_;
		d_ = src.d_;
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str) {
	size_t start = str.find_first_not_of(" \t\n\v\f\r");
	size_t end = str.find_last_not_of(" \t\n\v\f\r");

	if (start == std::string::npos)
		start = 0;
	
	if (end == std::string::npos)
		end = str.length() - 1;
	
	str_ = str.substr(start, end - start + 1);

	char *endptr;
	tod_ = std::strtod(str_.c_str(), &endptr);
	
	setType();
	toChar();
	toInt();
	toFloat();
	toDouble();

	print();
}

bool ScalarConverter::isNumber() {
	t_pos plus;
	t_pos minus;
	t_pos dot;
	t_pos f;

	plus.pos = str_.find('+');
	plus.is = plus.pos != std::string::npos;
	minus.pos = str_.find('-');
	minus.is = minus.pos != std::string::npos;
	dot.pos = str_.find('.');
	dot.is = dot.pos != std::string::npos;
	f.pos = str_.find('f');
	f.is = f.pos != std::string::npos;

	if (plus.is && plus.pos != 0)
		return false;
	if (minus.is && minus.pos != 0)
		return false;
	
	if (plus.is && minus.is)
		return false;

	if (f.is && f.pos != str_.length() - 1)
		return false;
	
	if (dot.is) {
		const size_t start = (plus.is || minus.is) ? 1 : 0;
		const size_t mid = f.pos;
		const size_t end = f.is ? f.pos - 1 : str_.length() - 1;

		if (mid == start || mid == end)
			return false;
		
		for (size_t i = start; i < mid; i++)
			if (std::isdigit(str_[i]) == 0)
				return false;
		
		for (size_t i = mid + 1; i <= end; i++)
			if (std::isdigit(str_[i]) == 0)
				return false;
		
		return true;
	}
	
	for (size_t i = (plus.is || minus.is) ? 1 : 0; i < str_.length(); i++)
		if (std::isdigit(str_[i]) == 0)
			return false;
	
	return true;
}

void ScalarConverter::setType() {
	if (str_ == "nan" || str_ == "-inf" || str_ == "+inf") {
		type_ = DOUBLE;
		impossible_ |= C | I;
		return ;
	}

	if (str_ == "nanf" || str_ == "-inff" || str_ == "+inff") {
		type_ = FLOAT;
		impossible_ |= C | I;
		return ;
	}

	if (str_.length() == 1 && std::isdigit(str_[0]) == 0) {
		type_ = CHAR;
		return ;
	}

	if (isNumber()) {
		if (str_.find('.') != std::string::npos) {
			if (str_.find('f') != std::string::npos)
				type_ = FLOAT;
			else
				type_ = DOUBLE;
		} else
			if (tod_ >= INT_MIN && tod_ <= INT_MAX)
				type_ = INT;
			else
				type_ = DOUBLE;
	}
}

void ScalarConverter::toChar() {
	if (impossible_ & C)
		return;
	
	if (type_ == CHAR) {
		c_ = str_[0];
		return;
	}
	
	if (tod_ < CHAR_MIN || tod_ > CHAR_MAX)
		impossible_ |= C;
	else if (std::isprint(tod_) == 0)
		c_nonPrintable_ = true;
	else
		c_ = static_cast<char>(tod_);
}

void ScalarConverter::toInt() {
	if (impossible_ & I)
		return;

	if (type_ == INT) {
		i_ = static_cast<int>(tod_);
		return;
	}

	if (tod_ < INT_MIN || tod_ > INT_MAX)
		impossible_ |= I;
	else
		i_ = static_cast<int>(tod_);
}

void ScalarConverter::toFloat() {
	if (impossible_ & F)
		return;
	
	if (type_ == FLOAT) {
		f_ = static_cast<float>(tod_);
		return;
	}

	if (tod_ < FLT_MIN || tod_ > FLT_MAX)
		impossible_ |= F;
	else
		f_ = static_cast<float>(tod_);
}

void ScalarConverter::toDouble() {
	if (impossible_ & D)
		return;
	
	if (type_ == DOUBLE) {
		d_ = tod_;
		return;
	}

	if (tod_ < DBL_MIN || tod_ > DBL_MAX)
		impossible_ |= D;
	else
		d_ = tod_;
}

void ScalarConverter::print() {
	std::cout << "char: ";
	if (impossible_ & C)
		std::cout << "impossible" << std::endl;
	else if (c_nonPrintable_)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c_ << "'" << std::endl;

	std::cout << "int: ";
	if (impossible_ & I)
		std::cout << "impossible" << std::endl;
	else
		std::cout << i_ << std::endl;
	
	std::cout << "float: ";
	if (impossible_ & F)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f_ << "f" << std::endl;
	
	std::cout << "double: ";
	if (impossible_ & D)
		std::cout << "impossible" << std::endl;
	else
		std::cout << d_ << std::endl;
}
