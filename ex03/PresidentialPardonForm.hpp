/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:34:30 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/12 00:31:18 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_PRESIDENTIALPARDONFORM_HPP
#define EX03_PRESIDENTIALPARDONFORM_HPP

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

#endif //EX03_PRESIDENTIALPARDONFORM_HPP
