/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:39:01 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/02 05:51:52 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	std::cout << "Animal type constructor called" << std::endl;
	this->type = type;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal&		Animal::operator=(const Animal& src)
{
	if (this != &src)
		type = src.type;
	return *this;
}

std::string	Animal::getType() const
{
	return type;
}

void		Animal::setType(std::string type)
{
	this->type = type;
}

void		Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}
