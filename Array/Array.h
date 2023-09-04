#pragma once
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
		Array(int size);
		Array(const Array& other);
		Array(Array&& other) noexcept;
		~Array();
		Array& operator=(const Array& other);
		Array& operator=(Array&& other) noexcept;
	};
}
