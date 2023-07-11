/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:27:59 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/08 17:28:01 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const & name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[AForm] " << COLOR_DEFAULT
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

AForm::AForm(AForm const & src) : _name(src._name + "_copy"), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[AForm] " << COLOR_DEFAULT
                  << "Copy Constructor called " << COLOR_YELLOW << src.getName() << COLOR_DEFAULT
                  << " " << COLOR_CYAN << src.getGradeToSign() << COLOR_DEFAULT
                  << " " << COLOR_ORANGE << src.getGradeToExec() << COLOR_DEFAULT << std::endl;
    }
    *this = src;
}

AForm & AForm::operator=(const AForm & rhs) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[AForm] " << COLOR_DEFAULT
                  << "Copy Constructor called " << COLOR_YELLOW << rhs.getName() << COLOR_DEFAULT
                  << " " << COLOR_CYAN << rhs.getGradeToSign() << COLOR_DEFAULT
                  << " " << COLOR_ORANGE << rhs.getGradeToExec() << COLOR_DEFAULT << std::endl;
    }
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

AForm::~AForm(void) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[AForm] " << COLOR_DEFAULT
                  << "Destructor called " << COLOR_YELLOW << this->getName() << COLOR_DEFAULT
                  << std::endl;
    }
}

void	AForm::executeFromBureaucrat(Bureaucrat const & executor) const
{
    if (!this->_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExec)
        throw GradeTooLowException();
    validExecution(executor);
}

void	AForm::execute(Bureaucrat const & executor) const {
    try {
        executor.executeFromForm(*this);
    }
    catch(std::exception & e) {
        std::cout   << COLOR_RED << executor.getName() << " couldn't execute "
                    << this->_name << " " << this->getFormType() << " because "
                    << e.what() << "\n" <<COLOR_DEFAULT;
    }
}

std::string const &	AForm::getName(void) const {
    return this->_name;
}

bool	AForm::getIsSigned(void) const {
    return this->_isSigned;
}

int	AForm::getGradeToSign(void) const {
    return this->_gradeToSign;
}

int	AForm::getGradeToExec(void) const {
    return this->_gradeToExec;
}

void AForm::beSigned(const Bureaucrat & src) {
    if (this->_isSigned)
        throw AFormAlreadySignedException();
    if (src.getGrade() <= this->_gradeToSign)
        this->_isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, AForm const & i) {
        o   << i.getName() << ", AForm status: "
            << (i.getIsSigned() ? "signed" : "unsigned")
            << " - grade required to sign: " << i.getGradeToSign()
            << " - grade required to execute: " << i.getGradeToExec();
    return o;
}
