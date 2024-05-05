/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:42:03 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 13:58:03 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date() : year(0), month(0), day(0) {}

Date::Date(unsigned short year, unsigned short month, unsigned short day) : year(year), month(month), day(day) {}

Date::Date(const Date &copy) : year(copy.year), month(copy.month), day(copy.day) {}

Date &Date::operator=(const Date &copy) {
	if (this != &copy)
	{
		year = copy.year;
		month = copy.month;
		day = copy.day;
	}
	return *this;
}

Date::~Date() {}

bool Date::operator==(const Date& other) const {
	return year == other.year && month == other.month && day == other.day;
}

bool Date::operator<(const Date& other) const {
	if (year < other.year)
		return true;
	if (year == other.year) {
		if (month < other.month)
			return true;
		if (month == other.month)
			return day < other.day;
	}
	return false;
}

bool Date::operator>(const Date& other) const {
	if (year > other.year)
		return true;
	if (year == other.year) {
		if (month > other.month)
			return true;
		if (month == other.month)
			return day > other.day;
	}
	return false;
}

bool Date::operator<=(const Date& other) const {
	return *this < other || *this == other;
}

bool Date::operator>=(const Date& other) const {
	return *this > other || *this == other;
}

bool Date::operator!=(const Date& other) const {
	return !(*this == other);
}

bool Date::isValid() const {
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 2) {
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			return day <= 29;
		return day <= 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return day <= 30;
	return true;
}

std::ostream &operator<<(std::ostream &out, const Date &d) {
	out << std::setfill('0')
		<< std::setw(4) << d.year << "-"
		<< std::setw(2) << d.month << "-"
		<< std::setw(2) << d.day;
	return out;
}

double Date::diff(const Date &a, const Date &b) {
	if (!a.isValid() || !b.isValid())
		throw std::invalid_argument("Error: bad date");
	double diff = 0;
	
	if (a.day < b.day)
		diff += b.day - a.day;
	else
		diff += a.day - b.day;

	if (a.month < b.month)
		diff += (b.month - a.month) * 30;
	else
		diff += (a.month - b.month) * 30;

	if (a.year < b.year)
		diff += (b.year - a.year) * 365;
	else
		diff += (a.year - b.year) * 365;
	return diff;
}
