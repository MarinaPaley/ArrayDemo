#include <stdexcept>
#include <algorithm>
#include <sstream>
#include "Array.h"

namespace rut::uizi::array
{
	void Array::CheckIndex(const size_t i) const
	{
		if (i >= this->GetSize())
		{
			throw std::out_of_range("Значение индекса больше размера массива!");
		}
	}

	Array::Array(const int size)
	{
		if (size <= 0)
		{
			throw std::logic_error("Размер массива должен быть неотрицательным!");
		}

		this->size = static_cast<size_t>(size);
		this->data = new int[this->size];
	}

	Array::Array( std::initializer_list<int> list)
		: size{ list.size()}, data{new int[this->size]}
	{
		std::copy(list.begin(), list.end(), this->data);
	}

	Array::Array(const Array& other)
		: size{ other.size }, data{ new int[this->size] }
	{
		std::copy(other.data, other.data + size, this->data);
	}

	Array::Array(Array&& other) noexcept
		: size{ 0 }, data{ nullptr }
	{
		//std::swap(other.data, this->data);
		//std::exchange(other.size, this->size);
		*this = std::move(other);
	}

	Array::~Array()
	{
		delete[] this->data;
	}

	Array& Array::operator=(const Array& other)
	{
		if (this != &other)
		{
			/*
			delete[] this->data;
			this->size = other.size;
			this->data = new int[this->size];

			std::copy(other.data, other.data + other.size, this->data);
			*/
			Array temp(other);
			std::swap(this->data, temp.data);
			std::swap(this->size, temp.size);

		}

		return *this;
	}

	Array& Array::operator=(Array&& other) noexcept
	{
		if (this != &other)
		{
			std::swap(other.data, this->data);
			std::exchange(other.size, this->size);
		}

		return *this;
	}

	const int& Array::operator[](size_t i) const
	{
		this->CheckIndex(i);
		return this->data[i];
	}

	int& Array::operator[](size_t i)
	{
		this->CheckIndex(i);
		return this->data[i];
	}

	size_t Array::GetSize() const
	{
		return this->size;
	}

	std::ostream& operator<<(std::ostream& out, const Array& array)
	{
		std::stringstream buffer{};
		size_t i = 0;
		for (; i < array.GetSize() - 1; ++i)
		{
			buffer << array[i] << ", ";
		}
		buffer << array[i] << "\n";

		return out << buffer.str();
	}
}
