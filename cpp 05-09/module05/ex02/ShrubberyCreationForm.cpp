/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:11:24 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/10 18:11:42 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm parameter constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 145, 137), _target(copy.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called " << this->_target << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const{return (this->_target);}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else if (bureaucrat.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::string filename = this->_target + "_shrubbery";
		std::ofstream file(filename.c_str());
		file << "       /\\      " << std::endl;
		file << "      /  \\     " << std::endl;
		file << "     /    \\    " << std::endl;
		file << "    /______\\   " << std::endl;
		file << "        ||     " << std::endl;
		file << "        ||     " << std::endl;
		file << std::endl;
		file << "      /\\       " << std::endl;
		file << "     /  \\      " << std::endl;
		file << "    /    \\     " << std::endl;
		file << "   /______\\    " << std::endl;
		file << "  /        \\   " << std::endl;
		file << " /          \\  " << std::endl;
		file << "/____________\\ " << std::endl;
		file << "      ||       " << std::endl;
		file << "      ||       " << std::endl;
		file << std::endl;
		file << "        /\\     " << std::endl;
		file << "       /  \\    " << std::endl;
		file << "      /    \\   " << std::endl;
		file << "     /______\\  " << std::endl;
		file << "    /        \\ " << std::endl;
		file << "   /          \\" << std::endl;
		file << "  /____________\\" << std::endl;
		file << " /              \\" << std::endl;
		file << "/________________\\" << std::endl;
		file << "        ||       " << std::endl;
		file << "        ||       " << std::endl;
		file.close();
		std::cout << "Shrubbery has been created in " << filename << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm *src)
{
	std::string isSigned = src->getIsSigned() ? " is signed" : " isn't signed";
	out << src->getName() << isSigned;
	out << ". Sign-grade: " << src->getGradeSign();
	out << ", execution-grade " << src->getGradeExecute() << std::endl;
	return (out);
}
