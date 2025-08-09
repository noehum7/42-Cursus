/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:49:50 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/07 12:53:51 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	std::cout << "Create Bureaucrat " << this->_name << " with grade " << grade << std::endl;
	this->_setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called " << this->_name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_grade = copy.getGrade();
	return (*this);
}

std::string const Bureaucrat::getName() const{return (this->_name);}
int Bureaucrat::getGrade() const{return (this->_grade);}

void Bureaucrat::_setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	this->_setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	this->_setGrade(this->_grade + 1);
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;

	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low");
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (stream);
}
