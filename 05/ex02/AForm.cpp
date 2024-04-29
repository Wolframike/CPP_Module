/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:55:18 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/29 23:55:23 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name_("default"), signed_(false), signGrade_(1), execGrade_(1) {}

AForm::AForm(const std::string name, unsigned short signGrade, unsigned short execGrade) : name_(name), signed_(false), signGrade_(signGrade), execGrade_(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooLowException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &copy) : name_(copy.name_), signed_(copy.signed_), signGrade_(copy.signGrade_), execGrade_(copy.execGrade_) {}

AForm &AForm::operator=(const AForm &copy) {
	if (this != &copy) {
		signed_ = copy.signed_;
	}
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
	return name_;
}

bool AForm::getSigned() const {
	return signed_;
}

unsigned short AForm::getSignGrade() const {
	return signGrade_;
}

unsigned short AForm::getExecGrade() const {
	return execGrade_;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > signGrade_)
		throw GradeTooLowException();
	signed_ = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << "AForm " << form.getName() << " is ";
	if (!form.getSigned())
		out << "not ";
	out << "signed" << std::endl;
	out << "Grade to sign: " << form.getSignGrade() << std::endl;
	out << "Grade to execute: " << form.getExecGrade() << std::endl;
	return out;
}
