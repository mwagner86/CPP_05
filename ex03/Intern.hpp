/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:30:54 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/12 00:30:56 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_INTERN_HPP
#define EX03_INTERN_HPP
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern {
public:
	Intern(void);
	Intern(Intern const & src);
	Intern & operator=(Intern const & rhs);
	~Intern(void);

	AForm * makeForm(std::string const & type, std::string const & target) const;
};

#endif //EX03_INTERN_HPP
