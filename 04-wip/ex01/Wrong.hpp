/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 04:57:33 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/08 23:54:48 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_HPP
# define WRONG_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		~WrongAnimal(void);
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal&	operator=(WrongAnimal const &src);
		std::string		getType(void) const;
		void			setType(std::string type);
		void	makeSound(void) const;
};

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const & src);
		WrongCat&	operator=(WrongCat const &src);
		~WrongCat(void);
		void	makeSound(void) const;
};

#endif