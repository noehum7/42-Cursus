/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:10:31 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/10 18:10:45 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm parameter constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45), _target(copy.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called " << this->_target << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const{return (this->_target);}

static int robotomy = 0;

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else 
	{
		std::cout << "* drilling noises *" << std::endl;
		if (robotomy++ % 2)
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "The robotomy failed" << std::endl;

	}
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm *src)
{
	std::string isSigned = src->getIsSigned() ? " is signed" : " isn't signed";
	out << src->getName() << isSigned;
	out << ". Sign-grade: " << src->getGradeSign();
	out << ", execution-grade " << src->getGradeExecute() << std::endl;
	return (out);
}
