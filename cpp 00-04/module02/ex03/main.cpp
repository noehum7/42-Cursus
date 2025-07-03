/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:37:24 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/18 13:37:24 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 3);

	Point inside(2, 1);        // Inside
	Point outside(5, 5);       // Outside
	Point onEdge(2, 0);        // On an edge (base): Outside
	Point onVertex(0, 0);      // On a vertex: Outside

	std::cout << "BSP algorithm test with triangle at [(0,0), (4,0), (2,3)]:" << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "Point (2,1): " << (bsp(a, b, c, inside) ? "INSIDE" : "OUTSIDE") << std::endl;
	std::cout << "Point (5,5): " << (bsp(a, b, c, outside) ? "INSIDE" : "OUTSIDE") << std::endl;
	std::cout << "Point (2,0): " << (bsp(a, b, c, onEdge) ? "INSIDE" : "OUTSIDE") << std::endl;
	std::cout << "Point (0,0): " << (bsp(a, b, c, onVertex) ? "INSIDE" : "OUTSIDE") << std::endl;

	Point d(1.5f, 1.5f);
	Point e(-2.5f, 3.0f);
	Point f(1.0f, -1.0f);

	Point p1(0.5f, 1.0f);      // Inside
	Point p2(-1.0f, -1.0f);    // Outside

	std::cout << "\nTest with another triangle [(1.5,1.5), (-2.5,3.0), (1.0,-1.0)]:" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Point (0.5,1.0): " << (bsp(d, e, f, p1) ? "INSIDE" : "OUTSIDE") << std::endl;
	std::cout << "Point (-1.0,-1.0): " << (bsp(d, e, f, p2) ? "INSIDE" : "OUTSIDE") << std::endl;
	return (0);
}

/*
BSP Algorithm Visualization for Point (2,1) - INSIDE case:

Triangle vertices: A(0,0), B(4,0), C(2,3)
Test point: P(2,1)

       C(2,3)
       /|\
      / | \
     /  |  \
    /   P   \    <- P(2,1) is INSIDE
   /  (2,1)  \
  /           \
 /             \
A(0,0)--------B(4,0)

BSP Algorithm Steps:
1. Calculate sign for each edge relative to point P:
   - Edge AB: sign(P, A, B) = positive (P is above line AB)
   - Edge BC: sign(P, B, C) = positive (P is left of line BC) 
   - Edge CA: sign(P, C, A) = positive (P is right of line CA)

2. All signs are positive and non-zero:
   - has_neg = false (no negative values)
   - has_pos = true (all positive values)
   - No zeros (not on any edge)

3. Result: !(false && true) && true = true && true = TRUE

Therefore: Point (2,1) is INSIDE the triangle.

Key insight: A point is inside when it's on the SAME SIDE of all three edges,
and not exactly ON any edge (which would give sign = 0).
*/
