/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:37:11 by ksudyn            #+#    #+#             */
/*   Updated: 2026/01/05 15:42:59 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>   // cout, cin
#include <string.h>     // std::string
#include <iomanip>    // setw, right
#include <limits>     // para limpiar el input buffer
#include <sstream>
#include <cstdlib>



//....Contact....//
//Representa a una persona en tu agenda.
//Guarda datos de una persona: nombre, apellido, apodo, teléfono, secreto.
//Tiene funciones para establecer (guardar) esos datos y para mostrarlos.
class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		long	phone_number;
		std::string	dark_secret;
    public:
		Contact(void);
		~Contact(void);
		void  print_table_contact(void);
		int	 check_num_phone(const char *number);
		void  print_col(std::string str,  int len_str);
		void  print_contact(int i);
		int	 dat_contact(size_t *num_contact);
};
//Los atributos son private porque no deben ser modificados directamente desde fuera.
//Las funciones públicas son la "interfaz" para interactuar con esos datos.

//....PhoneBook....//
class PhoneBook
{
	private:
		Contact contact[8];
	public:
		size_t	num_contact;

		PhoneBook(void);
		~PhoneBook(void);

		int check_command(std::string input);
};


#endif

//Una clase es como un molde para crear objetos que contienen datos
//(atributos) y funciones (métodos) que trabajan con esos datos.
// class NombreClase {
// private:
//     // variables que solo la clase puede usar internamente
// public:
//     // funciones que otros pueden usar
// };

// En relación a las clases, se podrían entender de forma parecida a los struct.
// Ambos pueden tener funciones y variables internas, así como partes públicas y privadas.

// En una class, si quieres acceder a una variable pública desde main, 
// necesitas crear primero un objeto de esa clase y luego acceder con el punto (.). 
// Por ejemplo:

// Contact contacto;
// contacto.nombre = "Juan";

// Sin embargo, si la variable o función es static y está en la parte pública, 
// puedes acceder directamente con el nombre de la clase usando :::

// Contact::contador_global = 5;
// Contact::mostrar_contador();

// Por otro lado, si una función está en la parte privada, 
// no puedes llamarla directamente desde main. 
// Solo puede ser usada dentro de la propia clase o por funciones amigas.
