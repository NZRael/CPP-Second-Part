/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:11:37 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/19 15:15:51 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	std::cout << RED << "----- TESTS INVALID FORM CREATION-----" << RESET << std::endl << std::endl;
	try {
		Form f1("Something", 1, 0);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try {
		Form f2("Something", 1, 151);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	
	std::cout << std::endl << GREEN << "----- TESTS TO SIGN FORMS -----" << RESET << std::endl << std::endl;
	
	Bureaucrat abby("Abby", 75);
	
	Form state("State", 75, 150);
	Form presidential_form("Presidential", 74, 150);

	Form kuala_lumpur(state);
	Form united_states(presidential_form);

	std::cout << std::endl << YELLOW << "----- FORM STATUSES w COPIED -----" << RESET << std::endl << std::endl;
	std::cout << state << std::endl;
	std::cout << presidential_form << std::endl;

	std::cout << std::endl << kuala_lumpur << std::endl;
	std::cout << united_states << std::endl;

	std::cout << std::endl;
	
	abby.signForm(state);
	abby.signForm(presidential_form);

	std::cout << std::endl << MAGENTA << "----- FORM STATUSES w DEEP COPIED -----" << RESET << std::endl << std::endl;

	std::cout << state << std::endl;
	std::cout << presidential_form << std::endl;

	std::cout << std::endl;

	std::cout << kuala_lumpur << std::endl;
	std::cout << united_states << std::endl;
	
	std::cout << std::endl << GREEN << "----- PROMOTE ABBY TRY AGAIN -----" << RESET << std::endl << std::endl;
	abby.incGrade();

	try {
		presidential_form.beSigned(abby);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	abby.signForm(kuala_lumpur);
	abby.signForm(united_states);

	try {
		united_states.beSigned(abby);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << GREEN << "----- FROM STATUSES -----" << RESET << std::endl << std::endl;
	std::cout << state << std::endl
		<< presidential_form << std::endl
		<< kuala_lumpur << std::endl
		<< united_states << std::endl;

	std::cout << std::endl;
}
