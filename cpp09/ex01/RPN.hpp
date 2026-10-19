#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <list>
# include <string>

class RPN
{
private:
    std::stack<long, std::list<long> > _stack;

    void applyOperator(char op);   // dépile 2, calcule, rempile

public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    long evaluate(const std::string &expr);
};

#endif