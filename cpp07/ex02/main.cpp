#include <string>
#include <iostream>
#include "Array.hpp"
#include "jttool.hpp"

/**
 * Need to testWithInt
 **/

template <class T>
void displayArray(Array<T> &array, std::string name)
{
    unsigned long i;

    std::cout << name << " -> ";
    i = -1;
    while (++i < array.size())
    {
        std::cout << i << ":" << array[i];
        if (i + 1 < array.size())
            std::cout << ", ";
    }
    std::cout << std::endl;
}

void testWithInt(void)
{
    msg::info("Initialize variable with default value");
    int *a = new int();
    std::cout << "Value of pointer a: " << *a << std::endl;

    msg::info("Initialize Array with no size and get its value at index[0]");
    Array<int> a1;
    displayArray(a1, "a1");

    msg::info("Initialize Array with size of 10 and get its all the value");
    Array<int> a2(10);
    displayArray(a2, "a2");

    msg::info("Set a2[5~9] to value 111");
    for (int i = 5; i < 10; i++)
        a2[i] = 111;
    msg::info("Initialize a new array(a3) and assign old array(a2) to it");
    Array<int> a3;
    a3 = a2;
    displayArray(a3, "a3");

    msg::info("Set a3[0~2] to value 888, then display a2 and a3");
    for (int i = 0; i < 3; i++)
        a3[i] = 888;
    displayArray(a2, "a2");
    displayArray(a3, "a3");

    msg::info("Copy construct works! new a4 copy a3");
    Array<int> a4(a3);
    displayArray(a4, "a4");

    msg::info("Init a5 array with the size of 20 and copy assign it to a3");
    Array<int> a5(20);
    a3 = a5;
    displayArray(a3, "a3");
    delete a;
}

void testWithStr(void)
{
    msg::info("Init string array with no size and display");
    Array<std::string> a1;
    displayArray(a1, "a1");

    msg::info("Init string array with size of 5 and display");
    Array<std::string> a2(5);
    displayArray(a2, "a2");
    msg::info("Set hello to all index");
    for (unsigned long i = 0; i < a2.size(); i++)
        a2[i] = "hello";
    displayArray(a2, "a2");
}

void testWithFloat(void)
{
    msg::info("Init float array");
    Array<double> a1(5);

    a1[0] = 4;
    displayArray(a1, "a1");
}

void moreTests(void)
{
    msg::info("Init int Array with size of 10 and try index thats out of bound");
    Array<int> a1(10);
    int i;

    displayArray(a1, "a1");
    i = 12;
    while (--i)
    {
        try
        {
            std::cout << "Trying index " << i << std::endl;
            std::cout << a1[i] << std::endl;
            break;
        }
        catch (const std::exception &e)
        {
            std::cerr << "index out of bound" << '\n';
        }
    }

    msg::info("Show size of a1");
    std::cout << a1.size() << std::endl;
}

int main(void)
{
    testWithInt();
    testWithStr();
    testWithFloat();
    moreTests();
    // system("leaks array");
}