#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    // Constructors and insertion operator:
    // Default
    std::cout   << "\n**************************************\n"
                << "CONSTRUCTOR TESTS\n"
                << "**************************************\n\n";
    Bureaucrat b1("Olaf", 100);
    std::cout << b1 << std::endl;
    // Copy
    Bureaucrat b2(b1);
    std::cout << b2 << std::endl;
    // Assignment
    Bureaucrat b3 = b2;
    std::cout << b3 << std::endl;

    std::cout   << "\n**************************************\n"
                << "GRADE SET TOO HIGH\n"
                << "**************************************\n\n";
    try {
        Bureaucrat Anna("Anna Lena", 0); // Throws GradeTooHighException
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout   << "\n**************************************\n"
                << "GRADE SET TOO LOW\n"
                << "**************************************\n\n";
    try {
        Bureaucrat Robert("Robert", 200); // Throws GradeTooLowException
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout   << "\n**************************************\n"
                << "TEST GRADE INCREMENT / DECREMENT\n"
                << "**************************************\n\n";
    try {
        Bureaucrat b("John Doe", 50);
        std::cout << b << std::endl;

        // Increment grade
        b.incrementGrade(); // Should throw GradeTooHighException if Grade goes out of Range
        std::cout << b << std::endl;

        // Decrement grade
        b.decrementGrade(); // Should throw GradeTooLowException if Grade goes out of Range
        std::cout << b << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout   << "\n**************************************\n"
                << "TEST LEAVING GRADE RANGE\n"
                << "**************************************\n\n";
    try {
        Bureaucrat b4("Jane Doe", 1);
        std::cout << b4 << std::endl;

        // Increment grade
        b4.incrementGrade(); // Should throw GradeTooHighException if Grade goes out of Range
        std::cout << b4 << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("Donald", 150);
        std::cout << b5 << std::endl;

        // Decrement Grade
        b5.decrementGrade(); // Should throw GradeTooHighException if Grade goes out of Range
        std::cout << b5 << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}
