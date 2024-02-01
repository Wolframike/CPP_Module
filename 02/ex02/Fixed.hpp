/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:38:46 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/01 21:14:51 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int					_rawbits;
		static const int	_fracbits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &copy);
		Fixed&	operator=(const Fixed &assign);
		~Fixed();
		void				setRawBits(int const raw);
		int					getRawBits(void) const;
		float				toFloat(void) const;
		int					toInt(void) const;
		bool				operator>(const Fixed &a);
		bool				operator<(const Fixed &a);
		bool				operator>=(const Fixed &a);
		bool				operator<=(const Fixed &a);
		bool				operator==(const Fixed &a);
		bool				operator!=(const Fixed &a);
		Fixed				operator+(const Fixed &a);
		Fixed				operator-(const Fixed &a);
		Fixed				operator*(const Fixed &a);
		Fixed				operator/(const Fixed &a);
		Fixed&				operator++(void);
		Fixed				operator++(int);
		Fixed&				operator--(void);
		Fixed				operator--(int);
		static Fixed&		min(Fixed &a, Fixed &b);
		const static Fixed&	min(const Fixed &a, const Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		const static Fixed&	max(const Fixed &a, const Fixed &b);
};

std::ostream&	operator<<(std::ostream& os, const Fixed &a);

#endif