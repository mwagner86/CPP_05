//
// Created by max on 7/10/23.
//

#ifndef EX02_SHRUBBERYCREATIONFORM_HPP
#define EX02_SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "colors.hpp"


class ShrubberyCreationForm : public AForm {

public:
    ShrubberyCreationForm(std::string const & target);
    ShrubberyCreationForm(ShrubberyCreationForm const & src);
    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
    ~ShrubberyCreationForm(void);

    void	validExecution(Bureaucrat const & executor) const;
    std::string const & getFormType(void) const;

    class CantAccessFileException : public std::exception
    {
    public:
        virtual const char * what() const throw()
        {
            return ("ShrubberyCreationForm::CantAccessFileException");
        }
    };

private:
    static int const	GRADE_TO_SIGN = 145;
    static int const	GRADE_TO_EXEC = 137;
    std::string const	_formType;
};


#endif //EX02_SHRUBBERYCREATIONFORM_HPP
