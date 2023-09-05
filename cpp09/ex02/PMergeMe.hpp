#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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
#include <deque>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iomanip>

//  Your program must be able to use a positive integer sequence as argument.
// • Your program must use a merge-insert sort algorithm to sort the positive integer
// sequence.

class PMergeMe
{
private:
    std::deque<int> _deque;
    std::list<int> _list;

    void insertionSortDeque(std::deque<int> &arr, int left, int right);
    void mergeDeque(std::deque<int> &arr, int left, int mid, int right);
    void mergeInsertionSortDeque(std::deque<int> &arr, int left, int right);
    double sortInDeque();

    void insertionSortList(std::list<int> &arr);
    void mergeList(std::list<int> &arr, std::list<int> &left, std::list<int> &right);
    void mergeInsertionSortList(std::list<int> &arr);
    double sortInList();

    int stoi(std::string str);
    int checkSorting();
    std::string joinString(char **argv);

public:
    PMergeMe();
    ~PMergeMe();
    void run(char **argv);
};

#endif