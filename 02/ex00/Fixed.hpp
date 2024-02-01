/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:06:39 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/01 19:22:45 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int					_rawbits;
		static const int	_fracbits = 8;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed&	operator=(const Fixed &assign);
		~Fixed();
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
};

#endif