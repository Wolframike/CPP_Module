/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 03:49:27 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/04 04:02:58 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type_("") {}

AMateria::AMateria(const std::string &type) : type_(type) {}

AMateria::AMateria(const AMateria &copy) : type_(copy.type_) {}

AMateria &AMateria::operator=(const AMateria &copy) {
	if (this == &copy)
		return *this;
	type_ = copy.type_;
	return *this;
}

AMateria::~AMateria() {}

const std::string &AMateria::getType() const {
	return type_;
}

void AMateria::use(ICharacter &target) {
	std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}
