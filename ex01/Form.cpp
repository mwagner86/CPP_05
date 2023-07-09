/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:27:59 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/08 17:28:01 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const & name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Form] " << COLOR_DEFAULT
                  << "Default Constructor called " << COLOR_YELLOW << name << COLOR_DEFAULT
                  << " " << COLOR_CYAN << gradeToSign << COLOR_DEFAULT
                  << " " << COLOR_ORANGE << gradeToExec << COLOR_DEFAULT <<std::endl;
    }
    if (gradeToSign > MINGRADE || gradeToExec > MINGRADE) {
        throw GradeTooLowException();
    }
    if (gradeToSign < MAXGRADE || gradeToExec < MAXGRADE) {
        throw GradeTooHighException();
    }
    this->_isSigned = false;
}

Form::Form(Form const & src) : _name(src._name + "_copy"), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Form] " << COLOR_DEFAULT
                  << "Copy Constructor called " << COLOR_YELLOW << src.getName() << COLOR_DEFAULT
                  << " " << COLOR_CYAN << src.getGradeToSign() << COLOR_DEFAULT
                  << " " << COLOR_ORANGE << src.getGradeToExec() << COLOR_DEFAULT << std::endl;
    }
    *this = src;
}

Form & Form::operator=(const Form & rhs) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Form] " << COLOR_DEFAULT
                  << "Copy Constructor called " << COLOR_YELLOW << rhs.getName() << COLOR_DEFAULT
                  << " " << COLOR_CYAN << rhs.getGradeToSign() << COLOR_DEFAULT
                  << " " << COLOR_ORANGE << rhs.getGradeToExec() << COLOR_DEFAULT << std::endl;
    }
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

Form::~Form(void) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Form] " << COLOR_DEFAULT
                  << "Destructor called " << COLOR_YELLOW << this->getName() << COLOR_DEFAULT
                  << std::endl;
    }
}

std::string const &	Form::getName(void) const {
    return this->_name;
}

bool	Form::getIsSigned(void) const {
    return this->_isSigned;
}

int	Form::getGradeToSign(void) const {
    return this->_gradeToSign;
}

int	Form::getGradeToExec(void) const {
    return this->_gradeToExec;
}

void	Form::beSigned(Bureaucrat const & src) {
    beSigned(&src);
}

void	Form::beSigned(Bureaucrat const * src) {
    if (this->_isSigned)
        throw FormAlreadySignedException();
    if (src->getGrade() <= this->_gradeToSign)
        this->_isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Form const & i) {
        o   << i.getName() << ", Form status: "
            << (i.getIsSigned() ? "signed" : "unsigned")
            << " - grade required to sign: " << i.getGradeToSign()
            << " - grade required to execute: " << i.getGradeToExec();
    return o;
}
