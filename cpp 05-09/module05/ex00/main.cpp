/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:49:55 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/07 12:55:04 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "🧑‍💼 === Test 1: Valid constructor === ✅" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 75);
        std::cout << "✅ " << bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "\n🚫 === Test 2: Grade too high === ❌" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 0);
        std::cout << "❌ " << alice << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "✅ Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n🚫 === Test 3: Grade too low === ❌" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 151);
        std::cout << "❌ " << charlie << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "✅ Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n📈 === Test 4: Increment/Decrement === ✅" << std::endl;
    try
    {
        Bureaucrat dave("Dave", 5);
        std::cout << "📊 Initial: " << dave << std::endl;
        
        dave.incrementGrade();
        std::cout << "⬆️ After increment: " << dave << std::endl;
        
        dave.decrementGrade();
        std::cout << "⬇️ After decrement: " << dave << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "\n⚠️ === Test 5: Increment out of range === ❌" << std::endl;
    try
    {
        Bureaucrat eve("Eve", 1);
        std::cout << "📊 Initial: " << eve << std::endl;
        eve.incrementGrade();
        std::cout << "❌ This should not print" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "✅ Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n⚠️ === Test 6: Decrement out of range === ❌" << std::endl;
    try
    {
        Bureaucrat frank("Frank", 150);
        std::cout << "📊 Initial: " << frank << std::endl;
        frank.decrementGrade();
        std::cout << "❌ This should not print" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "✅ Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n🎉 === All tests completed! ===" << std::endl;
    return (0);
}
