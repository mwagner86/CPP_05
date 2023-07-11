//
// Created by max on 7/11/23.
//

#include "Intern.hpp"

Intern::Intern(void)
{
	if (VERBOSE) {
		std::cout << COLOR_GREEN << "[Intern] " << COLOR_DEFAULT
				  << "Default Constructor called " << std::endl;
	}
}

Intern::Intern(Intern const & input) {
	if (VERBOSE) {
		std::cout << COLOR_GREEN << "[Intern] " << COLOR_DEFAULT
				  << "Copy Constructor called" << std::endl;
	}
	*this = input;
}

Intern & Intern::operator=(const Intern & rhs)
{
	if (VERBOSE) {
		std::cout << COLOR_GREEN << "[Intern] " << COLOR_DEFAULT
				  << "Assignment Constructor called "  << COLOR_DEFAULT << std::endl;
	}
	if (this != &rhs)
		(void) rhs;
	return *this;
}

Intern::~Intern(void) {
	if (VERBOSE) {
		std::cout << COLOR_RED << "[Intern] " << COLOR_DEFAULT
				  << "Destructor called " << std::endl;
	}
}

AForm * Intern::makeForm(std::string const & type, std::string const & target) const
{
	std::string const forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	selectForm = -1;
	AForm * newForm = NULL;

	for (int i = 0; i < 3; i++)	{
		if (type == forms[i])
		{
			selectForm = i;
			break;
		}
	}
	switch (selectForm) {
		case 0:
			newForm = new ShrubberyCreationForm(target);
			std::cout << "Intern creates: <ShrubberyCreationForm>\n";
			break;
		case 1:
			newForm = new RobotomyRequestForm(target);
			std::cout << "Intern creates: <RobotomyRequestForm>\n";
			break;
		case 2:
			newForm = new PresidentialPardonForm(target);
			std::cout << "Intern creates: <PresidentialPardonForm>\n";
			break;
		default:
			std::cout << "Intern creates: " << COLOR_RED << "FAILED" << COLOR_DEFAULT << " Form <" << type << "> does not exist.\n";
			break;
	}
	return (newForm);
}