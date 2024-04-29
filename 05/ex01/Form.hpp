/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:54:46 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/29 23:53:21 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name_;
		bool signed_;
		const unsigned short signGrade_;
		const unsigned short execGrade_;

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
		Form();
		Form(const std::string name, unsigned short gradeSign, unsigned short gradeExec);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();
		
		const std::string &getName() const;
		bool getSigned() const;
		unsigned short getSignGrade() const;
		unsigned short getExecGrade() const;
		
		void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
