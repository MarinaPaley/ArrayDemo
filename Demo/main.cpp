#include <iostream>
#include "..\Array\Array.h"
#include "..\TemplateArray\Array.h"


int main()
{
	setlocale(LC_ALL, "RU");
	rut::uizi::array::Array array{ 1, 2, 3, 4 };
	std::cout << array;

	rut::cip::array::Array<int> array1{ 1, 2, 3, 4 };
	std::cout << array1;

	try
	{
		rut::uizi::array::Array ayy(-1);
		rut::cip::array::Array<int> array3(-1);
	}
	catch (std::logic_error& e)
	{
		std::cerr << "Îøèáêà! " << e.what();
	}
	return 0;
}