 #include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm(target + "_shrubbery_form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::performAction() const
{
    std::ofstream file((_target + "_shrubbery").c_str());

    file << "       *\n";
    file << "      ***\n";
    file << "     *****\n";
    file << "    *******\n";
    file << "   *********\n";
    file << "      |||\n";
    file.close();
}