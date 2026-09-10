#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
}

static AForm *createShrubbery(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomy(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *createPardon(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm *(*formFactories[3])(const std::string &) = {
        &createShrubbery,
        &createRobotomy,
        &createPardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return (formFactories[i](target));
        }
    }
    std::cout << "Intern couldn't find a form named \"" << name << "\"" << std::endl;
    return (NULL);
}