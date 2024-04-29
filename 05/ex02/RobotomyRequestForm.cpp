/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:27:52 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/30 03:43:28 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target_(copy.target_) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	if (this != &copy)
		AForm::operator=(copy);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::cout << "Surgery go brrrr" << std::endl;
	if (rand() % 2)
		std::cout << target_ << " has been robotomized" << std::endl;
	else
		std::cout << target_ << " robotomization failed" << std::endl;
}
