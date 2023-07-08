/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:27:40 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/08 17:27:42 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_BUREAUCRAT_HPP
#define EX01_BUREAUCRAT_HPP

#include <iostream>
#include "colors.hpp"

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

private:

    std::string	const   _name;
    int                 _grade;
    static int const    MAXGRADE = 1;
    static int const    MINGRADE = 150;

};

std::ostream &		operator<<( std::ostream & o, Bureaucrat const & i );
std::ostream &		operator<<( std::ostream & o, Bureaucrat const * i );

// Set VERBOSE to one to get more verbose Con and Destructor calls
# ifndef VERBOSE
#  define VERBOSE 0
# endif
#endif //EX01_BUREAUCRAT_HPP
