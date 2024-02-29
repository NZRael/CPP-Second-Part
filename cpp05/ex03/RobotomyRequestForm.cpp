/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:16:57 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/27 16:32:03 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default"){
	std::cout << "Default constructor RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target){
	std::cout << "Constructor RobotomyRequestForm sucharged called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) : AForm(cpy), _target(cpy._target){
	std::cout << "Copy constructor RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs){
	if (this != &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Destructor RobotomyRequestForm called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	AForm::execute(executor);
	std::cout << "RobotomyRequestForm: Making some driling noise..." << std::endl;
	if (rand() % 2)
		std::cout << "RobotomyRequestForm: " << this->_target << " robotomization SUCCESSFULL!" << std::endl;
	else
		std::cout << "RobotomyRequestForm: " << this->_target << " robotomization FAILED!" << std::endl;
}
