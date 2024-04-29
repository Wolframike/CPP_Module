/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:16:31 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/30 04:08:37 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

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

	//ShubberyCreationForm
	ShrubberyCreationForm form("home");
	std::cout << form << std::endl;
	try {
		bureaucrat.signForm(form);
		form.execute(bureaucrat);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	//RobotomyRequestForm
	RobotomyRequestForm form2("home");
	std::cout << form2 << std::endl;
	try {
		bureaucrat.signForm(form2);
		form2.execute(bureaucrat);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	//PresidentialPardonForm
	PresidentialPardonForm form3("home");
	std::cout << form3 << std::endl;
	try {
		bureaucrat.signForm(form3);
		form3.execute(bureaucrat);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	//Intern
	Intern intern;
	AForm *form4 = intern.makeForm(ROBOTOMY_REQUEST_FORM, "Anthony E-gas Monise");
	std::cout << *form4 << std::endl;
	try {
		bureaucrat.signForm(*form4);
		form4->execute(bureaucrat);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete form4;

	return 0;
}
