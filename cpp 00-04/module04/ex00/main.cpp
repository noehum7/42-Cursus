/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:52:19 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/18 16:52:20 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() 
{ 
    const Animal* meta = new Animal(); 
    const Animal* j = new Dog(); 
    const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl; 
    std::cout << i->getType() << " " << std::endl; 
    i->makeSound(); 
    j->makeSound(); 
    meta->makeSound();
 
    delete meta; 
    delete j; 
    delete i;

    std::cout << "\n----- Testing WrongAnimal and WrongCat -----\n" << std::endl;
    
    WrongAnimal *wrongAnimal = new WrongAnimal();
    WrongAnimal *wrongCat = new WrongCat();
    
    std::cout << wrongAnimal->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongAnimal->makeSound();
    wrongCat->makeSound();
    
    WrongCat* realWrongCat = new WrongCat();
    realWrongCat->makeSound();

    delete wrongAnimal;
    delete wrongCat;
    delete realWrongCat;
    return (0);
}
