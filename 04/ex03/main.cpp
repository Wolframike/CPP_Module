/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:49:20 by misargsy          #+#    #+#             */
/*   Updated: 2024/09/22 20:51:43 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));

	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	//overflow materia slot
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));

	
	AMateria *tmp = src->createMateria("ice");
	try {
		me->equip(tmp);
	} catch (std::exception &e) {
		delete tmp;
		std::cout << e.what() << std::endl;
	}

	//delete nonexistent materia
	try {
		me->unequip(18);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	//use nonexistent materia
	try {
		me->use(18, *bob);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	delete bob;
	delete me;
	delete src;
	
	return 0;
}