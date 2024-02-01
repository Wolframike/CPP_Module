/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:23:17 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/01 18:33:44 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sifl.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return 1;
	}

	Sifl sifl(argv[1]);
	sifl.replace(argv[2], argv[3]);

	return 0;
}