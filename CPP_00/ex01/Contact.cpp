/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:31:44 by ksudyn            #+#    #+#             */
/*   Updated: 2026/01/05 15:42:22 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void)
{
    std::cout << "Contact Constructor" <<std::endl;
}
Contact::~Contact(void)
{
    std::cout << "Contact Destructor" <<std::endl;
}

void Contact:: print_table_contact(void)
{
	std::cout << "First_name: " << this->first_name <<std::endl;
	std::cout << "Last_name: " << this->last_name <<std::endl;
	std::cout << "Nickname: " << this->nick_name <<std::endl;
	std::cout << "Phone_number: " << this->phone_number <<std::endl;
	std::cout << "Dark_secret: " << this->dark_secret <<std::endl;
}
//Imprime toda la información del contacto.
//Usa std::cout para mostrar los datos en la consola.
//El this-> significa "de este contacto específico".
//Es como cuando pides todos los datos de una persona y te los dice uno por uno

int	Contact:: check_num_phone(const char *number)
{
	int i;

	if (strlen(number) != 9)
	{
		std::cout << "Wrong phone number" <<std::endl;
		return(1);
	}
	i = 0;
	while (number[i] != '\0')
	{
		if (!(number[i] >= '0' && number[i] <= '9'))
		{
			std::cout << "Wrong phone number" <<std::endl;
			return (1);
		}
		i++;
	}
	this->phone_number = atol(number);
	return (0);
}
//Verifica que el número de teléfono tenga exactamente 9 dígitos.
//Que todos los caracteres sean números (0–9).
//Si está mal, imprime "Wrong phone number" y devuelve 1 (error).
//Si está bien, guarda el número como entero (long) en this->phone_number 
//y devuelve 0 (todo ok).


void Contact:: print_col(std::string str,  int len_str)
{
	int spaces;
	int j = 0;
	int i = 0;

	spaces = 10 - len_str;
	while (i < spaces)
	{
		std::cout << " ";
		i++;
	}
	while (j < 9 && j < len_str)
	{
		std::cout << str[j++];
	}
	if (len_str >= 10)
		std::cout << ".";
}
//Imprime una columna de texto alineada a la derecha y truncada si es muy larga.
//Si el texto tiene más de 10 caracteres, muestra los primeros 9 y un ..
//Si tiene menos de 10, imprime espacios al inicio para que ocupe 10 posiciones.

void Contact:: print_contact(int i)
{
	std::stringstream index;

	index << (i +  1);
	print_col(index.str(), 1);
	std::cout << "|";
	print_col(this->first_name, first_name.length());
	std::cout << "|";
	print_col(this->last_name, last_name.length());
	std::cout << "|";
	print_col(this->nick_name, nick_name.length());
	std::cout << "\n";
}
// Imprime una línea con los datos del contacto, en columnas:
// índice (posición en la lista) | primer nombre | apellido | apodo.
// Ejemplo de salida:
//          1|  Fernando|   Gómez|  Fercho
// Usa la función print_col(...) para dar formato.
// Usa std::stringstream para convertir el índice a texto (ej: 1 → "1").
//funciona como un itoa mas flexible
//pero funciona con cualquier tipo de datos, no solo enteros.

int	Contact:: dat_contact(size_t *num_contact)
{
	std::string	input[5];
	std::string	types[5];

	types[0] = "    First_name";
	types[1] = "    Last_name";
	types[2] = "    Nickname";
	types[3] = "    Phone_number";
	types[4] = "    Dark_secret";
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << types[i] << ": ";
		std::getline(std::cin, input[i]);
		if (std::cin.eof())
		{
			std::cout << "\nEOF" <<std::endl;
			return (1);
		}
		if (input[i].empty())
		{
			std::cout << "Empty contact info" <<std::endl;
			(*num_contact)--;
			return (0);
		}
		if (i == 3)
		{
			if (check_num_phone(input[3].c_str()) == 1)
			{
				(*num_contact)--;
				return (0);
			}
		}
	}
	this->first_name = input[0];
	this->last_name = input[1];
	this->nick_name = input[2];
	this->dark_secret = input[4];
	return (0);
}
//Le pide al usuario que escriba los datos del contacto: nombre,
//apellido, apodo, número, secreto.
//Si algún campo está vacío, no lo guarda y descuenta uno del contador.
//Si el número es inválido, también cancela el guardado.

// Pide 5 datos uno por uno (std::getline).
// Si alguno está vacío → error.
// El número se valida con check_num_phone.
// Si todo va bien, guarda los datos en this->....

//	Ejemplo:
//     First_name: Pedro
//     Last_name: González
//     Nickname: Peter
//     Phone_number: 123456789
//     Dark_secret: Me da miedo el brócoli

// Usa un arreglo input[5]
//para guardar lo que el usuario escribe antes de ponerlo en los atributos del contacto