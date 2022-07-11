/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:36:57 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 21:00:15 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

class HumanA
{

	public:

		HumanA(string name, Weapon &weapon);
		~HumanA();

		void	attack(void);

		void	setWeapon(Weapon &weapon);
		string	getWeapon(void);
		void	setName(string name);
		string	getName(void);

	private:
		string	_name;
		Weapon &_weapon;

};


#endif /* ********************************************************** HUMANA_H */