/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:57:56 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/27 15:52:47 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

#define RESET "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class AForm;

class Bureaucrat
{
private:
	const	std::string _name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat & cpy);
	Bureaucrat & operator=(const Bureaucrat & rhs);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;

	void	incGrade();
	void	decGrade();

	void	signForm(AForm &form) const;
	void	executeForm(AForm &form) const;

	class	GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat & bur);
