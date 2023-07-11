/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:34:39 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/11 17:54:17 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm(target,
																				   GRADE_TO_SIGN,
																				   GRADE_TO_EXEC),
																			 		_formType("RobotomyRequestForm") {
	if (VERBOSE) {
		std::cout << COLOR_GREEN << "[RobotomyRequestForm] " << COLOR_DEFAULT
				  << "Default Constructor called " << COLOR_YELLOW << "GradeToSign: " << getGradeToSign() << COLOR_DEFAULT
				  << COLOR_CYAN << " GradeToExec: "  << getGradeToExec() << COLOR_DEFAULT
				  << " type: " << RobotomyRequestForm::getFormType() << std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _formType("RobotomyRequestForm") {
	if (VERBOSE) {
		std::cout << COLOR_GREEN << "[RobotomyRequestForm] " << COLOR_DEFAULT
				  << "Copy Constructor called " << COLOR_YELLOW << src.getName() << COLOR_DEFAULT
				  << " " << COLOR_CYAN << src.getFormType() << COLOR_DEFAULT << std::endl;
	}
	*this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
	if (VERBOSE) {
		std::cout << COLOR_GREEN << "[RobotomyRequestForm] " << COLOR_DEFAULT
				  << "Assignment Constructor called " << "name: " << COLOR_YELLOW << rhs.getName() << COLOR_DEFAULT
				  << " type: " << COLOR_CYAN << rhs.getFormType() << COLOR_DEFAULT << std::endl;
	}
	if (this != &rhs) {
		AForm::operator=(rhs);
		return *this;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (VERBOSE) {
		std::cout << COLOR_RED << "[RobotomyRequestForm] " << COLOR_DEFAULT
				  << "Destructor called " << std::endl;
	}
}

std::string const & RobotomyRequestForm::getFormType(void) const {
	return this->_formType;
}

void	RobotomyRequestForm::validExecution(Bureaucrat const & executor) const {
	int randomNumber = std::rand() % 2;
	std::cout << "...VVVrrrVVVrrr... *robotic drilling noise* ...VVrrrVvvrr..." << std::endl;
	if (randomNumber == 0)
		std::cout << COLOR_GREEN << this->getName() << " was robotomized successfully" << COLOR_DEFAULT << std::endl;
	else
		std::cout << COLOR_RED << "The robotomizer failed to robotomize " << this->getName() << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_GREEN << executor.getName() << " executed " << this->getName() << " " << this->_formType << "\n" << COLOR_DEFAULT;
}