#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Test 1 : ShrubberyCreationForm, grade suffisant partout
    try
    {
        Bureaucrat high("Directeur", 1);
        ShrubberyCreationForm shrub("home");

        std::cout << shrub << std::endl;
        high.signForm(shrub);
        high.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // Test 2 : exécuter sans signer -> doit échouer
    try
    {
        Bureaucrat high("Directeur", 1);
        RobotomyRequestForm robo("Bender");

        high.executeForm(robo);
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // Test 3 : signer avec grade insuffisant -> doit échouer
    try
    {
        Bureaucrat low("Stagiaire", 150);
        RobotomyRequestForm robo("Bender");

        low.signForm(robo);
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // Test 4 : signer OK, mais grade insuffisant pour exécuter
    try
    {
        Bureaucrat signer("Signataire", 72);
        Bureaucrat executor("Stagiaire", 100);
        RobotomyRequestForm robo("Bender");

        signer.signForm(robo);
        executor.executeForm(robo);
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // Test 5 : robotomy complet, plusieurs essais pour voir le 50/50
    try
    {
        Bureaucrat b("PDG", 1);
        for (int i = 0; i < 4; i++)
        {
            RobotomyRequestForm robo("Marvin");
            b.signForm(robo);
            b.executeForm(robo);
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // Test 6 : PresidentialPardonForm complet
    try
    {
        Bureaucrat b("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");

        b.signForm(pardon);
        b.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // Test 7 : polymorphisme, tableau de pointeurs AForm*
    try
    {
        Bureaucrat b("PDG", 1);
        AForm *forms[3];

        forms[0] = new ShrubberyCreationForm("jardin");
        forms[1] = new RobotomyRequestForm("R2D2");
        forms[2] = new PresidentialPardonForm("Ford Prefect");

        for (int i = 0; i < 3; i++)
        {
            b.signForm(*forms[i]);
            b.executeForm(*forms[i]);
            delete forms[i];
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return (0);
}