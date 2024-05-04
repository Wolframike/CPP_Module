/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:25:32 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 00:34:04 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.hpp"
#include <iostream>

Base::~Base() {}

Base *generate(void) {
	std::srand(time(NULL));
	const short i = std::rand() % 3;
	
	switch (i) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

void identify(Base *p) {
	char type = ' ';

	if (dynamic_cast<A*>(p) != NULL)
		type = 'A';
	else if (dynamic_cast<B*>(p) != NULL)
		type = 'B';
	else if (dynamic_cast<C*>(p) != NULL)
		type = 'C';
	std::cout << type << std::endl;
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	} catch (const std::exception &e) {}

	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch (const std::exception &e) {}

	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch (const std::exception &e) {}
}

int main(void) {
	Base *p = generate();
	identify(p);
	identify(*p);

	Base *p2 = generate();
	identify(p2);
	identify(*p2);

	Base *p3 = generate();
	identify(p3);
	identify(*p3);

	delete p;
	delete p2;
	delete p3;

	A a;
	B b;
	C c;

	identify(&a);
	identify(a);
	identify(&b);
	identify(b);
	identify(&c);
	identify(c);

	return 0;
}
