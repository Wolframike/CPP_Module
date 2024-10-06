/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:29:56 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/04 09:30:09 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target_(copy.target_) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	if (this != &copy)
		AForm::operator=(copy);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	const int height = 10;
	
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::ofstream file((target_ + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < height - i - 1; ++j) {
			file << " ";
		}
		for (int j = 0; j < 2 * i + 1; ++j) {
			char randomChar = std::rand() % 26 + 'a';
			file << randomChar;
		}
		file << std::endl;
	}
	for (int i = 0; i < height / 3; ++i) {
		for (int j = 0; j < height - 1; ++j) {
			file << " ";
		}
		file << "|||" << std::endl;
	}
}
