#include <stdexcept>
#include <algorithm>
#include "Array.h"

rut::uizi::array::Array::Array(int size)
	: size{ size }, data{new int[this->size]}
{
	if (size <= 0)
	{
		throw std::logic_error("–азмер массива должен быть неотрицательным!");
	}
}

rut::uizi::array::Array::Array(const Array& other)
	: size{ other.size }, data {new int[this->size]}
{
	std::copy(other.data, other.data + size, this->data);
}

rut::uizi::array::Array::Array(Array&& other) noexcept
	: size{size}, data{std::move(other.data)}
{
}
