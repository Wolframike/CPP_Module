/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:37:50 by misargsy          #+#    #+#             */
/*   Updated: 2024/06/02 16:28:07 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	brain_;
	
	public:
		Dog(void);
		Dog(Dog const & src);
		Dog&	operator=(Dog const &src);
		~Dog(void);
		void	makeSound(void) const;
};

#endif
