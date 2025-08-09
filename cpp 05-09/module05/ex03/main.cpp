/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:30:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/11 16:30:00 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    std::cout << "🎓 === Creating Intern === ✅" << std::endl;
    AForm *a; AForm *b; AForm *c;

    std::cout << std::endl;

    Intern someRandomIntern;
    std::cout << std::endl;

    std::cout << "🎖️ === Creating PresidentialPardonForm === ✅" << std::endl;
    a = someRandomIntern.makeForm("presidential pardon", "Arthur Dent"); 
    std::cout << std::endl;

    std::cout << "🤖 === Creating RobotomyRequestForm === ✅" << std::endl;
    b = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << std::endl;

    std::cout << "🌳 === Creating ShrubberyCreationForm === ✅" << std::endl;
    c = someRandomIntern.makeForm("shrubbery creation", "home");
    std::cout << std::endl;

    std::cout << "🚫 === Trying invalid form === ❌" << std::endl;
    someRandomIntern.makeForm("invalid form", "target");
    std::cout << std::endl;

    std::cout << "🗑️ === Cleaning up === ✅" << std::endl;
    if (a) 
    {
        std::cout << "✅ Deleting PresidentialPardonForm" << std::endl;
        delete a;
    }
    if (b) 
    {
        std::cout << "✅ Deleting RobotomyRequestForm" << std::endl;
        delete b;
    }
    if (c) 
    {
        std::cout << "✅ Deleting ShrubberyCreationForm" << std::endl;
        delete c;
    }

    std::cout << "\n🎉 === All tests completed! ===" << std::endl;
    return (0);
}
