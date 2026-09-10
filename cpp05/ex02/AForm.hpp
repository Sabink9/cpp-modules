#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string  _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

        AForm();

    public:
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        const std::string &getFormName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);
        void execute(Bureaucrat const &executor) const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    protected:
        virtual void performAction() const = 0; // pure virtuelle : chaque fille l'implémente
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif