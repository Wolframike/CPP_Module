/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 04:05:07 by misargsy          #+#    #+#             */
/*   Updated: 2024/09/28 21:05:07 by misargsy         ###   ########.fr       */
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
	
	Character* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	Character* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	//overflow materia slot
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	try {
		tmp = src->createMateria("ice");
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