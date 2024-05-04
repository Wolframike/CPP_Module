/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPNCalculator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 05:20:03 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 05:27:04 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPNCALCULATOR_HPP
# define RPNCALCULATOR_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

class RPNCalculator
{
	private:
		std::stack<int> operands_;

	public:
		RPNCalculator();
		RPNCalculator(const RPNCalculator &copy);
		RPNCalculator &operator=(const RPNCalculator &copy);
		~RPNCalculator();

		void evaluate(const std::string &expr);
};

#endif
