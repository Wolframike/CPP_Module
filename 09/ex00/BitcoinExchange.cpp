/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:41:34 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/08 18:56:45 by misargsy         ###   ########.fr       */
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
	std::getline(file, line);
	if (line != "date,exchange_rate") {
		throw std::invalid_argument("Error: bad header in database, only 'date,exchange_rate' is allowed.");
		return;
	}
	
	double rate;
	Date date;
	int i;
	double y, m, d;
	while (std::getline(file, line))
	{
		i = std::sscanf(line.c_str(), "%lf-%lf-%lf,%lf", &y, &m, &d, &rate);
		if (i != 4) {
			std::cout << "Error: bad line" << std::endl;
			continue;
		}
		if (!((0 <= y && y <= USHRT_MAX) && (0 <= m && m <= USHRT_MAX) && (0 <= d && d <= USHRT_MAX))) {
			std::cout << "Error: bad date" << " => " << date << std::endl;
			continue;
		}
		date.setYear(y);
		date.setMonth(m);
		date.setDay(d);
		
		if (!date.isValid()) {
			std::cout << "Error: bad date" << " => " << date << std::endl;
			continue;
		}
		if (rate < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (rate > INT_MAX) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		
		rates_[date] = rate;
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
	
	std::getline(file, line);
	if (line != "date | value") {
		std::cout << "Error: bad header in input, only 'date | value' is allowed." << std::endl;
		return;
	}
	
	double amount;
	Date date;
	int i;
	double y, m, d;
	while (std::getline(file, line))
	{
		i = std::sscanf(line.c_str(), "%lf-%lf-%lf | %lf", &y, &m, &d, &amount);
		if (i != 4) {
			std::cout << "Error: bad line" << std::endl;
			continue;
		}
		if (!((0 <= y && y <= USHRT_MAX) && (0 <= m && m <= USHRT_MAX) && (0 <= d && d <= USHRT_MAX))) {
			std::cout << "Error: bad date" << " => " << date << std::endl;
			continue;
		}
		date.setYear(y);
		date.setMonth(m);
		date.setDay(d);
		
		if (!date.isValid()) {
			std::cout << "Error: bad date" << " => " << date << std::endl;
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
		printExchangeRate(date, amount);
	}

	file.close();
}