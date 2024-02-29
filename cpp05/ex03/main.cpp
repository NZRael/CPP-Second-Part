/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:22:12 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/29 11:00:06 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void sign_and_exec(AForm *form) {
	Bureaucrat highPriest = Bureaucrat("High priest", 1);

	highPriest.signForm(*form);
	highPriest.executeForm(*form);
}

int	main(void)
{
	std::cout << std::endl;
	std::cout << GREEN << "----- INTERN CREATE GOOD FORMS-----" << RESET << std::endl << std::endl;

	Intern bob = Intern();
	AForm *form;

try{
	form = bob.makeForm("presidential pardon", "forgive jacob");
	sign_and_exec(form);
	delete form;
	std::cout << std::endl;
}
catch(std::exception &e){
	std::cout << e.what() << std::endl;
}
try{
	form = bob.makeForm("robotomy request", "create terminator 2");
	sign_and_exec(form);
	delete form;
	std::cout << std::endl;
}
catch(std::exception &e){
	std::cout << e.what() << std::endl;
}

try{
	form = bob.makeForm("shrubbery creation", "amazon");
	sign_and_exec(form);
	delete form;
	std::cout << std::endl;
}
catch(std::exception &e){
	std::cout << e.what() << std::endl;
}

	std::cout << RED << "----- INTERN CREATE BAD FORMS-----" << RESET << std::endl << std::endl;
	try {
		form = bob.makeForm("presidential", ""); // can create but without target will be ""
		sign_and_exec(form);
		delete form;
		std::cout << std::endl;
		
		form = bob.makeForm("", "noname target"); // cannot create with "" no form name
		sign_and_exec(form);
		delete form;
		std::cout << std::endl;
		
		form = bob.makeForm("notarealform", ""); // cannot create with invalid form name
		sign_and_exec(form);
		delete form;		
		std::cout << std::endl;
		
	} catch (std::exception &err) {
		std::cout << "Failed with catch err: " << err.what() << std::endl;
	}
	return (0);
}
