/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 04:20:37 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/10 18:58:39 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_(""), count_(0) {}

Character::Character(const std::string &name) : name_(name), count_(0) {}

Character::Character(const Character &copy) {
	*this = copy;
}

Character &Character::operator=(const Character &copy) {
	if (this == &copy)
		return *this;
	name_ = copy.name_;
	count_ = copy.count_;
	for (int i = 0; i < count_; i++)
		materias_[i] = copy.materias_[i];
	return *this;
}

Character::~Character() {
	for (int i = 0; i < count_; i++)
		delete materias_[i];
}

const std::string &Character::getName() const {
	return name_;
}

void Character::equip(AMateria *m) {
	if (count_ < MateriaSource::MATERIA_MAX)
		materias_[count_++] = m;
	else
		throw std::runtime_error("Character can't equip more than 4 materias");
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= count_)
		throw std::runtime_error("Invalid index");
	for (int i = idx; i < count_ - 1; i++)
		materias_[i] = materias_[i + 1];
	count_--;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= count_)
		throw std::runtime_error("Invalid index");
	materias_[idx]->use(target);
}
