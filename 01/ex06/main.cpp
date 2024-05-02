/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:56:38 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/01 18:57:56 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr << "Harl: invalid number of arguments" << std::endl;
		return 1;
	}
	harl.complain(argv[1]);
	return 0;
}