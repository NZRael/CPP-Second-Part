/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:54:13 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/27 15:55:37 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm & cpy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm & rhs);
		~ShrubberyCreationForm();

		void	execute(const Bureaucrat &executor) const;
};
