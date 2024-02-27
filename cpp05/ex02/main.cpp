/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:22:12 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/27 16:41:18 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	srand(time(NULL));
	std::cout << GREEN << "----- BUREAUCRATS CREATION-----" << RESET << std::endl << std::endl;

	Bureaucrat	noob = Bureaucrat("Noob Nathan", 142);
	Bureaucrat	average = Bureaucrat("Average Andy", 65);
	Bureaucrat	pro = Bureaucrat("Pro Peter", 6);

	std::cout << std::endl << "Three bureaucrats created:\n"
			"\t1) " << noob << "\n"
			"\t2) " << average << "\n"
			"\t3) " << pro << std::endl << std::endl;

	std::cout << RED << "----- FORMS CREATION-----" << RESET << std::endl << std::endl;
	
	ShrubberyCreationForm	shrubForm = ShrubberyCreationForm("Forest");
	RobotomyRequestForm		robotomyForm("RobotForm");
	PresidentialPardonForm	pardonForm("PardonForm");

	std::cout << std::endl << "Three forms created:\n"
			"\t1) " << shrubForm << "\n"
			"\t2) " << robotomyForm << "\n"
			"\t3) " << pardonForm << std::endl << std::endl;

	std::cout << YELLOW << "----- SIGNING AND EXECUTING SHRUBBERY FORM-----" << RESET << std::endl << std::endl;

	noob.signForm(shrubForm);
	noob.executeForm(shrubForm);
	average.executeForm(shrubForm);
	std::cout << std::endl;

	std::cout << GREEN << "----- SIGNING AND EXECUTING ROBOTOMY REQUEST FORM-----" << RESET << std::endl << std::endl;
	average.executeForm(robotomyForm);
	average.signForm(robotomyForm);
	average.executeForm(robotomyForm);
	
	pro.executeForm(robotomyForm);
	std::cout << std::endl;
	
	std::cout << MAGENTA << "----- SIGNING AND EXECUTING PRESIDENTIAL PARDON FORM-----" << RESET << std::endl << std::endl;
	pro.executeForm(pardonForm);
	pro.signForm(pardonForm);
	pro.executeForm(pardonForm);
	pro.incGrade();
	pro.executeForm(pardonForm);

	std::cout << std::endl;
	return (0);
}
