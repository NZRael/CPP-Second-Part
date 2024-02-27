/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:57:54 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/27 15:53:49 by sboetti          ###   ########.fr       */
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

Bureaucrat::Bureaucrat(const Bureaucrat & cpy) : _name(cpy._name), _grade(cpy._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
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

///////AFORM FUNCTION////////

void	Bureaucrat::signForm(AForm &form) const{
	try{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e){
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm &form) const{
	try{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e){
		std::cout << this->_name << " couldn't executed " << form.getName() << " because " << e.what() << std::endl;
	}
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
