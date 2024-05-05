/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:41:34 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 14:07:37 by misargsy         ###   ########.fr       */
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
	if (!file.is_open()) {
		throw std::invalid_argument("Error: database missing.");
		return;
	}

	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line))
	{
		std::string date;
		double rate;
		Date d;
		std::sscanf(line.c_str(), "%hu-%hu-%hu,%lf", &d.year, &d.month, &d.day, &rate);
		if (!d.isValid())
			throw std::invalid_argument("Error: bad date in database.");
		rates_[d] = rate;
	}
	file.close();
}


void BitcoinExchange::printExchangeRate(const Date &d, const double amount) const {	
	std::map<Date, double>::const_iterator low = rates_.lower_bound(d);

	if (low->first > d) {
		if (low == rates_.begin()) {
			std::cout << "Error: no data available before this date." << std::endl;
			return;
		}
		low--;		
	}
	std::cout << d << " => " << amount << " = " << amount * low->second << std::endl;
}

void BitcoinExchange::processTextfile(const std::string &filename) const {
	std::ifstream file(filename);

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::string date;
	double amount;
	Date d;
	int i;
	
	std::getline(file, line); // skip header
	while (std::getline(file, line))
	{
		i = std::sscanf(line.c_str(), "%hu-%hu-%hu | %lf", &d.year, &d.month, &d.day, &amount);
		if (i != 4) {
			if (!d.isValid()) {
				std::cout << "Error: bad input" << " => " << d << std::endl;
				continue;
			}
			std::cout << "Error: unknown error." << std::endl;
			continue;
		}
		if (amount < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (amount > INT_MAX) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		printExchangeRate(d, amount);
	}

	file.close();
}