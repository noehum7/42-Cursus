/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:10:20 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/10 18:10:28 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string const _target;
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		std::string getTarget() const;
		virtual void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm *src);
