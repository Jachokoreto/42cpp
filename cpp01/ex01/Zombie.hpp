/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 03:41:16 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 18:17:18 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP
#define __ZOMBIE_HPP

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;

class Zombie
{
  public:
	void announce(void);
	void setName(string name);

	Zombie(void);
	Zombie(string name);
	Zombie(const Zombie &zombie);
	~Zombie(void);

  private:
	string _name;
};

	Zombie *zombieHorde(int n, string name);

#endif