/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:27:29 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/11 17:33:43 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Bureaucrat] " << COLOR_DEFAULT
                  << "Default Constructor called " << COLOR_YELLOW << name << COLOR_DEFAULT
                  << " " << COLOR_CYAN << grade << COLOR_DEFAULT << std::endl;
    }
    if (grade > MINGRADE) {
        throw GradeTooLowException();
    }
    if (grade < MAXGRADE) {
        throw GradeTooHighException();
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name + "_copy") {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Bureaucrat] " << COLOR_DEFAULT
                  << "Copy Constructor called " << COLOR_YELLOW << src.getName() << COLOR_DEFAULT
                  << " " << COLOR_CYAN << src.getGrade() << COLOR_DEFAULT << std::endl;
    }
    *this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Bureaucrat] " << COLOR_DEFAULT
                  << "Assignment Constructor called " << COLOR_YELLOW << rhs.getName() << COLOR_DEFAULT
                  << " " << COLOR_CYAN << rhs.getGrade() << COLOR_DEFAULT << std::endl;
    }
    if (this != &rhs)
        this->_grade = rhs.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat(void) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Bureaucrat] " << COLOR_DEFAULT
                  << "Destructor called " << COLOR_YELLOW << this->getName() << COLOR_DEFAULT
                  << " " << COLOR_CYAN << this->getGrade() << COLOR_DEFAULT << std::endl;
    }
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

std::string const & Bureaucrat::getName(void) const {
    return this->_name;
}

// CAVE: increment grade == "--"
void	Bureaucrat::incrementGrade(void) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Bureaucrat] " << COLOR_ORANGE
                  << "incrementGrade() function called " << COLOR_YELLOW << this->getName() << COLOR_DEFAULT
                  << " " << COLOR_CYAN << this->getGrade() << COLOR_DEFAULT << std::endl;
    }
    if (this->_grade == Bureaucrat::MAXGRADE)
        throw GradeTooHighException();
    this->_grade--;
}

// CAVE: decrement grade == "++"
void	Bureaucrat::decrementGrade(void) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Bureaucrat] " << COLOR_BLUE
                  << "decrementGrade() function called " << COLOR_YELLOW << this->getName() << COLOR_DEFAULT
                  << " " << COLOR_MAGENTA << this->getGrade() << COLOR_DEFAULT << std::endl;
    }
    if (this->_grade == Bureaucrat::MINGRADE)
        throw GradeTooLowException();
    this->_grade++;
}

void	Bureaucrat::signForm(AForm & form) const {
    try {
        form.beSigned(*this);
        std::cout << COLOR_GREEN << this->_name << " signed " << form.getName() << COLOR_DEFAULT << std::endl;
    }
    catch (std::exception & e) {
        std::cout << COLOR_RED << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << COLOR_DEFAULT << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm & form) const {
    try {
        form.executeFromBureaucrat(*this);
    }
    catch (const std::exception& error) {
        std::cout   << COLOR_RED << this->_name << " couldn't execute "
                    << form.getName() << " " << form.getFormType() << " because "
                    << error.what() << "\n" << COLOR_DEFAULT;
    }
}

void Bureaucrat::executeFromForm(AForm const & form) const
{
    if (!form.getIsSigned())
        throw FormNotSignedException();
    if (this->_grade > form.getGradeToExec())
        throw GradeTooLowException();
    form.validExecution(*this);
}


std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i) {
    o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
    return o;
}
