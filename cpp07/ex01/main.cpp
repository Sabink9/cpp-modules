#include "Iter.hpp"

void print(int const& x)
{
	std::cout << x << " ";
}

void doubleValue(int& x)
{
	x *= 2;
}

void printString(std::string const& s)
{
	std::cout << s << " ";
}

int main()
{
	std::cout << "Test 1: afficher un tableau d'int" << std::endl;
	int tab1[5] = {1, 2, 3, 4, 5};
	iter(tab1, 5, print);
	std::cout << std::endl;

	std::cout << "\nTest 2: doubler chaque element (non-const)" << std::endl;
	int tab2[4] = {1, 2, 3, 4};
	iter(tab2, 4, doubleValue);
	iter(tab2, 4, print);
	std::cout << std::endl;

	std::cout << "\n Test 3: tableau const de string" << std::endl;
	std::string const tab3[3] = {"bonjour", "salut", "hey"};
	iter(tab3, 3, printString);
	std::cout << std::endl;

	return 0;
}