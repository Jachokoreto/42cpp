#include "Message.hpp"

void msg::constructor(std::string className, std::string info)
{
    std::cout << "# Constructed " BLU << className << RESET " with " << info << std::endl;
}

void msg::destructor(std::string className)
{
    std::cout << "# Destructed " BLU << className << RESET << std::endl;
}