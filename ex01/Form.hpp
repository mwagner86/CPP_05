/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:28:16 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/08 17:28:20 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "colors.hpp"

class Bureaucrat;

class Form {

public:

    Form(std::string const & name, int gradeToSign, int gradeToExec);
    Form(Form const & src);
    Form & operator=(Form const & rhs);
    ~Form(void);

    std::string const &	getName(void) const;
    bool				getIsSigned(void) const;
    int					getGradeToSign(void) const;
    int					getGradeToExec(void) const;

    void				beSigned(Bureaucrat const & src);
    void				beSigned(Bureaucrat const * src);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char * what() const throw() {
            return ("Form::GradeTooHighException");
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char * what() const throw() {
            return ("Form::GradeTooLowException");
        }
    };

    class FormAlreadySignedException : public std::exception {
    public:
        virtual const char * what() const throw() {
            return ("Form::FormAlreadySignedException");
        }
    };

private:
    std::string	const	_name;
    bool				_isSigned;
    int const			_gradeToSign;
    int const			_gradeToExec;

    static int const	MAXGRADE = 1;
    static int const	MINGRADE = 150;

};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif //EX01_FORM_HPP

