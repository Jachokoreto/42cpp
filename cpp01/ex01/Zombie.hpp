/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 03:41:16 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 17:12:41 by jatan            ###   ########.fr       */
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

	Zombie(string name);
	Zombie(const Zombie &zombie);
	~Zombie(void);
	Zombie &operator=(const Zombie &zombie);

  private:
	string _name;
};

	Zombie *newZombie(string name);
	void randomChump(string name);

#endif