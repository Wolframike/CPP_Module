/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:43:02 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/02 23:07:33 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap&		operator=(const ScavTrap &assign);
		~ScavTrap();

		void	attack(std::string const & target);
		void	guardGate();
};

#endif