/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:43:38 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/24 18:41:01 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon*		_weapon;
	
	public:
		HumanB(std::string name);
		~HumanB(void);
		void				setName(std::string name);
		void				setWeapon(Weapon& weapon);
		const std::string&	getName(void);
		const Weapon&		getWeapon(void);
		void				attack(void);
};

#endif
