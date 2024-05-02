/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:26:23 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/02 22:33:11 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	abc = (a.getX() - point.getX()) * (b.getY() - a.getY()) - (a.getY() - point.getY()) * (b.getX() - a.getX());
	Fixed	bca = (b.getX() - point.getX()) * (c.getY() - b.getY()) - (b.getY() - point.getY()) * (c.getX() - b.getX());
	Fixed	cab = (c.getX() - point.getX()) * (a.getY() - c.getY()) - (c.getY() - point.getY()) * (a.getX() - c.getX());

	return (abc >= 0 && bca >= 0 && cab >= 0) || (abc <= 0 && bca <= 0 && cab <= 0);
}

