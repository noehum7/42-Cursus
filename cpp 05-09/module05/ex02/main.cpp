/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:30:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/11 15:30:00 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

    std::cout << "\n🌳 === Test 2: ShrubberyCreationForm creation === ✅" << std::endl;
    try
    {
        ShrubberyCreationForm form1("home");
        std::cout << "✅ " << form1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "\n🤖 === Test 3: RobotomyRequestForm creation === ✅" << std::endl;
    try
    {
        RobotomyRequestForm form2("Bender");
        std::cout << "✅ " << form2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "\n🎖️ === Test 4: PresidentialPardonForm creation === ✅" << std::endl;
    try
    {
        PresidentialPardonForm form3("Arthur Dent");
        std::cout << "✅ " << form3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "\n✍️ === Test 5: Successful form signing === ✅" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 20);
        PresidentialPardonForm form4("Ford Prefect");
        
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
		PresidentialPardonForm form5("Trillian");
		
		std::cout << "📋 Before attempt: " << form5 << std::endl;
		charlie.signForm(form5);
		std::cout << "📋 After attempt: " << form5 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "❌ " << e.what() << std::endl;
	}

    std::cout << "\n🌳 === Test 7: Successful ShrubberyCreationForm execution === ✅" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 130);
        ShrubberyCreationForm form6("garden");
        
        std::cout << "📋 Before signing: " << form6 << std::endl;
        alice.signForm(form6);
        std::cout << "✅ After signing: " << form6 << std::endl;
        
        alice.executeForm(form6);
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "\n🤖 === Test 8: Successful RobotomyRequestForm execution === ✅" << std::endl;
    try
    {
        Bureaucrat dave("Dave", 40);
        RobotomyRequestForm form7("C3PO");
        
        std::cout << "📋 Before signing: " << form7 << std::endl;
        dave.signForm(form7);
        std::cout << "✅ After signing: " << form7 << std::endl;
        
        dave.executeForm(form7);
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "\n🎖️ === Test 9: Successful PresidentialPardonForm execution === ✅" << std::endl;
    try
    {
        Bureaucrat eve("Eve", 1);
        PresidentialPardonForm form8("Marvin");
        
        std::cout << "📋 Before signing: " << form8 << std::endl;
        eve.signForm(form8);
        std::cout << "✅ After signing: " << form8 << std::endl;
        
        eve.executeForm(form8);
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "\n🚫 === Test 10: Execute unsigned form === ❌" << std::endl;
    try
    {
        Bureaucrat frank("Frank", 1);
        ShrubberyCreationForm form9("park");
        
        std::cout << "📋 Form status: " << form9 << std::endl;
        frank.executeForm(form9);
    }
    catch (std::exception &e)
    {
        std::cout << "❌ " << e.what() << std::endl;
    }

	std::cout << "\n🎲 === Test 11: Multiple robotomy attempts === 🎲" << std::endl;
	try
	{
		Bureaucrat ivan("Ivan", 1);
		
		std::cout << "\n--- Attempt 1 ---" << std::endl;
		RobotomyRequestForm form1("Robot1");
		ivan.signForm(form1);
		ivan.executeForm(form1);
		
		std::cout << "\n--- Attempt 2 ---" << std::endl;
		RobotomyRequestForm form2("Robot2");
		ivan.signForm(form2);
		ivan.executeForm(form2);
		
		std::cout << "\n--- Attempt 3 ---" << std::endl;
		RobotomyRequestForm form3("Robot3");
		ivan.signForm(form3);
		ivan.executeForm(form3);
	}
	catch (std::exception &e)
	{
		std::cout << "❌ " << e.what() << std::endl;
	}

    std::cout << "\n🎉 === All tests completed! ===" << std::endl;
    return (0);
}
