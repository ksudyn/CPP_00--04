/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:04:16 by ksudyn            #+#    #+#             */
/*   Updated: 2026/03/25 02:11:43 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->Name = "KUKU";
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name)
{
    this->Name = name;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
    std::cout << "FragTrap " << Name << " has been created!" << std::endl;
}

FragTrap& FragTrap:: operator=(const FragTrap& before)
{
    if(this != &before)
    {
        std::cout << "FragTrap copy assigment operartor called" << std::endl;
        this->HitPoints = before.HitPoints;
        this->EnergyPoints = before.EnergyPoints;
        this->AttackDamage = before.AttackDamage;
        this->Name = before.Name; 
    }
    return(*this);
}

FragTrap::FragTrap(const FragTrap& before)
{
    std::cout <<  "FragTrap cpy constructor called" << std::endl;
    *this = before;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << Name << " has been destroyed!" << std::endl;
}


void FragTrap::attack(const std::string& target)
{
    if (HitPoints <= 0) {
        std::cout << "FragTrap " << Name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }
    if (EnergyPoints <= 0) {
        std::cout << "FragTrap " << Name << " has no energy left to attack!" << std::endl;
        return;
    }

    EnergyPoints--;

    std::cout << "FragTrap " << Name << " attacks " << target
              << ", causing " << AttackDamage << " points of damage!"
              << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " requests high fives!" << std::endl;
}