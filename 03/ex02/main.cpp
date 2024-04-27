/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:52:44 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/27 19:52:30 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap clap1("Clap");
	ClapTrap clap2("Trap");

	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAttackDamage());
	
	// keep attacking until clap1 run out of energy
	while (clap1.getEnergyPoints() > 0)
	{
		clap1.attack(clap2.getName());
		clap2.takeDamage(clap1.getAttackDamage());
	}
	
	//attack with no energy
	clap1.attack(clap2.getName());

	//gain attack damage and energy points
	clap1.setAttackDamage(2);
	clap1.setEnergyPoints(100);

	//attack until clap2 dies
	while (clap2.getHitPoints() > 0)
	{
		clap1.attack(clap2.getName());
		clap2.takeDamage(clap1.getAttackDamage());
	}

	//try attacking clap2
	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAttackDamage());

	//recover clap2 and attack again
	clap2.beRepaired(10);
	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAttackDamage());

	ScavTrap scav1("Scav");
	
	scav1.attack(clap1.getName());
	clap1.takeDamage(scav1.getAttackDamage());
	scav1.guardGate();

	FragTrap frag1("Frag");

	frag1.attack(scav1.getName());
	scav1.takeDamage(frag1.getAttackDamage());
	frag1.highFivesGuys();
	return (0);
}