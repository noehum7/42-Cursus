/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:37:36 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/18 13:37:36 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &copy);
		~Point();
		Point &operator=(const Point &copy);
		Fixed getX() const;
		Fixed getY() const;
};

bool	bsp(const Point& a, const Point& b, const Point& c, const Point& point);

#endif
