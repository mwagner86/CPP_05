/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:27:40 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/11 17:33:50 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_BUREAUCRAT_HPP
#define EX03_BUREAUCRAT_HPP

#include <iostream>
#include "colors.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat {

public:

    Bureaucrat(std::string const & name, int grade);
    Bureaucrat(Bureaucrat const & src);
    Bureaucrat & operator=(Bureaucrat const & rhs);
    ~Bureaucrat(void);

    int 				getGrade(void) const;
    std::string	const & getName(void) const;
    void                incrementGrade(void);
    void	            decrementGrade(void);

    void				signForm(AForm & form) const;
    void				executeForm(AForm const & form) const;
    void				executeFromForm(AForm const & form) const;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char * what() const throw() {
            return ("Bureaucrat::GradeTooHighException");
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char * what() const throw() {
            return ("Bureaucrat::GradeTooLowException");
        }
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char * what() const throw() {
            return ("AForm::FormNotSignedException");
        }
    };

private:

    std::string	const   _name;
    int                 _grade;
    static int const    MAXGRADE = 1;
    static int const    MINGRADE = 150;

};

std::ostream &		operator<<(std::ostream & o, Bureaucrat const & i);

// Set VERBOSE to one to get more verbose Con and Destructor calls
# ifndef VERBOSE
#  define VERBOSE 0
# endif
#endif //EX03_BUREAUCRAT_HPP
