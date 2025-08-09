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
#include "Form.hpp"

int main()
{
    std::cout << "🧑‍💼 === Test 1: Valid Bureaucrat creation === ✅" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 30);
        std::cout << "✅ " << alice << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "\n📄 === Test 2: Valid Form creation === ✅" << std::endl;
    try
    {
        Form form1("Tax Document", 50, 25);
        std::cout << "✅ " << form1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "\n🚫 === Test 3: Form with grade too high === ❌" << std::endl;
    try
    {
        Form form2("Invalid Form", 0, 25);
        std::cout << "❌ " << form2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "✅ Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n🚫 === Test 4: Form with grade too low === ❌" << std::endl;
    try
    {
        Form form3("Invalid Form", 50, 151);
        std::cout << "❌ " << form3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "✅ Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n✍️ === Test 5: Successful form signing === ✅" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 20);
        Form form4("License", 50, 25);
        
        std::cout << "📋 Before signing: " << form4 << std::endl;
        bob.signForm(form4);
        std::cout << "✅ After signing: " << form4 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "\n🔒 === Test 6: Failed form signing (grade too low) === ❌" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 100);
        Form form5("Top Secret", 10, 5);
        
        std::cout << "📋 Before attempt: " << form5 << std::endl;
        charlie.signForm(form5);
        std::cout << "📋 After attempt: " << form5 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "\n🎉 === All tests completed! ===" << std::endl;
    return (0);
}
