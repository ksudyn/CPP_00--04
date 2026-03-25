/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:03:00 by ksudyn            #+#    #+#             */
/*   Updated: 2026/03/25 02:14:06 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap:: DiamondTrap() : ClapTrap() , ScavTrap() , FragTrap()
{
    this->name = "KUKU";
    ClapTrap::Name = name + "_clap_name";
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 30;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(std::string name ): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    ScavTrap scav;
    FragTrap frag;
    
    this->name = name;
	this->setHitPoints(frag.getHitPoints());
	this->setEnergyPoints(scav.getEnergyPoints());
	this->setAttackDamage(frag.getAttackDamage());

    std::cout << "HitPoint de DiamondTrap " << HitPoints << std::endl;
    std::cout << "EnergyPoint de DiamondTrap " << EnergyPoints << std::endl;
    std::cout << "AttackDamage de DiamondTrap  " << AttackDamage << std::endl;

    std::cout << "DiamondTrap " << this->name << " has been created!" << std::endl;
}

DiamondTrap& DiamondTrap:: operator=(const DiamondTrap& before)
{
    if(this != &before)//Buena practica para futuros proyectos
    {
        std::cout << "DiamondTrap copy assigment operator called" << std::endl;
        this->HitPoints = before.HitPoints;
        this->EnergyPoints = before.EnergyPoints;
        this->AttackDamage = before.AttackDamage;
        this->name = before.name;
    }
    return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& before)
{
    std::cout << "DiamonTrap copy constructor called" << std::endl;
	*this = before;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " has been destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);// usa el attack de ScavTrap
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->name 
              << " and my ClapTrap name is " << ClapTrap::Name << std::endl;
}
// Sirve para mostrar dos nombres diferentes:
// El nombre propio de DiamondTrap (DiamondTrap::name) → el que le das al constructor.
// El nombre de ClapTrap interno (ClapTrap::Name) → se inicializa con name + "_clap_name".