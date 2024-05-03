/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 04:17:33 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/04 04:32:05 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string name_;
		AMateria *materias_[MateriaSource::MATERIA_MAX];
		int count_;
	
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &copy);
		Character &operator=(const Character &copy);
		~Character();

		const std::string &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif
