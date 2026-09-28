#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>
#include <ctime>

template <typename T>
void test(T& cont, int value)
{
    for (typename T::iterator i = cont.begin(); i != cont.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    typename T::iterator it = easyfind(cont, value);
    if (it == cont.end())
        std::cout << value << " not found" << std::endl;
    else
        std::cout << "Found " << *it << " at index "
                  << std::distance(cont.begin(), it) << std::endl;
}

int	main()
{
	std::vector<int> v;
	std::list<int>   l;
	std::deque<int>  d;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		l.push_back(i * 2);
		d.push_back(i + 10);
	}
	::test(v, 4);
	::test(l, 14);
	::test(d, 80);
}