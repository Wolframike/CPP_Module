/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 05:35:58 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 18:20:49 by misargsy         ###   ########.fr       */
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
		static std::string str_;
		static short impossible_;
		static bool c_nonPrintable_;
		static short type_;
		static double tod_;

		static char c_;
		static int i_;
		static float f_;
		static double d_;

		typedef struct {
			size_t pos;
			bool is;
		} t_pos;

		static bool isNumber();
		static void setType();

		static void toChar();
		static void toInt();
		static void toFloat();
		static void toDouble();

		static void print();

		ScalarConverter();
		ScalarConverter(const std::string &str);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();

	public:
		static void convert(const std::string &str);
};

#endif
