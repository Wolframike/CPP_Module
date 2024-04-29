/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:58:18 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/30 04:05:50 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy) {
	(void)copy;
}

Intern &Intern::operator=(const Intern &copy) {
	(void)copy;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	static const std::string formNames[] = {
		SHRUBBERY_CREATION_FORM,
		ROBOTOMY_REQUEST_FORM,
		PRESIDENTIAL_PARDON_FORM
	};
	static formCreator formCreators[] = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};
	for (size_t i = 0; i < sizeof(formNames) / sizeof(formNames[0]); ++i) {
		if (formNames[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}
	std::cout << "Intern could not create " << formName << std::endl;
	return NULL;
}
