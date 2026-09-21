#include "Base.hpp"

Base* generate(void)
{
	int choice = rand() % 3;
	
	if (choice == 0)
		return new A();
	else if (choice == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (...)
	{

		try
		{
			dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (...)
		{
	
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (...)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}