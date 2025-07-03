/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:53:46 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/18 16:53:47 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name) {
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
}

Character::Character(const Character& copy) {
	*this = copy;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] != NULL) {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
}

Character& Character::operator=(const Character& copy) {
    if (this != &copy) {
        this->_name = copy._name;
        for (int i = 0; i < 4; i++)
		{
            if (this->_inventory[i] != NULL)
                delete this->_inventory[i];
            this->_inventory[i] = copy._inventory[i];
        }
    }
    return (*this);
}

std::string const & Character::getName() const {return (this->_name);}

void Character::equip(AMateria* m) {
    if (m == NULL) return ;
    
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == NULL) {
            this->_inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
        this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL) {
        this->_inventory[idx]->use(target);
    }
}
