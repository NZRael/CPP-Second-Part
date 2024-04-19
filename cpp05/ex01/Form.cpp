/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:53:04 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/19 10:21:10 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Form Default"), _sign(false), _grade_signed(150), _grade_exec(150){
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const std::string &name, int grade_signed, int grade_exec) : _name(name), _sign(false), _grade_signed(grade_signed), _grade_exec(grade_exec){
	std::cout << "Form surcharged constructor called" << std::endl;
	if (this->_grade_signed < 1 || this->_grade_exec < 1) throw Form::GradeTooHighException();
	if (this->_grade_signed > 150 || this->_grade_exec > 150) throw Form::GradeTooLowException();
}

Form::Form(const Form & cpy) : _name(cpy._name), _grade_signed(cpy._grade_signed), _grade_exec(cpy._grade_exec) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form & rhs){
	if (this == &rhs)
		return *this;
	this->_sign = rhs._sign;
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

void	Form::beSigned(const Bureaucrat &bur){
	if (this->_sign == true)
		throw std::runtime_error("Form already signed.");
	if (bur.getGrade() > this->_grade_signed)
		throw GradeTooLowException();
	this->_sign = true;
}

const char	*Form::GradeTooHighException::what() const throw(){
	return ("Form Grade too high.");
}

const char	*Form::GradeTooLowException::what() const throw(){
	return ("Form Grade too low.");
}

std::ostream	&operator<<(std::ostream &o, const Form & form){
	o << form.getName() << " form, grade required to sign: " << form.getGradeSigned() << ", grade required to execute: " << form.getGradeExec() << ", is signed: " << form.getSign();
	return (o);
}
