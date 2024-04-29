/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 04:58:16 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/08 23:56:23 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wrong.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Wrong animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "Wrong animal type constructor called" << std::endl;
	this->type = type;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong animal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	*this = src;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const &src)
{
	if (this != &src)
		type = src.type;
	return *this;
}

std::string		WrongAnimal::getType(void) const
{
	return type;
}

void			WrongAnimal::setType(std::string type)
{
	this->type = type;
}

void			WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong animal sound" << std::endl;
}

WrongCat::WrongCat(void) : WrongAnimal("Cat")
{
	std::cout << "Wrong cat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src)
{
	*this = src;
	std::cout << "Wrong cat copy constructor called" << std::endl;
}
WrongCat&	WrongCat::operator=(WrongCat const &src)
{
	if (this != &src)
		WrongAnimal::operator=(src);
	std::cout << "Wrong cat assignation operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Wrong cat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong meow" << std::endl;
}
