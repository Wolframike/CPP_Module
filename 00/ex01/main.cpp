/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:54:16 by misargsy          #+#    #+#             */
/*   Updated: 2024/01/31 03:05:29 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string input;
	PhoneBook phonebook;

	phonebook.set_contact_count(0);
	phonebook.set_oldest_index(0);
	while (true)
	{
		if (std::cin.eof())
			break ;
		std::cout << "Enter command: ";
		std::getline(std::cin, input);
		if (input == "EXIT")
		{
			std::cout << "Goodbye" << std::endl;
			break ;
		}
		else if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else
			std::cout << "PhoneBook: " << input << ": invalid command" << std::endl;
		std::cout << std::endl;
		std::cin.clear();
	}
}
