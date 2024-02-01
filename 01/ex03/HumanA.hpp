/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:48:24 by misargsy          #+#    #+#             */
/*   Updated: 2024/01/31 23:49:06 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon&		_weapon;
	
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		void		setName(std::string name);
		void		setWeapon(Weapon& weapon);
		std::string	getName(void);
		Weapon&		getWeapon(void);
		void		attack(void);
};

#endif
