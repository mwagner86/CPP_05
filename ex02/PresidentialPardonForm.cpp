/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:34:23 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/11 17:34:26 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm(target,
																				 GRADE_TO_SIGN,
																				 GRADE_TO_EXEC),
																				 _formType("PresidentialPardonForm") {
	if (VERBOSE) {
		std::cout << COLOR_GREEN << "[PresidentialPardonForm] " << COLOR_DEFAULT
				  << "Default Constructor called " << COLOR_YELLOW << "GradeToSign: " << getGradeToSign() << COLOR_DEFAULT
				  << COLOR_CYAN << " GradeToExec: "  << getGradeToExec() << COLOR_DEFAULT
				  << " type: " << PresidentialPardonForm::getFormType() << std::endl;
	}
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src), _formType("PresidentialPardonForm") {
	if (VERBOSE) {
		std::cout << COLOR_GREEN << "[PresidentialPardonForm] " << COLOR_DEFAULT
				  << "Copy Constructor called " << COLOR_YELLOW << src.getName() << COLOR_DEFAULT
				  << " " << COLOR_CYAN << src.getFormType() << COLOR_DEFAULT << std::endl;
	}
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs)
{
	if (VERBOSE) {
		std::cout << COLOR_GREEN << "[PresidentialPardonForm] " << COLOR_DEFAULT
				  << "Assignment Constructor called " << "name: " << COLOR_YELLOW << rhs.getName() << COLOR_DEFAULT
				  << " type: " << COLOR_CYAN << rhs.getFormType() << COLOR_DEFAULT << std::endl;
	}
	if (this != &rhs) {
		AForm::operator=(rhs);
		return *this;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (VERBOSE) {
		std::cout << COLOR_RED << "[PresidentialPardonForm] " << COLOR_DEFAULT
				  << "Destructor called " << std::endl;
	}
}

std::string const & PresidentialPardonForm::getFormType(void) const {
	return this->_formType;
}

void	PresidentialPardonForm::validExecution(Bureaucrat const & executor) const {
	std::cout << COLOR_GREEN << this->getName() << " has been pardoned by Zaphod Beeblebrox\n";
	std::cout << executor.getName() << " executed " << this->getName() << " " << this->_formType << "\n" << COLOR_DEFAULT;
}
