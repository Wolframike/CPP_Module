/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:55:29 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/30 03:43:16 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

class Bureaucrat;

class AForm {
	private:
		const std::string name_;
		bool signed_;
		const unsigned short signGrade_;
		const unsigned short execGrade_;
	
	protected:
		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too high";
				}
		};
		
		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too low";
				}
		};

	public:
		AForm();
		AForm(const std::string name, unsigned short gradeSign, unsigned short gradeExec);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();
		
		const std::string &getName() const;
		bool getSigned() const;
		unsigned short getSignGrade() const;
		unsigned short getExecGrade() const;
		
		void beSigned(const Bureaucrat &bureaucrat);

		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
