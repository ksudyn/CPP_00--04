/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:32:09 by ksudyn            #+#    #+#             */
/*   Updated: 2026/01/05 15:40:14 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->num_contact = 0;
	std::cout << "PhoneBook Constructor" <<std::endl;
} 

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructor" <<std::endl;
}

int PhoneBook::check_command(std::string input)
{
	size_t	i;
	int number;
	std::string index;

	i = 0;

	// === CASO 1: Comando "ADD" ===
	if (input == "ADD")
	{
		// Llama a la función que pide los datos al usuario
		if (contact[num_contact % 8].dat_contact(&num_contact) == 1)
			return (1);  // Si hubo error, salimos

		// Aumenta el número total de contactos
		this->num_contact++;

		std::cout << "NUM_CONTACT: " << num_contact << std::endl;
	}

	// === CASO 2: Comando "SEARCH" ===
	else if (input == "SEARCH")
	{
		// Imprime la lista de contactos guardados (máximo 8)
		while (i < num_contact && i < 8)
		{
			contact[i % 8].print_contact(i); // Imprime solo: índice, nombre, apellido, apodo
			i++;
		}

		// Pide al usuario que escriba el índice del contacto a mostrar
		std::cout << "    Enter index: ";
		std::getline(std::cin, index);// lees línea del usuario

		// Si el usuario presionó Ctrl+D (EOF), salimos
		if (std::cin.eof())//eof() significa end-of-file (fin de fichero).
		{
			std::cout << "\nEmpty " << input << std::endl;
			return (1);
		}

		// Convierte el índice escrito (texto) a número
		std::stringstream index_new(index);
		index_new >> number;

		// Valida el índice (entre 1 y 8, y que no pase del total de contactos)
		if (!(number > 0 && number <= 8) || static_cast<size_t>(number) > num_contact)
		{
			std::cout << "Wrong index" << std::endl;
			return (0);
		}

		// Si el índice es válido, imprime todos los detalles del contacto
		contact[(number - 1) % 8].print_table_contact();
	}

	// === CASO 3: Comando "EXIT" ===
	else if (input == "EXIT")
		return (1); // Salimos del programa

	// === Cualquier otro comando ===
	return (0); // No hace nada especial, vuelve a esperar comando
}

//Esta función recibe lo que el usuario escribe como comando
// ("ADD", "SEARCH", o "EXIT") y decide qué hacer en cada caso.
// Sirve como el controlador principal del programa: 
// ejecuta la acción correcta según la palabra ingresada.
// Variables usadas
// contact[8] → Es un arreglo de contactos (Contact) con máximo 8 posiciones.
// num_contact → Es un contador de cuántos contactos se han agregado en total.
// % 8 → Se usa para sobrescribir el contacto más antiguo cuando hay más de 8.
// std::stringstream → Se usa para convertir un texto (como "2") en número (como 2).

// Qué hace el % 8?
// Imagina que num_contact = 9, entonces:

// num_contact % 8 = 1
// → Guarda el nuevo contacto en person[1]
// Así, una vez llenas las 8 posiciones, empieza a sobrescribir desde el principio