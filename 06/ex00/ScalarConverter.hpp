/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 05:35:58 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/04 07:54:08 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cfloat>
#include <climits>

typedef enum e_impossible : short{
	C = 1 << 0,
	I = 1 << 1,
	F = 1 << 2,
	D = 1 << 3
} e_impossible;

typedef enum e_type : short{
	CHAR = 1 << 0,
	INT = 1 << 1,
	FLOAT = 1 << 2,
	DOUBLE = 1 << 3
} e_type;

class ScalarConverter {
	private:
		std::string str_;
		short impossible_;
		bool c_nonPrintable_;
		short type_;
		double tod_;

		char c_;
		int i_;
		float f_;
		double d_;

		typedef struct {
			size_t pos;
			bool is;
		} t_pos;

		bool isNumber();
		void setType();

		void toChar();
		void toInt();
		void toFloat();
		void toDouble();

	public:
		ScalarConverter();
		ScalarConverter(const std::string &str);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();

		void convert();
		void print() const;
};

#endif
