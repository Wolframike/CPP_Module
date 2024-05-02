/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:18:53 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/02 22:33:32 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const Point & src);
		Point(const Fixed x, const Fixed y);
		Point &operator=(const Point &src);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
