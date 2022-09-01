/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 03:41:16 by jatan             #+#    #+#             */
/*   Updated: 2022/08/31 17:20:26 by jatan            ###   ########.fr       */
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
	Zombie(void);
	Zombie(string name);
	~Zombie(void);
	
	void announce(void);
	void setName(string name);


  private:
	string _name;
};

	Zombie *zombieHorde(int n, string name);

#endif