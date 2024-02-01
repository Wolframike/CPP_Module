/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:08:48 by misargsy          #+#    #+#             */
/*   Updated: 2024/01/31 20:21:53 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* horde = zombieHorde(10, "ZOMBIE");

	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}

__attribute__((destructor))
static void a(void)
{
	system("leaks -q zombieHorde");
}
