#include <iostream>
#include "..\Array\Array.h"
#include "..\TemplateArray\Array.h"

using namespace rut::uizi::array;

int main()
{
	setlocale(LC_ALL, "RU");
	rut::uizi::array::Array array{ 1, 2, 3, 4 };
	std::cout << array;

	Array array3{};
	array3 = array;
	std::cout << array3;

	rut::cip::array::Array<int> array1{ 1, 2, 3, 4 };
	std::cout << array1;

	try
	{
		rut::uizi::array::Array ayy(-1);
		rut::cip::array::Array<int> array3(-1);
	}
	catch (std::logic_error& e)
	{
		std::cerr << "Ошибка " << e.what();
	}
	return 0;
}