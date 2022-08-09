#include "Message.hpp"


/**
 * @brief Message for constrcutor
 * 
 * @param className Class name for display
 * @param info Type of constructor being called
 */
void msg::constructor(std::string className, std::string info)
{
    std::cout << "# Constructed " BLU << className << RESET " with " << info << std::endl;
}


/**
 * @brief Message for destructor
 * 
 * @param className Class name for display
 */
void msg::destructor(std::string className)
{
    std::cout << "# Destructed " BLU << className << RESET << std::endl;
}

void msg::info(std::string info)
{
	std::cout << std::endl << BLU " >> " RESET << info << std::endl;
}