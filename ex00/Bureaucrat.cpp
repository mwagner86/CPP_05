//
// Created by max on 7/7/23.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Default Constructor called" << std::endl;
    this->_foo = 0;
}
Bureaucrat::Bureaucrat(int n) {
    std::cout << "Parametric Constructor called" << std::endl;
    this->_foo = n;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _foo() {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}

void	Bureaucrat::setFoo(int n) {
    this->_foo = n;
}

int			Bureaucrat::getFoo() const {
    return this->_foo;
}

void	Bureaucrat::setName(std::string name) {
    this->_name = name;
}

std::string const & Bureaucrat::getName() const {
    return (this->_name);
}


Bureaucrat &	Bureaucrat::operator=(Bureaucrat const &rhs) {
    std::cout << "Assignment operator overload called" << std::endl;
    if ( this != &rhs )
        this->_foo = rhs.getFoo();
    return *this;
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & i ) {
    o << "The value of _foo is : " << i.getFoo();
    return o;
}