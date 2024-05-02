/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:42:43 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/02 21:34:37 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout 
		<< "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout 
		<< "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout 
		<< "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I've been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout 
		<< "[ ERROR ]" << std::endl
		<< "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*complaints[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	size_t i = 0;
	while (levels[i].compare(level) != 0 && i < 4)
		i++;
	if (i < 4)
	{
		switch (i) {
			case 0:
				(this->*complaints[0])();
			case 1:
				(this->*complaints[1])();
			case 2:
				(this->*complaints[2])();
			case 3:
				(this->*complaints[3])();
				break;
			default:
				std::cout << "Harl: Unknown level: " << level << std::endl;
		}
	}
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
