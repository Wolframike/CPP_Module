/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:43:18 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/24 18:41:18 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::~HumanB(void) {}

void HumanB::setName(std::string name)
{
	this->_name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

const std::string& HumanB::getName(void)
{
	return (this->_name);
}

const Weapon& HumanB::getWeapon(void)
{
	return (*this->_weapon);
}

void HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
