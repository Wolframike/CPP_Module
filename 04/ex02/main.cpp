/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:29:07 by misargsy          #+#    #+#             */
/*   Updated: 2024/06/02 16:32:25 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Wrong.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
	Animal* arr[2] = {new Dog(), new Cat()};

	for (int i = 0; i < 2; i++)
		arr[i]->makeSound();

	Animal* dog = new Dog();
	Animal* dog2 = new Dog();
	*dog2 = *dog;
	delete dog;
	delete dog2;

	for (int i = 0; i < 2; i++)
		delete arr[i];

	return 0;
}
