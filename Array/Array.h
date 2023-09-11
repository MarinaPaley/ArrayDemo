#pragma once
#include <initializer_list>
#include <ostream>

namespace rut::uizi::array
{
	/*
	* @brief Класс вектор...)
	*/
	class Array final
	{
	private:
		size_t size;
		int* data;
	public:
		explicit Array(const int size);
		Array(const std::initializer_list<int> list);
		Array(const Array& other);
		Array(Array&& other) noexcept;
		~Array();
		Array& operator=(const Array& other);
		Array& operator=(Array&& other) noexcept;

		const int& operator[](size_t i) const;
		int& operator[](size_t i);

		size_t GetSize() const;

		friend std::ostream& operator<<(std::ostream& os, const Array& array);
	};
}
