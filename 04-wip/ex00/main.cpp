/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:29:07 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/02 05:04:17 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "--------------------" << std::endl;

	const WrongAnimal* wrong = new WrongAnimal;
	const WrongAnimal* wrongCat = new WrongCat;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrong->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete wrongCat;
	return 0;
}
