/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:41:34 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 05:18:40 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::data_path_ = "data.csv";

BitcoinExchange::BitcoinExchange() : rates_() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : rates_(copy.rates_) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		rates_ = copy.rates_;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::setRates(void)
{
	std::ifstream file(data_path_);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::string date;
		double rate;
		std::stringstream ss(line);
		ss >> date;
		ss >> rate;
		Date d;
		std::sscanf(date.c_str(), "%hu-%hu-%hu", &d.year, &d.month, &d.day);
		rates_[d] = rate;
	}
	file.close();
}


void BitcoinExchange::printExchangeRate(const Date &d, const double amount) const {
}