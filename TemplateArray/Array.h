#pragma once
#include <ostream>
#include <sstream>

namespace rut::cip::array
{
	template<typename T>
	class Array final
	{
	private:
		size_t size;
		T* data;
		void CheckIndex(const size_t i) const;
	public:
		explicit Array(const int size);
		Array(const std::initializer_list<T> list);
		Array(const Array& other);
		Array(Array&& other) noexcept;
		~Array();
		Array& operator=(const Array& other);
		Array& operator=(Array&& other) noexcept;

		const T& operator[](size_t i) const;
		T& operator[](size_t i);

		size_t GetSize() const;

		friend std::ostream& operator<<(std::ostream& os, const Array& array);
	};

	template<typename T>
	Array<T>::Array(const int size)
	{
		if (size <= 0)
		{
			throw std::logic_error("–азмер массива должен быть неотрицательным!");
		}

		this->size = static_cast<size_t>(size);
		this->data = new T[this->size];
	}

	template<typename T>
	Array<T>::Array(const std::initializer_list<T> list)
		: size{ list.size()}, data{new int[this->size]}
	{
		std::copy(list.begin(), list.end(), this->data);
	}

	template<typename T>
	Array<T>::Array(const Array& other)
		: size{ other.size }, data{ new int[this->size] }
	{
		std::copy(other.data, other.data + size, this->data);
	}

	template<typename T>
	Array<T>::Array(Array&& other) noexcept
		: size{ 0 }, data{ nullptr }
	{
		//std::swap(other.data, this->data);
		//std::exchange(other.size, this->size);
		*this = std::move(other);
	}

	template<typename T>
	Array<T>::~Array()
	{
		delete[] this->data;
	}

	template<typename T>
	Array<T>& Array<T>::operator=(const Array<T>& other)
	{
		if (this != &other)
		{
			delete[] this->data;
			this->size = other.size;
			this->data = new int[this->size];

			std::copy(other.data, other.data + other.size, this->data);
		}

		return *this;
	}

	template<typename T>
	Array<T>& Array<T>::operator=(Array<T>&& other) noexcept
	{
		if (this != &other)
		{
			std::swap(other.data, this->data);
			std::exchange(other.size, this->size);
		}

		return *this;
	}

	template<typename T>
	void Array<T>::CheckIndex(const size_t i) const
	{
		if (i >= this->GetSize())
		{
			throw std::out_of_range("«начение индекса больше размера массива!");
		}
	}

	template<typename T>
	const T& Array<T>::operator[](size_t i) const
	{
		this->CheckIndex(i);
		return this->data[i];
	}

	template<typename T>
	T& Array<T>::operator[](size_t i)
	{
		this->CheckIndex(i);
		return this->data[i];
	}

	template<typename T>
	size_t Array<T>::GetSize() const
	{
		return this->size;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Array<T>& array)
	{
		std::stringstream buffer;
		size_t i = 0;
		for (; i < array.GetSize() - 1; ++i)
		{
			buffer << array[i] << ", ";
		}
		buffer << array[i] << "\n";

		return os << buffer.str();
	}
}