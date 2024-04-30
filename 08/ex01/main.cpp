/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:07:26 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/30 22:31:19 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main(void) {
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
	} catch (std::length_error &e) {
		std::cerr << e.what() << std::endl;
	}

	Span big = Span(20000);

	//use container to add numbers
	std::vector<int> v(10000, 42);
	big.addNumber(v.begin(), v.end());
	
	big.addNumber(50000);
	
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;
	
	return 0;
}
