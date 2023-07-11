/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:28:16 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/08 17:28:20 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_AAForm_HPP
#define EX02_AAForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "colors.hpp"

class Bureaucrat;

class AForm {

public:
    AForm(std::string const & name, int gradeToSign, int gradeToExec);
    AForm(AForm const & src);
    AForm & operator=(AForm const & rhs);
    virtual ~AForm(void);

    void			            execute(Bureaucrat const & executor) const;
    void	                    executeFromBureaucrat(Bureaucrat const & executor) const;
    virtual std::string const & getFormType(void) const = 0;
    virtual void                validExecution(Bureaucrat const & executor) const = 0;


    std::string const &	getName(void) const;
    bool				getIsSigned(void) const;
    int					getGradeToSign(void) const;
    int					getGradeToExec(void) const;

    void				beSigned(Bureaucrat const & src);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char * what() const throw() {
            return ("AForm::GradeTooHighException");
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char * what() const throw() {
            return ("AForm::GradeTooLowException");
        }
    };

    class AFormAlreadySignedException : public std::exception {
    public:
        virtual const char * what() const throw() {
            return ("AForm::AFormAlreadySignedException");
        }
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char * what() const throw() {
            return ("AForm::FormNotSignedException");
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

std::ostream & operator<<(std::ostream & o, AForm const & i);

#endif //EX02_AAForm_HPP
