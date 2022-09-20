#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"
#include "jttool.hpp"
#include <cstdlib>

/**
 * Need to testWithInt
 **/

template <class T>
void fillContainer(T &cont, unsigned int size)
{
    for (unsigned int i = 1; i < size + 1; i++)
        cont.push_back(i);
};

template <class T>
void showContainer(T &cont)
{
    typename T::iterator it;

    it = cont.begin();
    while (it != cont.end())
        std::cout << *it++ << " ";
    std::cout << '\n';
}

template <class T>
void testContainer(T &cont)
{
    typename T::iterator it;

    int toFind;
    fillContainer(cont, 15);
    showContainer(cont);
    for (int i = 0; i < 5; i++)
    {
        try
        {
            toFind = rand() % 20;
            it = easyfind(cont, toFind);
            std::cout << GRN "Element " << *it << " found! \n" RESET;
        }
        catch (NoOccuranceException::exception &e)
        {
            std::cerr << RED "Trying to find " << toFind << ": " << e.what() << RESET "\n";
        }
    }
};

int main(void)
{
    srand(time(0));

    msg::annouceTest("Testing vector", "one of the sequence container");
    std::vector<int> vec1;
    testContainer(vec1);
    vec1.push_back(rand() % 50);
    vec1.push_back(rand() % 50);
    vec1.push_back(rand() % 50);
    showContainer(vec1);

    // https://www.geeksforgeeks.org/deque-cpp-stl/?ref=rp
    msg::annouceTest("Testing deque", "one of the sequence container");
    std::deque<int> deq1;
    testContainer(deq1);
    deq1.push_front(rand() % 50);
    deq1.push_front(rand() % 50);
    deq1.push_front(rand() % 50);
    showContainer(deq1);

    // https://www.geeksforgeeks.org/list-cpp-stl/?ref=rp
    msg::annouceTest("Testing list", "one of the sequence container");
    std::list<int> meww;
    testContainer(meww);
    meww.reverse();
    showContainer(meww);

    // system("leaks array");
    return (0);
}