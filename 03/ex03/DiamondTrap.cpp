/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:13:15 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/04 01:42:39 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap " << this->_name << " joins the battle!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;

	std::cout << "DiamondTrap " << name << " joins the battle!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	std::cout << "DiamondTrap " << this->_name << " has been cloned!" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &assign) {
	if (this != &assign) {
		this->_name = assign._name;
		this->_hitPoints = assign._hitPoints;
		this->_energyPoints = assign._energyPoints;
		this->_attackDamage = assign._attackDamage;
	}
	return (*this);

	std::cout << "DiamondTrap " << this->_name << " has been assigned!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " has been destroyed!" << std::endl;
}

void	DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << "." << std::endl;
}
