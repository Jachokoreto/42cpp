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

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;

class FragTrap : virtual public ClapTrap
{

  public:
	FragTrap(void);
	FragTrap(string name);
	FragTrap(const FragTrap &rhs);
	FragTrap &operator=(const FragTrap &FragTrap);
	~FragTrap(void);

	void highFivesGuys(void);

  private:
};

#endif /* ********************************************************** FragTrap_H */