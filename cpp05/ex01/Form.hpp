/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:38:03 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/23 15:35:18 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Form
{
private:
	const std::string	_name;
	bool				_sign{false};
	const int			_grade_signed;
	const int			_grade_exec;	
public:
	Form();
	Form(const std::string &name, int grade_signed, int grade_exec);
	Form(const Form & cpy);
	Form & operator=(const Form & rhs);
	~Form();

	std::string	getName() const;
	bool		getSign() const;
	int			getGradeSigned() const;
	int			getGradeExec() const;

	class	GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, const Form & form);
