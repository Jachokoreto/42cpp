#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	msg::constructor("Brain", "default");
}

Brain::Brain(const Brain &copy)
{
	msg::constructor("Brain", "Copy constructor");
	copyIdeas(copy);
}

Brain::Brain(std::string ideas[100])
{
	msg::constructor("Brain", "string array");
	ideas[100] = ideas[100];
}


// Destructor
Brain::~Brain()
{
	msg::destructor("Brain");
}


// Operators
Brain & Brain::operator=(const Brain &assign)
{
	copyIdeas(assign);
	return *this;
}


// Getters / Setters
std::string *Brain::getIdeas() const
{
	return (std::string *)ideas;
}

void Brain::setIdeas(std::string idea)
{
	ideas[0] = idea;
}

void Brain::copyIdeas(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];

}
