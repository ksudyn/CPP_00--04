/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:51:36 by ksudyn            #+#    #+#             */
/*   Updated: 2026/01/05 15:34:09 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "iostream"
#include <cctype>

int main(int argc, char **argv)
{
    int i;
    int j;
    int len;

    i = 1;
    if(argc > 1)
    {
        while(i < argc)
        {
            j = 0;
            len = strlen(argv[i]);
            while(j <= len)
            {
                argv[i][j] = std::toupper(static_cast<unsigned char>(argv[i][j]));
                j++;
            }
            std::cout << argv[i];
            i++;
        }
        std::cout << "\n";
		return (0);
    }
    std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}

// std::cout significa Console Output (salida por consola)
// y es una variable del tipo ostream que pertenece al namespace std (standard).
// Lo usas para imprimir texto u otras cosas en la consola,
// parecido a printf() en C, pero más seguro y flexible.
//cout es un objeto(no una funcion) que representa la salida estándar.