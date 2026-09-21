#include "Base.hpp"

int	main()
{
	srand(time(NULL));

	Base* rand1;
	rand1 = generate();

	identify(rand1);
	identify(*rand1);

	delete rand1;
}