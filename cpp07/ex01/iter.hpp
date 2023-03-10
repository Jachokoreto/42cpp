#ifndef ITER_HPP
# define ITER_HPP

template <class T, class U>
void iter(T *array, U len, void (*func)(T const &))
{
	int i;

	i = -1;
	while (++i < len)
	{
		func(array[i]);
	}
};

template <class T>
void read(T &t)
{
	std::cout << "reading... " << t << std::endl;
}


#endif