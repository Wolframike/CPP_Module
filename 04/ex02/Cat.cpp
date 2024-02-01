/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:39:51 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/02 05:28:10 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	this->brain = new Brain();
}

Cat::~Cat(void)
{
	delete this->brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
