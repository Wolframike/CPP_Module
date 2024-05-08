/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:42:03 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/08 18:50:24 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date() : year_(0), month_(0), day_(0) {}

Date::Date(unsigned short year_, unsigned short month_, unsigned short day_) : year_(year_), month_(month_), day_(day_) {}

Date::Date(const Date &copy) : year_(copy.year_), month_(copy.month_), day_(copy.day_) {}

Date &Date::operator=(const Date &copy) {
	if (this != &copy)
	{
		year_ = copy.year_;
		month_ = copy.month_;
		day_ = copy.day_;
	}
	return *this;
}

Date::~Date() {}

unsigned short Date::getYear() const {
	return year_;
}

unsigned short Date::getMonth() const {
	return month_;
}

unsigned short Date::getDay() const {
	return day_;
}

void Date::setYear(unsigned short year) {
	year_ = year;
}

void Date::setMonth(unsigned short month) {
	month_ = month;
}

void Date::setDay(unsigned short day) {
	day_ = day;
}

bool Date::operator==(const Date& other) const {
	return year_ == other.year_ && month_ == other.month_ && day_ == other.day_;
}

bool Date::operator<(const Date& other) const {
	if (year_ < other.year_)
		return true;
	if (year_ == other.year_) {
		if (month_ < other.month_)
			return true;
		if (month_ == other.month_)
			return day_ < other.day_;
	}
	return false;
}

bool Date::operator>(const Date& other) const {
	if (year_ > other.year_)
		return true;
	if (year_ == other.year_) {
		if (month_ > other.month_)
			return true;
		if (month_ == other.month_)
			return day_ > other.day_;
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
	if (month_ < 1 || month_ > 12 || day_ < 1 || day_ > 31)
		return false;
	if (month_ == 2) {
		if (year_ % 4 == 0 && (year_ % 100 != 0 || year_ % 400 == 0))
			return day_ <= 29;
		return day_ <= 28;
	}
	if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)
		return day_ <= 30;
	return true;
}

std::ostream &operator<<(std::ostream &out, const Date &d) {
	out << std::setfill('0')
		<< std::setw(4) << d.getYear() << "-"
		<< std::setw(2) << d.getMonth() << "-"
		<< std::setw(2) << d.getDay();
	return out;
}

double Date::diff(const Date &a, const Date &b) {
	if (!a.isValid() || !b.isValid())
		throw std::invalid_argument("Error: bad date");
	double diff = 0;
	
	if (a.day_ < b.day_)
		diff += b.day_ - a.day_;
	else
		diff += a.day_ - b.day_;

	if (a.month_ < b.month_)
		diff += (b.month_ - a.month_) * 30;
	else
		diff += (a.month_ - b.month_) * 30;

	if (a.year_ < b.year_)
		diff += (b.year_ - a.year_) * 365;
	else
		diff += (a.year_ - b.year_) * 365;
	return diff;
}
