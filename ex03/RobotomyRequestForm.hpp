/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:34:44 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/12 00:31:41 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_ROBOTOMYREQUESTFORM_HPP
#define EX03_ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib> // For rand and srand
#include "AForm.hpp"
#include "colors.hpp"

class RobotomyRequestForm : public AForm {

public:

    RobotomyRequestForm(std::string const & target);
    RobotomyRequestForm(RobotomyRequestForm const & src);
    RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
    ~RobotomyRequestForm(void);

    void	validExecution(Bureaucrat const & executor) const;
    std::string const & getFormType(void) const;
    

private:

    static int const	GRADE_TO_SIGN = 72;
    static int const	GRADE_TO_EXEC = 45;
    std::string const	_formType;
};


#endif //EX03_ROBOTOMYREQUESTFORM_HPP
