/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:56:19 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/08 16:49:54 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _gradeSign(150), _gradeExecute(150), _signed(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const &name, int grade_sign, int grade_execute) : _name(name), _gradeSign(grade_sign), _gradeExecute(grade_execute), _signed(false)
{
	std::cout << "Create Form " << this->_name << " with grade to sign " << this->_gradeSign << " and grade to execute " << this->_gradeExecute << std::endl;
	if (grade_sign < 1 || grade_execute < 1)
		throw Form::GradeTooHighException();
	else if (grade_sign > 150 || grade_execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy.getName()), _gradeSign(copy.getGradeSign()), _gradeExecute(copy.getGradeExecute()), _signed(copy.getIsSigned())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called " << this->_name << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

std::string const Form::getName() const {return (this->_name);}
int Form::getGradeExecute() const {return(this->_gradeExecute);}
int Form::getGradeSign() const {return(this->_gradeSign);}
bool Form::getIsSigned() const {return(this->_signed);}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low");
}

std::ostream &operator<<(std::ostream &stream, const Form &form)
{
	stream << "Form " << form.getName()
		   << ", with grade to sign " << form.getGradeSign()
		   << " and grade to execute " << form.getGradeExecute()
		   << " signed: "
		   << (form.getIsSigned() ? "yes" : "no");
	return (stream);
}
