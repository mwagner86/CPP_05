/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:35:17 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/11 17:35:19 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_SHRUBBERYCREATIONFORM_HPP
#define EX03_SHRUBBERYCREATIONFORM_HPP

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


#endif //EX03_SHRUBBERYCREATIONFORM_HPP
