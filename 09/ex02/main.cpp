/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:01:44 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/08 21:56:33 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc == 1)
		return 0;
	
	size_t lenMax = 0;
	int max = INT_MAX;
	while (max != 0) {
		max /= 10;
		lenMax++;
	}
	
	size_t len;
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++) {
			if (!std::isdigit(argv[i][j])) {
				std::cout << "Error" << std::endl;
				return 1;
			}
		}
		len = std::strlen(argv[i]);
		if (len > lenMax || len == 0) {
			std::cout << "Error" << std::endl;
			return 1;
		}
	}
	
	std::string str;
	for (int i = 1; i < argc; i++) {
		str += argv[i];
		if (i + 1 < argc)
			str += " ";
	}

	PmergeMe p;
	try {
		p.sort(str);
	} catch (std::invalid_argument &e) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	
	return 0;
}
