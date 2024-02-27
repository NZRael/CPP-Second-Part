/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:24:42 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/27 16:33:52 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default"){
	std::cout << "Default constructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target){
	std::cout << "Constructor PresidentialPardonForm sucharged called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy) : AForm(cpy), _target(cpy._target){
	std::cout << "Copy constructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs){
	if (this != &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Destructor PresidentialPardonForm called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	AForm::execute(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
