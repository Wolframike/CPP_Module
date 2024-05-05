/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:03:31 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 13:09:22 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <climits>

#include "Date.hpp"

class BitcoinExchange {
	private:
		static const std::string data_path_;

		std::map<Date, double> rates_;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		void setRates(void);
		void printExchangeRate(const Date &d, double amount) const;
		void processTextfile(const std::string &filename) const;
};

#endif
