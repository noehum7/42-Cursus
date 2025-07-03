/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:53:25 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/20 11:30:25 by nporras-         ###   ########.fr       */
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
    
    std::cout << "\n----- Deep Copy Test -----" << std::endl;
    Dog original;
    original.getBrain()->setIdea(0, "Chase cats!");
    
    Dog copy = original;
    original.getBrain()->setIdea(0, "Chase squirrels!");
    
    std::cout << "Original: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy: " << copy.getBrain()->getIdea(0) << std::endl;
    
    return 0;
}