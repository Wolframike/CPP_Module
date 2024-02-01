/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:36:48 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/01 22:57:43 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;

	std::cout << "ClapTrap " << name << " joins the battle!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	
	std::cout << "ClapTrap " << this->_name << " has been cloned!" << std::endl;
}

ClapTrap&		ClapTrap::operator=(const ClapTrap &assign)
{
	if (this != &assign)
	{
		this->_name = assign._name;
		this->_hitPoints = assign._hitPoints;
		this->_energyPoints = assign._energyPoints;
		this->_attackDamage = assign._attackDamage;
	}
	return (*this);

	std::cout << "ClapTrap " << this->_name << " has been assigned!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed!" << std::endl;
}

void			ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void			ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void			ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void			ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->_attackDamage = attackDamage;
}

std::string		ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

void			ClapTrap::attack(std::string const & target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	if (this->_energyPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " ran out of energy points!" << std::endl;
		return ;
	}
	this->_energyPoints--;

	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}

	if (this->_hitPoints < amount)
	{
		std::cout << "ClapTrap " << this->_name << " has taken " << this->_hitPoints << " points of damage!" << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
	
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " has died!" << std::endl;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " has recovered " << amount << " hit points!" << std::endl;
	this->_hitPoints += amount;
}
