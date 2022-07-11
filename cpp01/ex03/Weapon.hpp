#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

using std::string;

class Weapon
{

	public:

		Weapon(string type);
		~Weapon();


		string &getType(void);
		void setType(string type);

	private:
		string _type;
};


#endif /* ********************************************************** WEAPON_H */