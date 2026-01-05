/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:32:56 by ksudyn            #+#    #+#             */
/*   Updated: 2026/01/05 15:44:12 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	input;

	while (1)
	{
		std::cout << "Enter line: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\nEmpty" << input <<std::endl;
			break ;
		}
		if (phone_book.check_command(input) == 1)
			return (1);
	}
	return (0);
}


//Ejemplo de uso
// c1r1s1% ./phoneBook
// Contact Constructor
// Contact Constructor
// Contact Constructor
// Contact Constructor
// Contact Constructor
// Contact Constructor
// Contact Constructor
// Contact Constructor
// PhoneBook Constructor
// Enter line: ADD
//     First_name: kon
//     Last_name: sud
//     Nickname: ko
//     Phone_number: 123456789
//     Dark_secret: cuki
// NUM_CONTACT: 1
// Enter line: ADD 
//     First_name: GRAC
//     Last_name: PER
//     Nickname: mentora
//     Phone_number: 453628190
//     Dark_secret: cab
// NUM_CONTACT: 2
// Enter line: SEARCH
//          1|       kon|       sud|        ko
//          2|      GRAC|       PER|   mentora
//     Enter index: EXIT
// Wrong index
// Enter line: 
// Empty
// PhoneBook Destructor
// Contact Destructor
// Contact Destructor
// Contact Destructor
// Contact Destructor
// Contact Destructor
// Contact Destructor
// Contact Destructor
// Contact Destructor
// c1r1s1% 