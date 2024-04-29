/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:58:38 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/29 23:49:17 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_("default"), signed_(false), signGrade_(1), execGrade_(1) {}

Form::Form(const std::string name, unsigned short signGrade, unsigned short execGrade) : name_(name), signed_(false), signGrade_(signGrade), execGrade_(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooLowException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooHighException();
}

Form::Form(const Form &copy) : name_(copy.name_), signed_(copy.signed_), signGrade_(copy.signGrade_), execGrade_(copy.execGrade_) {}

Form &Form::operator=(const Form &copy) {
	if (this != &copy) {
		signed_ = copy.signed_;
	}
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const {
	return name_;
}

bool Form::getSigned() const {
	return signed_;
}

unsigned short Form::getSignGrade() const {
	return signGrade_;
}

unsigned short Form::getExecGrade() const {
	return execGrade_;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > signGrade_)
		throw GradeTooLowException();
	signed_ = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "Form " << form.getName() << " is ";
	if (!form.getSigned())
		out << "not ";
	out << "signed" << std::endl;
	out << "Grade to sign: " << form.getSignGrade() << std::endl;
	out << "Grade to execute: " << form.getExecGrade() << std::endl;
	return out;
}
