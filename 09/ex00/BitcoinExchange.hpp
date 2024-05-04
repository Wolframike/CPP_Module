/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:03:31 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 05:17:39 by misargsy         ###   ########.fr       */
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

class BitcoinExchange
{
	private:
		typedef struct Date {
			unsigned short day;
			unsigned short month;
			unsigned short year;
		} Date;
		static const std::string data_path_;

		std::map<Date, double> rates_;

		typedef std::map<Date, double>::iterator iterator;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		void setRates(void);
		void printExchangeRate(const Date &d, double amount) const;
};

#endif
