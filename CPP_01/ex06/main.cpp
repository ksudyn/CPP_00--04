/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:15:05 by ksudyn            #+#    #+#             */
/*   Updated: 2026/01/05 16:01:32 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum Level
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    UNKNOWN
};

Level getLevel(std::string level)
{
    if (level == "DEBUG") return DEBUG;
    if (level == "INFO") return INFO;
    if (level == "WARNING") return WARNING;
    if (level == "ERROR") return ERROR;
    return UNKNOWN;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./harlFilter <LEVEL>" << std::endl;
        return 1;
    }

    Harl harl;
    Level level = getLevel(argv[1]);

    switch(level)
    {
        case DEBUG:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
        case INFO:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
        case WARNING:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
        case ERROR:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }

    return 0;
}

// switch evalúa una expresión entera (en tu caso, el enum level).
// case es cada valor posible. Si coincide, se ejecuta ese bloque.
// default es el bloque que se ejecuta si ningún case coincide.
// Por defecto, después de ejecutar un case, el switch se “rompe” (termina).
// Si quieres que siga ejecutando el siguiente case, usas [[fallthrough]]
// (o simplemente no pones break; en C++98).
//Permite que un case siga ejecutando el siguiente sin break,
//útil para “desde este nivel en adelante”.