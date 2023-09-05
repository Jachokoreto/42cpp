#include "RPN.hpp"

RPN::RPN(std::string expression)
{
    tokenize(expression);
}

void RPN::tokenize(std::string expression)
{
    std::stringstream ss(expression);
    std::string token;

    while (std::getline(ss, token, ' '))
    {
        if (token != "+" && token != "-" && token != "*" && token != "/")
        {
            if (token.length() != 1 || !std::isdigit(token[0]))
            {
                std::cout << "Error: invalid token." << std::endl;
                exit(1);
            }
        }
        _tokens.push_back(token);
    }
}

void RPN::evaluate(std::string token)
{
    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    std::cout << a << " " << token << " " << b << std::endl;
    if (token == "+")
        _stack.push(a + b);
    else if (token == "-")
        _stack.push(a - b);
    else if (token == "*")
        _stack.push(a * b);
    else if (token == "/")
        _stack.push(a / b);
}

RPN::~RPN()
{
}

namespace util
{
    int stoi(std::string str)
    {
        std::stringstream ss(str);
        int val;
        ss >> val;
        return val;
    }
} // namespace util

void RPN::run()
{

    for (size_t i = 0; i < _tokens.size(); i++)
    {
        if (_tokens[i].find_first_of("+-*/") != std::string::npos)
        {
            if (_stack.size() < 2)
            {
                std::cout << "Error: invalid expression." << std::endl;
                exit(1);
            }
            evaluate(_tokens[i]);
            std::cout << "= :" << _stack.top() << std::endl;
        }
        else
        {
            _stack.push(util::stoi(_tokens[i]));
        }
    }
    std::cout << _stack.top() << std::endl;
}