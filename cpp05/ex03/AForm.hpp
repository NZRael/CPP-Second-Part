/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:38:03 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/27 16:41:25 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

#define RESET "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_sign;
	const int			_grade_signed;
	const int			_grade_exec;	
public:
	AForm();
	AForm(const std::string &name, int grade_signed, int grade_exec);
	AForm(const AForm & cpy);
	AForm & operator=(const AForm & rhs);
	virtual ~AForm();

	std::string	getName() const;
	bool		getSign() const;
	int			getGradeSigned() const;
	int			getGradeExec() const;

	void	beSigned(const Bureaucrat &bur);

	virtual void	execute(const Bureaucrat &executor) const = 0;

	class	GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, const AForm & AForm);
