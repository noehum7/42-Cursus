/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:54:09 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/18 16:54:10 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _templates[4];
		
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		virtual ~MateriaSource();
		MateriaSource& operator=(const MateriaSource& copy);
		
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif
