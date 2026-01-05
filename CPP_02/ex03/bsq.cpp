/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:21:39 by ksudyn            #+#    #+#             */
/*   Updated: 2026/01/05 16:05:21 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//bsp usará áreas (o vectores cruzados) para determinar si el punto está dentro del triángulo.
// Función auxiliar para calcular área del triángulo (en valor absoluto)
static float triangleArea(Point const &p1, Point const &p2, Point const &p3)
{
    Fixed term1;
    Fixed term2;
    Fixed term3;
    Fixed area;
    
    term1 = p1.getX() * (p2.getY() - p3.getY());
    term2 = p2.getX() * (p3.getY() - p1.getY());
    term3 = p3.getX() * (p1.getY() - p2.getY());

    area = (term1 + term2 + term3);
    if (area < Fixed(0))
        area = area * Fixed(-1);
    return (area / Fixed(2)).toFloat();
}
// Calcula el área de un triángulo usando la fórmula del determinante:
// Área=21​∣x1​(y2​−y3​)+x2​(y3​−y1​)+x3​(y1​−y2​)∣
// Usa la clase Fixed para todas las operaciones → mantiene la precisión de punto fijo.
// Convierte al final a float para devolver un valor estándar

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
    float ABC;
    float PBC;
    float APC;
    float ABP;
    
    ABC = triangleArea(a, b, c);
    PBC = triangleArea(p, b, c);
    APC = triangleArea(a, p, c);
    ABP = triangleArea(a, b, p);

    if (PBC + APC + ABP > ABC) // fuera
        return false;

    // en borde si alguna subárea es prácticamente cero
    if (roundf(PBC) == 0 || roundf(APC) == 0 || roundf(ABP) == 0)
        return false;

    return true; // dentro
}
// Calcula área del triángulo original ABC.
// Calcula área de los triángulos formados con el punto: PBC, APC, ABP.
// Suma de subáreas > área original → punto fuera.
// Alguna subárea = 0 → punto en un borde o vértice → falso.
// Si ninguna de esas condiciones se cumple → el punto está estrictamente dentro del triángulo
