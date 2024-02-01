/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:00:03 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/02 05:05:50 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	//Stack
	Zombie zombie = Zombie("Stack Zombie");
	zombie.announce();
	
	//Heap
	Zombie *zombie2 = zombie.newZombie("Heap Zombie");
	zombie2->announce();
	delete zombie2;

	//Random
	zombie.randomChump("Random Zombie");
	return (0);
	/*
	Stack: Once allocated, the memory is automatically freed when the variable goes out of scope.

	Heap: Memory needs to be manually freed. Memory leaks will occur if not done so.
	*/
}
