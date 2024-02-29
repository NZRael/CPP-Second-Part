/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:50:46 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/28 14:40:17 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
	std::cout << "Constructor Intern called" << std::endl;
}

Intern::Intern(const Intern &cpy){
	std::cout << "Copy constructor Intern called" << std::endl;
	*this = cpy;
}

Intern	&Intern::operator=(const Intern &rhs){
	(void) rhs;
	return (*this);
}

Intern::~Intern(){
	std::cout << "Destructor Intern called" << std::endl;
}

AForm	*Intern::makeForm(std::string name, std::string target){
	std::string	form_info[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*formu[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	AForm		*form = NULL;

	for (int i = 0; i < 3; i++){
		if (form_info[i] == name){
			std::cout << "Intern creates " << name << std::endl;
			form = formu[i];
		}
		else
			delete formu[i];
	}
	if (!form)
		throw Intern::NotGoodName();
	return (form);
}

const char	*Intern::NotGoodName::what() const throw(){
	return ("Error : Not a good name...");
}
