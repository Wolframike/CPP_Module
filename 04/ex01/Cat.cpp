/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:39:51 by misargsy          #+#    #+#             */
/*   Updated: 2024/06/02 16:29:25 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const & src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat&	Cat::operator=(Cat const &src)
{
	if (this == &src)
		return *this;
	
	Animal::operator=(src);
	delete brain_;
	brain_ = new Brain(*src.brain_);
	std::cout << "Cat assignation operator called" << std::endl;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
