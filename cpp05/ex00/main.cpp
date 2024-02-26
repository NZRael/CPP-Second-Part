/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:11:37 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/23 12:47:36 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat bureaucrat1;

	std::cout << BLUE <<
	"------------------------------------------" << std::endl <<
	"               Initial Test "	 			<< std::endl <<
	"------------------------------------------" <<
	RESET << std::endl;
	for (int i = 149; i < 153; i++)
	{
		try
		{
			std::cout << "i = " << i << std::endl;
			bureaucrat1 = Bureaucrat("BOBBY", i);
			std::cout << GREEN << bureaucrat1 << RESET << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cout << RED << e.what() << "  " << RESET << std::endl;
			continue;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
			continue;
		}
	}
	for (int i = 2; i > -2; i--)
	{
		try
		{
			std::cout << "i = " << i << std::endl;
			bureaucrat1 = Bureaucrat("BOBBY", i);
			std::cout << GREEN << bureaucrat1 << RESET << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cout << RED << e.what() << "  " << RESET << std::endl;
			continue;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
			continue;
		}
	}
	std::cout << BLUE <<
	"------------------------------------------" << std::endl <<
	"             IncreaseGrade Test "	 			<< std::endl <<
	"------------------------------------------" <<
	RESET << std::endl;

	int i = 3;
	Bureaucrat bureaucrat2("ASHE", i);
	while (i > -1)
	{
		try
		{
			std::cout << "i = " << i << " -> " << i - 1 <<std::endl;
			bureaucrat2.incGrade();
			std::cout << GREEN << bureaucrat2 << RESET << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cout << RED << e.what() << "  " << RESET << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		i--;
	}

	std::cout << BLUE <<
	"------------------------------------------" << std::endl <<
	"             DecreaseGrade Test "	 			<< std::endl <<
	"------------------------------------------" <<
	RESET << std::endl;

	i = 148;
	Bureaucrat bureaucrat3("ANNA", i);
	while (i < 152)
	{
		try
		{
			std::cout << "i = " << i << " -> " << i + 1 <<std::endl;
			bureaucrat3.decGrade();
			std::cout << GREEN << bureaucrat3 << RESET << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cout << RED << e.what() << "  " << RESET << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		i++;
	}
	return	0;
}
