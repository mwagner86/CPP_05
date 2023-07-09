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

    if (gradeToSign > MINGRADE || gradeToExec > MINGRADE) {
        throw GradeTooLowException();
    }
    if (gradeToSign < MAXGRADE || gradeToExec < MAXGRADE) {
        throw GradeTooHighException();
    }
    this->_isSigned = false;
}

Form::Form(Form const & src) : _name(src._name + "_copy"), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {

    *this = src;
}

Form & Form::operator=(const Form & rhs) {
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

Form::~Form(void) {
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
