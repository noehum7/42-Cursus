/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:56:21 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/07 13:05:52 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExecute;
		bool				_signed;
	
	public:
		Form();
		Form(std::string const &name, int grade_sign, int grade_execute);
		Form(const Form &copy);
		~Form();
		Form &operator=(const Form &copy);
		std::string const getName() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		bool getIsSigned() const;
		void beSigned(Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &stream, const Form &form);
