/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:53:10 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/27 16:42:50 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default"){
	std::cout << "Default constructor ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){
	std::cout << "Constructor ShrubberCreationForm sucharged called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) : AForm(cpy), _target(cpy._target){
	std::cout << "Copy constructor ShrubberCreationForm called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs){
	if (this != &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Destructor ShrubberyCreationForm called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	//peut etre probleme avec try et catch
	AForm::execute(executor);
	std::ofstream file((this->_target + "_shrubbery").c_str());
	file << "               ,@@@@@@@," << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	file << "       |o|        | |         | |" << std::endl;
	file << "       |.|        | |         | |" << std::endl;
	file << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	file.close();
}
