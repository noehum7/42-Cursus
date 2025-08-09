/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:56:19 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/10 17:38:36 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _gradeSign(150), _gradeExecute(150), _signed(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(std::string const &name, int grade_sign, int grade_execute) : _name(name), _gradeSign(grade_sign), _gradeExecute(grade_execute), _signed(false)
{
	std::cout << "Create Form " << this->_name << " with grade to sign " << this->_gradeSign << " and grade to execute " << this->_gradeExecute << std::endl;
	this->checkGrades(grade_sign, grade_execute);
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _gradeSign(copy.getGradeSign()), _gradeExecute(copy.getGradeExecute()), _signed(copy.getIsSigned())
{
	std::cout << "Form copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form destructor called " << this->_name << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	return (*this);
}

std::string const AForm::getName() const {return (this->_name);}
int AForm::getGradeExecute() const {return(this->_gradeExecute);}
int AForm::getGradeSign() const {return(this->_gradeSign);}
bool AForm::getIsSigned() const {return(this->_signed);}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_signed)
		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because it's already signed" << std::endl;
	else
		this->_signed = true;
}

void	AForm::checkGrades(int gradeSign, int executeSign)
{
	if (gradeSign < 1 || executeSign < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150 || executeSign > 150)
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form needs to be signed before executing");
}

std::ostream &operator<<(std::ostream &stream, const AForm &form)
{
	stream << "Form " << form.getName()
		   << ", with grade to sign " << form.getGradeSign()
		   << " and grade to execute " << form.getGradeExecute()
		   << " signed: "
		   << (form.getIsSigned() ? "yes" : "no");
	return (stream);
}
