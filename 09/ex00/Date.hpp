/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:41:57 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 13:21:13 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

#include <stdexcept>
#include <iostream>
#include <iomanip>

class Date {
	public:
		unsigned short year;
		unsigned short month;
		unsigned short day;

		Date();
		Date(unsigned short year, unsigned short month, unsigned short day);
		Date(const Date &copy);
		Date &operator=(const Date &copy);
		~Date();

		bool operator==(const Date& other) const;
		bool operator<(const Date& other) const;
		bool operator>(const Date& other) const;
		bool operator<=(const Date& other) const;
		bool operator>=(const Date& other) const;
		bool operator!=(const Date& other) const;

		bool isValid() const;
		static double diff(const Date &a, const Date &b);
};

// << operator overload
std::ostream &operator<<(std::ostream &out, const Date &d);

#endif
