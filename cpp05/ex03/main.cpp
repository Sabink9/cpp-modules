#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    Intern someRandomIntern;
    AForm *forms[4];

    forms[0] = someRandomIntern.makeForm("shrubbery creation", "home");
    forms[1] = someRandomIntern.makeForm("robotomy request", "Bender");
    forms[2] = someRandomIntern.makeForm("presidential pardon", "Marvin");
    forms[3] = someRandomIntern.makeForm("formulaire inexistant", "cible");

    Bureaucrat b("PDG", 1);

    for (int i = 0; i < 4; i++)
    {
        if (forms[i] != NULL)
        {
            b.signForm(*forms[i]);
            b.executeForm(*forms[i]);
            delete forms[i];
        }
    }

    return (0);
}