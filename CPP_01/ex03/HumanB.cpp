/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:12:07 by ksudyn            #+#    #+#             */
/*   Updated: 2026/01/05 15:51:38 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL)
{
    std::cout << name << " HumanB Constructor" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << " HumanB Destructor" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack() const
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon " << std::endl;
}
//weapon->getType() en puntero / weapon.getType() en referencia.
//sintaxis diferente porque uno es puntero, otro referencia