/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:16:31 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/29 22:27:15 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat bureaucrat("Jackson", 42);
	std::cout << bureaucrat << std::endl;

	//below minimum score
	try {
		Bureaucrat bureaucrat("Smith", 0);
		std::cout << bureaucrat << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	//above maximum score
	try {
		Bureaucrat bureaucrat("Craig", 151);
		std::cout << bureaucrat << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	//increment
	try {
		Bureaucrat bureaucrat("Jackson", 42);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	//increment beyond maximum
	try {
		Bureaucrat bureaucrat("Johnson", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}