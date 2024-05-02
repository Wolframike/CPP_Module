/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:19:56 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/02 22:30:50 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point &src) : x(src.getX()), y(src.getY()) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

Point &Point::operator=(const Point &src) {
	static_cast<void>(src);
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
	return this->x;
}

Fixed Point::getY() const {
	return this->y;
}
