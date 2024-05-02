/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:03:38 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/27 19:51:13 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap " << name << " joins the battle!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap " << this->_name << " has been cloned!" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &assign)
{
	if (this != &assign)
	{
		this->_name = assign._name;
		this->_hitPoints = assign._hitPoints;
		this->_energyPoints = assign._energyPoints;
		this->_attackDamage = assign._attackDamage;
	}
	return (*this);

	std::cout << "FragTrap " << this->_name << " has been assigned!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " has been destroyed!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " wants a high-five!" << std::endl;
}
