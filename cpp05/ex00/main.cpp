#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b;
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Trop haut", 0);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Trop bas", 200);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Ambitieux", 2);
        b.incrementGrade();
        std::cout << b << std::endl; // grade 1
        b.incrementGrade();          // doit throw
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Fatigue", 149);
        b.decrementGrade();
        std::cout << b << std::endl; // grade 150
        b.decrementGrade();          // doit throw
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat original("Original", 42);
        Bureaucrat copie(original);
        std::cout << copie << std::endl;

        Bureaucrat autre("Autre", 100);
        autre = original;
        std::cout << autre << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return (0);
}
