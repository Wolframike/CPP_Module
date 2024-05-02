/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:40:09 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/01 21:19:11 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawbits = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawbits = value << this->_fracbits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawbits = (int)roundf(value * (1 << this->_fracbits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed&			Fixed::operator=(const Fixed &assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawbits = assign.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void			Fixed::setRawBits(int const raw)
{
	this->_rawbits = raw;
}

int				Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawbits);
}

float			Fixed::toFloat(void) const
{
	return ((float)this->_rawbits / (1 << this->_fracbits));
}

int				Fixed::toInt(void) const
{
	return (this->_rawbits >> this->_fracbits);
}

bool			Fixed::operator>(const Fixed &a)
{
	return (this->_rawbits > a.getRawBits());
}

bool			Fixed::operator<(const Fixed &a)
{
	return (this->_rawbits < a.getRawBits());
}

bool			Fixed::operator>=(const Fixed &a)
{
	return (this->_rawbits >= a.getRawBits());
}

bool			Fixed::operator<=(const Fixed &a)
{
	return (this->_rawbits <= a.getRawBits());
}

bool			Fixed::operator==(const Fixed &a)
{
	return (this->_rawbits == a.getRawBits());
}

bool			Fixed::operator!=(const Fixed &a)
{
	return (this->_rawbits != a.getRawBits());
}

Fixed			Fixed::operator+(const Fixed &a)
{
	Fixed	sum;

	sum.setRawBits(this->_rawbits + a.getRawBits());
	return (sum);
}

Fixed			Fixed::operator-(const Fixed &a)
{
	Fixed	diff;

	diff.setRawBits(this->_rawbits - a.getRawBits());
	return (diff);
}

Fixed			Fixed::operator*(const Fixed &a)
{
	Fixed	prod;

	prod.setRawBits((this->_rawbits * a.getRawBits()) >> this->_fracbits);
	return (prod);
}

Fixed			Fixed::operator/(const Fixed &a)
{
	Fixed	quot;

	quot.setRawBits((this->_rawbits << this->_fracbits) / a.getRawBits());
	return (quot);
}

Fixed&			Fixed::operator++(void)
{
	this->_rawbits++;
	return (*this);
}

Fixed			Fixed::operator++(int)
{
	Fixed	prev(*this);

	++(*this);
	return (prev);
}

Fixed&			Fixed::operator--(void)
{
	this->_rawbits--;
	return (*this);
}

Fixed			Fixed::operator--(int)
{
	Fixed	prev(*this);

	--(*this);
	return (prev);
}

Fixed&			Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed&			Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

std::ostream&	operator<<(std::ostream& os, const Fixed &a)
{
	os << a.toFloat();
	return (os);
}
