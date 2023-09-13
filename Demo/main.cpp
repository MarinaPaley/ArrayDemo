#include <iostream>
#include "..\Array\Array.h"


using namespace rut::uizi::array;

int main()
{
	setlocale(LC_ALL, "RU");
	Array array{ 1, 2, 3, 4 };
	std::cout << array;

	try
	{
		Array ayy(-1);
	}
	catch (std::logic_error& e)
	{
		std::cerr << "Îøèáêà! " << e.what();
	}
	return 0;
}