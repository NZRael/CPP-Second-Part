/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:53:04 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/23 15:53:11 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Form Default"){
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const std::string &name, int grade_signed, int grade_exec) : _name(name){
	std::cout << "Form surcharged constructor called" << std::endl;
	// if (grade < 1) throw GradeTooHighException();
	// if (grade > 150) throw GradeTooLowException();
	// this->_grade = grade;
}

Form::Form(const Form & cpy) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = cpy;
}

Form &Form::operator=(const Form & rhs){
	if (this == &rhs)
		return *this;
	//this->_grade = rhs._grade;
	return (*this);
}

Form::~Form(){
	std::cout << "Form destructor called" << std::endl;
}

std::string	Form::getName() const{
	return (this->_name);
}

bool		Form::getSign() const{
	return (this->_sign);
}

int	Form::getGradeSigned() const{
	return (this->_grade_signed);
}

int	Form::getGradeExec() const{
	return (this->_grade_exec);
}


const char	*Form::GradeTooHighException::what() const throw(){
	return ("Error : Form Grade cannot be higher than 1.");
}

const char	*Form::GradeTooLowException::what() const throw(){
	return ("Error : Form Grade cannot be lower than 150.");
}

std::ostream	&operator<<(std::ostream &o, const Form & form){
	o << form.getName() << " form, grade required to sign: " << form.getGradeSigned() << ", grade required to execute: " << form.getGradeExec() << ", is signed: " << form.getSign();
	return (o);
}
