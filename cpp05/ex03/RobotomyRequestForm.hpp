/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:16:59 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/27 16:28:32 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <math.h>
#include "AForm.hpp"

class	RobotomyRequestForm : public AForm{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm & cpy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm & rhs);
		~RobotomyRequestForm();

		void	execute(const Bureaucrat &executor) const;
};
