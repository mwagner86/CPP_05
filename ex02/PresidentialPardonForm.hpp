//
// Created by max on 7/10/23.
//

#ifndef EX02_PRESIDENTIALPARDONFORM_HPP
#define EX02_PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.hpp"

class PresidentialPardonForm : public AForm {

public:
	PresidentialPardonForm(std::string const & target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
    ~PresidentialPardonForm(void);

    void	validExecution(Bureaucrat const & executor) const;
    std::string const & getFormType(void) const;


private:
    static int const	GRADE_TO_SIGN = 25;
    static int const	GRADE_TO_EXEC = 5;
    std::string const	_formType;
};

#endif //EX02_PRESIDENTIALPARDONFORM_HPP
