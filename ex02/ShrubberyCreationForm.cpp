/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:35:04 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/11 17:35:07 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm(target,
																				 GRADE_TO_SIGN,
																				 GRADE_TO_EXEC),
																				 _formType("ShrubberyCreationForm") {
	if (VERBOSE) {
		std::cout << COLOR_GREEN << "[ShrubberyCreationForm] " << COLOR_DEFAULT
				  << "Default Constructor called " << COLOR_YELLOW << "GradeToSign: " << getGradeToSign() << COLOR_DEFAULT
				  << COLOR_CYAN << " GradeToExec: "  << getGradeToExec() << COLOR_DEFAULT
				  << " type: " << ShrubberyCreationForm::getFormType() << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _formType("ShrubberyCreationForm") {
	if (VERBOSE) {
		std::cout << COLOR_GREEN << "[ShrubberyCreationForm] " << COLOR_DEFAULT
				  << "Copy Constructor called " << COLOR_YELLOW << src.getName() << COLOR_DEFAULT
				  << " " << COLOR_CYAN << src.getFormType() << COLOR_DEFAULT << std::endl;
	}
    *this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{
	if (VERBOSE) {
		std::cout << COLOR_GREEN << "[ShrubberyCreationForm] " << COLOR_DEFAULT
				  << "Assignment Constructor called " << "name: " << COLOR_YELLOW << rhs.getName() << COLOR_DEFAULT
				  << " type: " << COLOR_CYAN << rhs.getFormType() << COLOR_DEFAULT << std::endl;
	}
    if (this != &rhs) {
		AForm::operator=(rhs);
		return *this;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (VERBOSE) {
		std::cout << COLOR_RED << "[ShrubberyCreationForm] " << COLOR_DEFAULT
				  << "Destructor called " << std::endl;
	}
}

std::string const & ShrubberyCreationForm::getFormType(void) const {
    return this->_formType;
}

void	ShrubberyCreationForm::validExecution(Bureaucrat const & executor) const {
	std::string	const filename = (this->getName() + "_shrubbery");
	std::ofstream	output_file(filename.c_str());

	if (!output_file.is_open())
		throw CantAccessFileException();
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣄⡀⠀⠀⠀⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣆⠀⠀⢻⡍⢳⡄⠀⠀⣿⠸⣆⠀⠀⣠⣤⣾⢳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output_file << "⠀⠀⠀⠀⠀⠀⢀⣀⠀⢀⠀⢀⣀⠀⢸⢁⣿⡄⠀⠈⢷⣈⣿⠀⣠⣼⣦⣿⣴⣋⣡⠞⢻⠀⣿⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠘⢿⡻⣿⠳⣾⡍⠻⣿⣾⢿⡛⠶⣦⡄⠈⣿⣏⣡⠞⠋⣻⠉⠉⡀⠀⢸⡶⢟⣽⡯⠥⢤⣄⣀⡀⠀⠀⠀⠀⠀⠀\n";
	output_file << "⠀⠀⠀⠀⠀⠀⢀⣈⣛⣿⠀⢹⡿⠶⣼⣿⠀⠙⠶⢬⣷⣿⢸⡏⠀⠀⠀⡟⠀⢸⠹⣦⣾⠞⠋⠉⠛⠛⢿⠋⣻⠷⢲⣶⠆⠀⠀⠀\n";
	output_file << "⠀⠀⠀⢼⡿⣦⠸⣯⡉⠛⠷⣾⡃⠀⠀⢸⣇⠀⠀⠀⠈⣽⡇⢿⡄⠀⢀⡇⠀⢸⣠⡟⠀⠀⠀⠀⠀⠀⣸⣾⠥⠖⠋⠀⠀⠀⠀⠀\n";
	output_file << "⠀⠀⢰⣾⣧⢻⡆⠈⠉⠉⠙⠙⠻⣦⣀⠀⢿⣄⠀⠀⠀⣿⡇⠈⢻⣆⢸⡇⠀⣸⣿⢦⡀⠀⠀⣀⣤⣾⠋⠀⣀⣤⣶⣞⣉⡿⠆⠀\n";
	output_file << "⠀⠀⠘⣧⠈⢿⡃⠀⣀⣤⣤⣀⠀⠀⠙⠳⢶⣿⣦⡀⠀⣿⡇⠀⠀⢻⣿⣧⠞⢉⣿⣄⢻⡖⠛⠉⠉⠉⠉⠻⣿⣍⠛⣧⡀⠀⠀⠀\n";
	output_file << "⠀⢸⡿⢿⡷⠴⢷⡾⠥⠴⠞⠁⠀⠀⠀⠀⠀⠀⠉⠻⣦⣹⣇⠀⠀⠈⣿⡇⢀⡾⠉⣯⠛⠇⠀⠀⠀⠀⣀⣠⠞⠋⠓⠛⠟⠀⠀⠀\n";
	output_file << "⠀⠈⢷⡈⣷⡀⠈⠻⣆⠀⠀⢀⣠⡤⢤⣤⠀⠀⠀⠀⠘⢿⣿⡄⠀⠀⣼⣷⠋⢹⡀⣿⣀⣤⡤⠶⠒⠋⠹⣍⠳⣄⠀⠀⠀⠀⠀⠀\n";
	output_file << "⠀⠀⠀⠙⢿⣀⠀⠀⠙⠿⣦⡛⠛⠛⠛⠁⠀⠀⠀⠀⠀⠈⢿⣧⣴⠟⢻⡇⢀⣤⠿⣿⣉⡀⠀⠀⣀⡀⠀⠈⠛⠛⠃⠀⢀⣠⣤⠀\n";
	output_file << "⠀⠀⠀⠀⠀⠉⠙⠛⠲⠶⠿⠿⣦⣄⣀⣀⣀⣀⣀⠀⠀⠀⢸⣿⠏⠀⢸⣷⠋⠁⠀⠀⠉⠉⠛⠛⣿⠙⢲⡄⠀⣀⣴⣾⡽⠾⠛⠀\n";
	output_file << "⢰⢦⣄⠀⠀⢴⣚⣛⣶⣶⠀⠀⠀⠉⠛⠛⠻⠿⠿⠿⣷⣦⣼⣿⡄⠀⣿⡇⠀⠀⠀⠀⠀⣀⣀⣤⣬⡿⠶⠛⢩⣿⢯⣉⠛⢶⡄⠀\n";
	output_file << "⠘⢦⣌⣷⡄⠀⠀⠀⠀⠙⢶⣤⣀⡀⠀⠀⣀⣀⣀⣀⠈⠛⣿⣿⠇⣰⣿⣧⣶⣾⣿⠿⠿⠛⠉⠘⣧⢻⡄⠀⣾⢹⡆⠈⠙⠛⠛⠀\n";
	output_file << "⠀⠀⢈⡛⠷⠦⣤⣤⣤⡤⠴⠿⠿⠛⠛⠛⠋⠛⠛⠻⢿⣦⣼⣿⣠⣿⠋⠁⠀⠉⠙⠛⢳⣶⡞⠛⠻⣾⡏⠙⢿⡿⣧⣴⣶⠶⢤⣀\n";
	output_file << "⠀⠀⡟⢹⡄⠀⠀⠀⠀⡞⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⢸⣁⣿⠀⠀⠀⠀⠀⠀⠀⠙⢷⡈⠻⣞⠉\n";
	output_file << "⠀⠀⢷⡾⠀⠀⠀⠀⠀⠻⣼⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠘⠿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠿⠀\n";
	output_file << "⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "               ,@@@@@@@,\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "       |o|        | |         | |\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣿⠟⠛⢻⣯⠙⠻⠿⠿⠷⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "       |.|        | |         | |\n";
	output_file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠁⠀⠀⠘⠛⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
	output_file.close();
	std::cout << COLOR_GREEN << executor.getName() << " executed " << this->getName() << " " << this->_formType << "\n" << COLOR_DEFAULT;
}
