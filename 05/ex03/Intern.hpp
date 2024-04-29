/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:56:36 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/30 04:05:42 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define SHRUBBERY_CREATION_FORM "shrubbery creation"
#define ROBOTOMY_REQUEST_FORM "robotomy request"
#define PRESIDENTIAL_PARDON_FORM "presidential pardon"

class Intern {
	private:
		typedef AForm *(*formCreator)(const std::string &target);
		static AForm *createShrubberyCreationForm(const std::string &target);
		static AForm *createRobotomyRequestForm(const std::string &target);
		static AForm *createPresidentialPardonForm(const std::string &target);

	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

		AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
