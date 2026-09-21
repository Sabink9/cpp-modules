#include "Serializer.hpp"

int main()
{
	Data myData;

	Data* ptrData = &myData; 

	uintptr_t serialized = Serializer::serialize(ptrData);

	Data* deserialized = Serializer::deserialize(serialized);

	if (deserialized == ptrData)
		std::cout << "OK: les pointeurs sont identiques" << std::endl;
	else
		std::cout << "KO: les pointeurs sont différents" << std::endl;

}