#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>
# include <iostream>
# include "jttool.hpp"

enum e_type { CHAR, INT, FLOAT, DOUBLE, INVALID };

typedef struct s_vars 
{
	char	c;
	int		i;
	float	f;
	double	d;
} t_vars;

void convert(e_type type, std::string s, t_vars &v);

#endif