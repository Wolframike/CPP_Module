/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:16:31 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/29 23:52:50 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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

	//below minimum score
	try {
		Form form("Form", 0, 42);
		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	//above maximum score
	try {
		Form form("Form", 42, 151);
		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	//sign form
	try {
		Form form("Form", 42, 42);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	//sign form with too low grade
	try {
		Form form("Form", 42, 42);
		std::cout << form << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	//sign form with too high grade
	try {
		Form form("Form", 42, 42);
		std::cout << form << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}