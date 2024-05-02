/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:31:52 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/02 22:34:30 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void) {
	Point a(0, 0);
	Point b(0, 4);
	Point c(4, 0);

	Point p1(1, 1);
	Point p2(2, 2);
	Point p3(3, 3);
	Point p4(4, 4);
	Point p5(5, 5);

	std::cerr << "p1 is inside the triangle: " << bsp(a, b, c, p1) << std::endl;
	std::cerr << "p2 is inside the triangle: " << bsp(a, b, c, p2) << std::endl;
	std::cerr << "p3 is inside the triangle: " << bsp(a, b, c, p3) << std::endl;
	std::cerr << "p4 is inside the triangle: " << bsp(a, b, c, p4) << std::endl;
	std::cerr << "p5 is inside the triangle: " << bsp(a, b, c, p5) << std::endl;

	return 0;
}
