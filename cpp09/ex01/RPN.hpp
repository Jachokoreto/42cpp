#ifndef RPN_HPP
#define RPN_HPP

// Your program must take an inverted Polish mathematical expression as an argument.
// • The numbers used in this operation will always be less than 10.
// • Your program must process this expression and output the correct result on the
// standard output.
// • If an error occurs during the execution of the program an error message should be
// displayed on the standard output.
// • Your program must be able to handle operations with these tokens: "+ - / *".

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <cstdlib>

class RPN
{
private:
    std::vector<std::string> _tokens;
    std::stack<int> _stack;

    void tokenize(std::string expression);
    void evaluate(std::string token);

public:
    RPN(std::string expression);
    ~RPN();
    void run();
};

#endif