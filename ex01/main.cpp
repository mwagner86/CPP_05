/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:28:23 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/08 17:28:54 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {

    std::cout << "\n**************************************\n"
              << "VALID INTERACTION\n"
              << "**************************************\n";
    Form publicHealth("Public Health Form", 80, 90);
    // Using the operator<< overload with Form object reference
    std::cout << publicHealth << std::endl;

    Bureaucrat Obama("Barack Hussein", 70);
    Obama.signForm(publicHealth);
    std::cout << publicHealth << std::endl;

    std::cout << "\n**************************************\n"
              << "INVALID INTERACTION\n"
              << "**************************************\n";
    Form wallApproval("Wall Approval Form", 50, 100);
    // Using the operator<< overload with Form object reference
    std::cout << wallApproval << std::endl;

    Bureaucrat Trump("The Donald", 70);
    Trump.signForm(wallApproval);
    std::cout << wallApproval << std::endl;

    std::cout << "\n**************************************\n"
              << "EXCEPTIONS\n"
              << "**************************************\n";

    std::cout << "Exception1: Bureaucrat Grade too low" << std::endl;
    try {
        Bureaucrat bureaucrat("Jane Doe", 50);
        Form form("Example Form", 49, 100);

        bureaucrat.signForm(form); // Attempt to sign the form
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "Exception2: Attempt go out of bounds" << std::endl;
    try {
        Bureaucrat bureaucrat("John Doe", 100);
        Form form("Example Form", 151, 100);

    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "Exception3: Double sign form" << std::endl;
    try {
        Bureaucrat bureaucrat("John Doe", 100);
        Form form("Example Form", 110, 100);

        bureaucrat.signForm(form); // Signing the form for the first time
        bureaucrat.signForm(form); // Attempting to sign the form again

    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}