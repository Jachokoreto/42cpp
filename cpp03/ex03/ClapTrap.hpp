/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:56:36 by jatan             #+#    #+#             */
/*   Updated: 2022/07/13 23:05:56 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

class ClapTrap
{

  public:
	ClapTrap(void);
	ClapTrap(string name);
	ClapTrap(string name, int hp, int ep, int ad);
	ClapTrap(const ClapTrap &rhs);
	ClapTrap &operator=(const ClapTrap &ClapTrap);
	~ClapTrap(void);

	string getName(void) const;
	int getHitPts(void) const;
	int getEnergyPts(void) const;

	int getAttackDmg(void) const;
	void setAttackDmg(unsigned int amount);

	void attack(const string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

  private:
	string _name;
	unsigned int _hitPts;
	unsigned int _energyPts;
	unsigned int _attackDmg;
};

#endif /* ********************************************************** ClapTrap_H */