#include "Span.hpp"
#include "jttool.hpp"
#include <cstdlib>
#include <algorithm>

void test1(void)
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;
}

void randNum(std::vector<int>::iterator &a)
{
    std::cout << *a << std::endl;
}

void test2(void)
{
    msg::annouceTest("test 2", "test add number using range operator");

    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(rand() % 1000);
        std::cout << *(vec.end() - 1) << " ";
    }
    msg::info("Copy vector to span using range iterator");
    Span sp(10);

    sp.addNumber(vec.begin(), vec.end());
    sp.display();
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;
}

void test3(void)
{
    msg::annouceTest("test3", "test add number using fill");

    Span sp(1500);
    while (1)
    {
        try
        {
            sp.addNumber(rand() % 100, rand() % 100);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            break;
        }
    }
    sp.display();

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;
}

void test4(void)
{
    msg::annouceTest("test4", "test big number");

    Span sp(10000);
    for (int i = 0; i < 10000; i++)
    {
        sp.addNumber(rand() % 10000000);
    }
    sp.display();

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;
}

void test5(void)
{
    msg::annouceTest("test5", "exception test");

    Span sp(5);

    while (1)
    {
        try
        {
            std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        try
        {
            std::cout << "Longest: " << sp.longestSpan() << std::endl;
            break;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        sp.addNumber(rand() % 100);
        sp.display();
    }
}

int main(void)
{
    srand(time(NULL));

    test1();
    test2();
    test3();
    test4();
    test5();
}