/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:56:21 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/10 17:36:39 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExecute;
		bool				_signed;
	
	public:
		AForm();
		AForm(std::string const &name, int grade_sign, int grade_execute);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm &operator=(const AForm &copy);
		std::string const getName() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		bool getIsSigned() const;
		void beSigned(Bureaucrat &bureaucrat);
		void checkGrades(int gradeSign, int gradeExecute);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &stream, const AForm &form);
