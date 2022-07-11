/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:36:57 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 21:17:27 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

class HumanB
{

	public:

		HumanB(string name);
		~HumanB();

		void	attack(void);

		void	setWeapon(Weapon &weapon);
		string	getWeapon(void);
		void	setName(string name);
		string	getName(void);

	private:
		string	_name;
		Weapon *_weapon;

};


#endif /* ********************************************************** HUMANB_H */