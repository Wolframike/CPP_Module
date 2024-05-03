/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 04:07:40 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/04 04:16:24 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count_(0) {}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	*this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
	if (this == &copy)
		return *this;
	count_ = copy.count_;
	for (int i = 0; i < count_; i++)
		materias_[i] = copy.materias_[i];
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < count_; i++)
		delete materias_[i];
}

void MateriaSource::learnMateria(AMateria *m) {
	if (count_ < MATERIA_MAX)
		materias_[count_++] = m;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < count_; i++)
		if (materias_[i]->getType() == type)
			return materias_[i]->clone();
	
	return 0;
}
