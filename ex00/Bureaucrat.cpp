//
// Created by max on 7/7/23.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Bureaucrat] " << COLOR_DEFAULT
                  << "Default Constructor called " << COLOR_YELLOW << name << COLOR_DEFAULT
                  << " " << COLOR_CYAN << grade << COLOR_DEFAULT << std::endl;
    }
    if (grade > MINGRADE) {
        throw GradeTooLowException();
    }
    if (grade < MAXGRADE) {
        throw GradeTooHighException();
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name + "_copy") {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Bureaucrat] " << COLOR_DEFAULT
                  << "Copy Constructor called " << COLOR_YELLOW << src.getName() << COLOR_DEFAULT
                  << " " << COLOR_CYAN << src.getGrade() << COLOR_DEFAULT << std::endl;
    }
    *this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Bureaucrat] " << COLOR_DEFAULT
                  << "Assignment Constructor called " << COLOR_YELLOW << rhs.getName() << COLOR_DEFAULT
                  << " " << COLOR_CYAN << rhs.getGrade() << COLOR_DEFAULT << std::endl;
    }
    if ( this != &rhs )
        this->_grade = rhs.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat(void) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Bureaucrat] " << COLOR_DEFAULT
                  << "Destructor called " << COLOR_YELLOW << this->getName() << COLOR_DEFAULT
                  << " " << COLOR_CYAN << this->getGrade() << COLOR_DEFAULT << std::endl;
    }
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

std::string const & Bureaucrat::getName(void) const {
    return this->_name;
}

// CAVE: increment grade == "--"
void	Bureaucrat::incrementGrade(void) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Bureaucrat] " << COLOR_ORANGE
                  << "incrementGrade() function called " << COLOR_YELLOW << this->getName() << COLOR_DEFAULT
                  << " " << COLOR_CYAN << this->getGrade() << COLOR_DEFAULT << std::endl;
    }
    if (this->_grade == Bureaucrat::MAXGRADE)
        throw GradeTooHighException();
    this->_grade--;
}

// CAVE: decrement grade == "++"
void	Bureaucrat::decrementGrade(void) {
    if (VERBOSE) {
        std::cout << COLOR_GREEN << "[Bureaucrat] " << COLOR_BLUE
                  << "decrementGrade() function called " << COLOR_YELLOW << this->getName() << COLOR_DEFAULT
                  << " " << COLOR_MAGENTA << this->getGrade() << COLOR_DEFAULT << std::endl;
    }
    if (this->_grade == Bureaucrat::MINGRADE)
        throw GradeTooLowException();
    this->_grade++;
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & i ) {
    o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
    return o;
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const * i ) {
    o << i->getName() << ", bureaucrat grade " << i->getGrade() << ".";
    return o;
}