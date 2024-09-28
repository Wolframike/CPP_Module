/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:34:18 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/10 19:03:57 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;
		Animal(void);
		Animal(std::string type);

	public:
		virtual ~Animal(void);
		Animal(Animal const &src);
		Animal&			operator=(Animal const &src);
		std::string		getType(void) const;
		void			setType(std::string type);
		virtual void	makeSound(void) const = 0;
};

#endif
