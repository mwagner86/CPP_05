/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:31:01 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/12 00:31:05 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	// Create Bureaucrat to interact with fresh forms
	Bureaucrat bureaucrat("Fry", 100);
	// RobotomyRequestForm from Subject
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf) {
		try {
			bureaucrat.signForm(*rrf);
			bureaucrat.executeForm(*rrf);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete rrf;
	}

	Bureaucrat LordCommander("Roboute Guilliman", 2);
	// Create different forms using the makeForm function
	AForm *scf1 = someRandomIntern.makeForm("shrubbery creation", "Garden World");
	AForm *rrf2 = someRandomIntern.makeForm("robotomy request", "Criminal");
	AForm *ppf1 = someRandomIntern.makeForm("presidential pardon", "Inquisitor Eisenhorn");
	AForm *form4 = someRandomIntern.makeForm("invalid form", "not found");

	// Use the created forms (if they exist)
	if (scf1) {
		try {
			LordCommander.signForm(*scf1);
			LordCommander.executeForm(*scf1);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete scf1;
	}

	if (rrf2) {
		try {
			LordCommander.signForm(*rrf2);
			LordCommander.executeForm(*rrf2);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete rrf2;
	}

	if (ppf1) {
		try {
			LordCommander.signForm(*ppf1);
			LordCommander.executeForm(*ppf1);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete ppf1;
	}

	if (form4) {
		// form4 is NULL since an invalid form type was passed
		delete form4; // not required, since null.
	}

	return (0);
}
