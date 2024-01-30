/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:38:08 by misargsy          #+#    #+#             */
/*   Updated: 2024/01/31 03:08:50 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->contact_count = 0;
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::set_contact_count(unsigned short contact_count)
{
	this->contact_count = contact_count;
}

void	PhoneBook::set_oldest_index(unsigned short oldest_index)
{
	this->oldest_index = oldest_index;
}

unsigned short	PhoneBook::get_contact_count(void)
{
	return (this->contact_count);
}

unsigned short	PhoneBook::get_oldest_index(void)
{
	return (this->oldest_index);
}

void	PhoneBook::add(void)
{
	if (this->oldest_index == CONTACT_MAX)
		this->oldest_index = 0;

	std::cout << std::endl;
	std::string input;
	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	this->contacts[this->oldest_index].set_first_name(input);
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	this->contacts[this->oldest_index].set_last_name(input);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	this->contacts[this->oldest_index].set_nickname(input);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	this->contacts[this->oldest_index].set_phone_number(input);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	this->contacts[this->oldest_index].set_darkest_secret(input);
	if (this->contact_count < CONTACT_MAX)
		this->contact_count++;
	this->oldest_index++;
	std::cout << "Contact added" << std::endl;
}

static std::string	trim_string(std::string str)
{
	if (str.length() > COLUMN_LEN)
	{
		str.resize(COLUMN_LEN - 1);
		str.append(".");
	}
	return (str);
}

static void	display_single_contact(Contact contact, unsigned short index)
{
	std::cout << std::setw(COLUMN_LEN) << index << "|";
	std::cout << std::setw(COLUMN_LEN) << trim_string(contact.get_first_name()) << "|";
	std::cout << std::setw(COLUMN_LEN) << trim_string(contact.get_last_name()) << "|";
	std::cout << std::setw(COLUMN_LEN) << trim_string(contact.get_nickname()) << "|" << std::endl;
}

static void	display_contact_title(void)
{
	std::cout << std::setw(COLUMN_LEN) << "index" << "|";
	std::cout << std::setw(COLUMN_LEN) << "first name" << "|";
	std::cout << std::setw(COLUMN_LEN) << "last name" << "|";
	std::cout << std::setw(COLUMN_LEN) << "nickname" << "|" << std::endl;
}

void	PhoneBook::search(void)
{
	if (this->contact_count == 0)
		std::cout << "PhoneBook: no contacts registered" << std::endl;
	else
	{
		display_contact_title();
		for (unsigned short i = 0; i < this->contact_count; i++)
			display_single_contact(this->contacts[i], i);
	}
	unsigned int index;
	std::cout << "Enter index: ";
	std::cin >> index;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (index < this->contact_count)
	{
		std::cout << std::setw(DISPLAY_LEN) << "First name: " << this->contacts[index].get_first_name() << std::endl;
		std::cout << std::setw(DISPLAY_LEN) << "Last name: " << this->contacts[index].get_last_name() << std::endl;
		std::cout << std::setw(DISPLAY_LEN) << "Nickname: " << this->contacts[index].get_nickname() << std::endl;
		std::cout << std::setw(DISPLAY_LEN) << "Phone number: " << this->contacts[index].get_phone_number() << std::endl;
		std::cout << std::setw(DISPLAY_LEN) << "Darkest secret: " << this->contacts[index].get_darkest_secret() << std::endl;
	}
	else
		std::cout << "PhoneBook: " << index << ": index out of range" << std::endl;
}
