/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:28:23 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/11 17:34:03 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {

	std::cout << "\n**************************************\n"
			  << "SHRUBBERY TEST 0\n" << "Grade too low for all\n"
			  << "**************************************\n";
	// Create a Bureaucrat
	Bureaucrat bureaucrat0("John Dull", 150);
	// Grade is low for everything

	// Create a ShrubberyCreationForm
	ShrubberyCreationForm form("Park");

	// Attempt to sign the form
	try {
		bureaucrat0.signForm(form);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while signing the form: " << e.what() << std::endl;
		return 1;
	}

	// Attempt to execute the form
	try {
		bureaucrat0.executeForm(form);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while executing the form: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n**************************************\n"
			  << "SHRUBBERY TEST 1\n" << "Grade too low for Exec\n"
			  << "**************************************\n";
	// Create a Bureaucrat
	Bureaucrat bureaucrat("John Doe", 139);
	// Grade is high enough to sign the form but not to execute it.

	// Attempt to sign the form
	try {
		bureaucrat.signForm(form);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while signing the form: " << e.what() << std::endl;
		return 1;
	}

	// Attempt to execute the form
	try {
		bureaucrat.executeForm(form);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while executing the form: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n**************************************\n"
			  << "SHRUBBERY TEST 2\n" << "valid Grade (but already signed)\n"
			  << "**************************************\n";
	// Create a valid Bureaucrat
	Bureaucrat Zaphod("Zaphod Beeblebrox", 1);
	// Grade is high enough to sign and execute it.

	// Attempt to sign the form
	try {
		Zaphod.signForm(form);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while signing the form: " << e.what() << std::endl;
		return 1;
	}

	// Attempt to execute the form
	try {
		Zaphod.executeForm(form);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while executing the form: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n**************************************\n"
			  << "SHRUBBERY TEST 3\n" << "Constructors\n"
			  << "**************************************\n";

	// Create a ShrubberyCreationForm
	ShrubberyCreationForm form1("Recreation Area");
	// Create a copy of the form using the copy constructor
	ShrubberyCreationForm form2(form1);
	// Create a third form and assign form1 to it using the assignment operator
	ShrubberyCreationForm form3("Backyard");
	form3 = form1;
	// Create a new Bureaucrat
	Bureaucrat bureaucrat3("Jane Doe", 50);

	try {
		// Sign the form with the bureaucrat
		bureaucrat3.signForm(form1);
		bureaucrat3.signForm(form2);
		bureaucrat3.signForm(form3);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while signing the form: " << e.what() << std::endl;
		return 1;
	}

	try {
		// Execute the forms
		bureaucrat3.executeForm(form1);
		bureaucrat3.executeForm(form2);
		bureaucrat3.executeForm(form3);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while executing the form: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n**************************************\n"
			  << "PARDON TEST 0\n" << "Grade too low for all\n"
			  << "**************************************\n";
	// Grade is low for everything
	// Create a PresidentialPardonForm
	PresidentialPardonForm misdemeanor("misdemeanor");

	// Attempt to sign the form
	try {
		bureaucrat0.signForm(misdemeanor);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while signing the form: " << e.what() << std::endl;
		return 1;
	}

	// Attempt to execute the form
	try {
		bureaucrat0.executeForm(misdemeanor);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while executing the form: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n**************************************\n"
			  << "PARDON TEST 1\n" << "Grade too low for Exec\n"
			  << "**************************************\n";
	// Create a Bureaucrat
	Bureaucrat PoliticalOfficer("Grand Moff Tarkin", 10);
	// Grade is high enough to sign the form but not to execute it.

	// Attempt to sign the form
	try {
		PoliticalOfficer.signForm(misdemeanor);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while signing the form: " << e.what() << std::endl;
		return 1;
	}

	// Attempt to execute the form
	try {
		PoliticalOfficer.executeForm(misdemeanor);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while executing the form: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n**************************************\n"
			  << "PARDON TEST 2\n" << "valid Grade (but already signed)\n"
			  << "**************************************\n";
	// Attempt to sign the form
	try {
		Zaphod.signForm(misdemeanor);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while signing the form: " << e.what() << std::endl;
		return 1;
	}

	// Attempt to execute the form
	try {
		Zaphod.executeForm(misdemeanor);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while executing the form: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n**************************************\n"
			  << "PARDON TEST 3\n" << "Constructors\n"
			  << "**************************************\n";

	// Create a PresidentialPardonForm
	PresidentialPardonForm felony1("Grand Theft Spaceship");
	// Create a copy of the form using the copy constructor
	PresidentialPardonForm felony2(felony1);
	// Create a third form and assign form1 to it using the assignment operator
	PresidentialPardonForm felony3("Arson");
	form3 = form1;
	// Create a new Bureaucrat
	Bureaucrat PoliticalOfficer2("Colonel Commissar Gaunt", 2);

	try {
		// Sign the form with the bureaucrat
		PoliticalOfficer2.signForm(felony1);
		PoliticalOfficer2.signForm(felony2);
		PoliticalOfficer2.signForm(felony3);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while signing the form: " << e.what() << std::endl;
		return 1;
	}

	try {
		// Execute the forms
		PoliticalOfficer2.executeForm(felony1);
		PoliticalOfficer2.executeForm(felony2);
		PoliticalOfficer2.executeForm(felony3);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while executing the form: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n**************************************\n"
			  << "ROBOTOMIZE TEST 0\n" << "Grade too low for all\n"
			  << "**************************************\n";
	// Grade is low for everything
	// Create a RobotomyRequestForm
	RobotomyRequestForm Servitor1("Criminal");

	// Attempt to sign the form
	try {
		bureaucrat0.signForm(Servitor1);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while signing the form: " << e.what() << std::endl;
		return 1;
	}

	// Attempt to execute the form
	try {
		bureaucrat0.executeForm(Servitor1);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while executing the form: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n**************************************\n"
			  << "ROBOTOMIZE TEST 1\n" << "Grade too low for Exec\n"
			  << "**************************************\n";
	// Create a Bureaucrat
	Bureaucrat TechPriest("TechPriest", 50);
	// Grade is high enough to sign the form but not to execute it.

	// Attempt to sign the form
	try {
		TechPriest.signForm(Servitor1);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while signing the form: " << e.what() << std::endl;
		return 1;
	}

	// Attempt to execute the form
	try {
		TechPriest.executeForm(Servitor1);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while executing the form: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n**************************************\n"
			  << "ROBOTOMIZE TEST 2\n" << "valid Grade\n"
			  << "**************************************\n";

	RobotomyRequestForm Servitor2("Xenos");
	RobotomyRequestForm Servitor3("Alien");
	RobotomyRequestForm Servitor4("Heretic");

	Bureaucrat GrandMagus("GrandMagus", 20);
	// Attempt to sign the form
	try {
		GrandMagus.signForm(Servitor2);
		GrandMagus.signForm(Servitor3);
		GrandMagus.signForm(Servitor4);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while signing the form: " << e.what() << std::endl;
		return 1;
	}

	// Attempt to execute the form
	try {
		GrandMagus.executeForm(Servitor1);
		GrandMagus.executeForm(Servitor2);
		GrandMagus.executeForm(Servitor3);
		GrandMagus.executeForm(Servitor4);
	} catch (const std::exception& e) {
		std::cout << "Exception occurred while executing the form: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
