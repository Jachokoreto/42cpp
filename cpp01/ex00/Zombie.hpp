/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 03:41:16 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 16:39:44 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP
#define __ZOMBIE_HPP

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Zombie
{
  public:
	void announce(void);

	Zombie(void);
	Zombie(const Zombie &zombie);
	~Zombie(void);
	Zombie &operator=(const Zombie &zombie);

	Zombie *newZombie(string name);
	void randomChump(string name);

  private:
	string _name;
};

#endif