#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include <string>
# include <iostream>

# include "styling.hpp"

namespace msg
{
    void constructor(std::string className, std::string info);
    void destructor(std::string className);
}

#endif