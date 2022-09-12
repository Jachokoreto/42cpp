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

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;

class ScavTrap : virtual public ClapTrap
{

  public:
	ScavTrap(void);
	ScavTrap(string name);
	ScavTrap(const ScavTrap &rhs);
	ScavTrap &operator=(const ScavTrap &ScavTrap);
	~ScavTrap(void);

	void attack(const string &target);
	void guardGate(void);

  private:
};

#endif /* ********************************************************** ScavTrap_H */