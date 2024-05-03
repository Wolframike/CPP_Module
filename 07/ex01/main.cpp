/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:37:31 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/04 04:58:06 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void iter(T *array, size_t size, void (*func)(const T&)) {
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}

void printSquare(const int &i) {
	std::cout << i * i << " ";
}

void printFirstLetter(const std::string &str) {
	std::cout << str[0] << " ";
}

int main(void) {
	int intArray[] = {1, 2, 3, 4, 5};
	std::string strArray[] = {"one", "two", "three", "four", "five"};

	std::cout << "intArray: ";
	::iter(intArray, 5, printSquare);

	std::cout << std::endl << "strArray: ";
	::iter(strArray, 5, printFirstLetter);

	std::cout << std::endl;
	return 0;
}
