/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:52:51 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/20 11:28:45 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "----- Basic Test -----" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;
    
    std::cout << "\n----- Array Test -----" << std::endl;
    const int arraySize = 4;
    Animal* animals[arraySize];
    
    for (int idx = 0; idx < arraySize; idx++)
    {
        if (idx < arraySize / 2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }
    
    for (int idx = 0; idx < arraySize; idx++)
        delete animals[idx];
    
    std::cout << "\n----- Deep Copy Test -----" << std::endl;
    Dog original;
    Dog copy = original;
    
    return 0;
}