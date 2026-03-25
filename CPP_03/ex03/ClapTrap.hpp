/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:56:22 by ksudyn            #+#    #+#             */
/*   Updated: 2026/03/25 02:07:44 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include "iostream"
# include "string.h"

class ClapTrap
{
    protected:
        std::string Name;// Nombre del ClapTrap
        int HitPoints;// Vida / salud actual
        int EnergyPoints;// Energía disponible para acciones
        int AttackDamage;// Daño que causa al atacar

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        	void			setName(const std::string& name);
        void			setHitPoints(unsigned int hitPoints);
        void			setEnergyPoints(unsigned int energyPoints);
        void			setAttackDamage(unsigned int attackDamage);

        std::string		getName() const;
        unsigned int	getHitPoints() const;
        unsigned int	getEnergyPoints() const;
        unsigned int	getAttackDamage() const;

};

#endif
