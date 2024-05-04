/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 05:30:02 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 05:30:14 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPNCalculator.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RPN \"expression\"" << std::endl;
		return 1;
	}
	RPNCalculator calc;
	calc.evaluate(av[1]);
	return 0;
}