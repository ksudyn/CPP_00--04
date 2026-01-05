/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:40:43 by ksudyn            #+#    #+#             */
/*   Updated: 2026/01/05 15:49:12 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie:: announce( void )
{
	std::cout << name <<": BraiiiiiiinnnzzzZ..." <<std::endl;
}

Zombie::Zombie( void )
{
	this->name = "";
	std::cout << name << " Zombie Constructor" <<std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << name << " Zombie Destructor" <<std::endl;
}

void Zombie:: put_name( std::string name )
{
	this->name = name;
}