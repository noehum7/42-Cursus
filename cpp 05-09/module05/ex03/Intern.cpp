/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:17:51 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/14 12:17:52 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &copy)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	if (this == &copy)
		return(*this);
	return(*this);
}

static AForm *createPresidentialPardonForm(std::string const &target){return (new PresidentialPardonForm(target));}
static AForm *createRobotomyRequestForm(std::string const &target){return (new RobotomyRequestForm(target));}
static AForm *createShrubberyCreationForm(std::string const &target){return (new ShrubberyCreationForm(target));}

AForm *Intern::makeForm(std::string const &form, std::string const &target)
{
	std::string const formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *(*formGenerator[])(std::string const &target) = {&createPresidentialPardonForm, &createRobotomyRequestForm, &createShrubberyCreationForm};
	
	for (int i = 0; i < 3; i++)
	{
		if (form == formNames[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return (formGenerator[i](target));
		}
	}
	std::cout << "Error: Form '" << form << "' doesn't exist." << std::endl;
	return (NULL);
}
