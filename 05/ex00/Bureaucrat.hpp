/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:05:06 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/29 23:38:43 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#define SCORE_MAX 150
#define SCORE_MIN 1

class Bureaucrat {
	private:
		const std::string name_;
		unsigned short grade_;

		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Bureaucrat: Grade too high";
				}
		};
		
		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Bureaucrat: Grade too low";
				}
		};

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, unsigned short grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();

		const std::string &getName() const;
		unsigned short getGrade() const;
		void incrementGrade();
		void decrementGrade();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
