/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:33:17 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 14:08:08 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	try {
		exchange.setRates();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	exchange.processTextfile(argv[1]);
	
	return 0;
}