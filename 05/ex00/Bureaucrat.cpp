/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:05:26 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/29 23:39:04 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
	name_("default"),
	grade_(150){}

Bureaucrat::Bureaucrat(const std::string name, unsigned short grade) :
	name_(name),
	grade_(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):
	name_(copy.name_),
	grade_(copy.grade_){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy)
		grade_ = copy.grade_;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {
	return name_;
}

unsigned short Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::incrementGrade() {
	if (grade_ == SCORE_MIN)
		throw GradeTooHighException();
	grade_--;
}

void Bureaucrat::decrementGrade() {
	if (grade_ == SCORE_MAX)
		throw GradeTooLowException();
	grade_++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}