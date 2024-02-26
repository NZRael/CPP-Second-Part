/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:57:54 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/23 15:16:35 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat Default"){
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	std::cout << "Bureaucrat surcharged constructor called" << std::endl;
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & cpy) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = cpy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & rhs){
	if (this == &rhs)
		return *this;
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const{
	return (this->_name);
}

int	Bureaucrat::getGrade() const{
	return (this->_grade);
}

void	Bureaucrat::incGrade(){
	if (this->_grade == 1) throw GradeTooHighException();
	this->_grade--;
	std::cout << this->_name << " increased grade by 1, now grade is " << this->_grade << std::endl;
}

void	Bureaucrat::decGrade(){
	if (this->_grade == 150) throw GradeTooLowException();
	this->_grade++;
	std::cout << this->_name << " deacreased grade by 1, now grade is " << this->_grade << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Error : Grade cannot be higher than 1.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Error : Grade cannot be lower than 150.");
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat & bur){
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return (o);
}
