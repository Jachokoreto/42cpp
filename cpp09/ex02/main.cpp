#include "PMergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./PMergeMe <sequence>" << std::endl;
        return 1;
    }
    PMergeMe pmergeme;
    pmergeme.run(&argv[1]);

    return 0;
}