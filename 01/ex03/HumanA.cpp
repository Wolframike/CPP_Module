/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:42:12 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/24 18:41:11 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	this->_name = name;
}

HumanA::~HumanA(void) {}

void HumanA::setName(std::string name)
{
	this->_name = name;
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}

const std::string& HumanA::getName(void)
{
	return (this->_name);
}

const Weapon& HumanA::getWeapon(void)
{
	return (this->_weapon);
}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
