//
// Created by max on 7/7/23.
//

#ifndef EX00_BUREAUCRAT_HPP
#define EX00_BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

public:

    Bureaucrat();
    Bureaucrat(int n);
    Bureaucrat(Bureaucrat const & src);
    ~Bureaucrat();

    Bureaucrat &		operator=( Bureaucrat const & rhs );
    void				setFoo(int value);
    int 				getFoo() const;
    void				setName(std::string name);
    std::string	const & getName() const;

private:

    int 				_foo;
    std::string			_name;

};

std::ostream &		operator<<( std::ostream & o, Bureaucrat const & i );

#endif //EX00_BUREAUCRAT_HPP
