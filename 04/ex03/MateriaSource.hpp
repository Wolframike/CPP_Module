/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 04:06:18 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/04 04:26:11 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

class MateriaSource : public IMateriaSource {
	private:
		int count_;
	
	public:
		static const int MATERIA_MAX = 4;
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		MateriaSource &operator=(const MateriaSource &copy);
		~MateriaSource();

		void learnMateria(AMateria *m);
		AMateria *createMateria(const std::string &type);
	
	private:
		AMateria *materias_[MATERIA_MAX];
};

#endif
