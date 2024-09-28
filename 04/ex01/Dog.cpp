/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:40:09 by misargsy          #+#    #+#             */
/*   Updated: 2024/08/25 10:05:34 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const & src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog&	Dog::operator=(Dog const &src)
{
	if (this != &src)
		Animal::operator=(src);
	delete brain;
	brain = new Brain(*src.brain);
	std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}
