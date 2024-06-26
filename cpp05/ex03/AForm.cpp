/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:53:04 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/19 16:19:01 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("AForm Default"), _sign(false), _grade_signed(150), _grade_exec(150){
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int grade_signed, int grade_exec) : _name(name), _sign(false), _grade_signed(grade_signed), _grade_exec(grade_exec){
	std::cout << "AForm surcharged constructor called" << std::endl;
	if (this->_grade_signed < 1 || this->_grade_exec < 1) throw GradeTooHighException();
	if (this->_grade_signed > 150 || this->_grade_exec > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm & cpy) : _name(cpy._name), _sign(cpy._sign), _grade_signed(cpy._grade_signed), _grade_exec(cpy._grade_exec) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm & rhs){
	if (this == &rhs)
		return *this;
	this->_sign = rhs._sign;
	return (*this);
}

AForm::~AForm(){
	std::cout << "AForm destructor called" << std::endl;
}

std::string	AForm::getName() const{
	return (this->_name);
}

bool		AForm::getSign() const{
	return (this->_sign);
}

int	AForm::getGradeSigned() const{
	return (this->_grade_signed);
}

int	AForm::getGradeExec() const{
	return (this->_grade_exec);
}

void	AForm::beSigned(const Bureaucrat &bur){
	if (bur.getGrade() > this->_grade_signed)
		throw GradeTooLowException();
	if (this->_sign != true)
		this->_sign = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (this->_sign == false)
		throw NotSignedException();
	else if (executor.getGrade() > this->_grade_exec)
		throw GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what() const throw(){
	return ("AForm Grade too high.");
}

const char	*AForm::GradeTooLowException::what() const throw(){
	return ("AForm Grade too low.");
}

const char	*AForm::NotSignedException::what() const throw(){
	return ("AForm is not signed...");
}

std::ostream	&operator<<(std::ostream &o, const AForm & AForm){
	o << AForm.getName() << " AForm, grade required to sign: " << AForm.getGradeSigned() << ", grade required to execute: " << AForm.getGradeExec() << ", is signed: " << AForm.getSign();
	return (o);
}
