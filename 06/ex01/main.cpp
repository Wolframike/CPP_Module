/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 08:48:53 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/04 08:53:18 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <iostream>

int main(void) {
	Data data = {42, 'a', 'b'};

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << "Data: " << ptr->s1 << " " << ptr->c1 << " " << ptr->c2 << std::endl;

	return 0;
}
