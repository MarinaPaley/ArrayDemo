#pragma once
#include <ostream>
#include <sstream>
#include <string>

namespace rut::cip::array
{
	template<typename T> class Array;

	/**
	 * @brief Опрератор сдвига.
	 * @tparam T Тип данных массива.
	 * @param os Поток вывода.
	 * @param array Массив (целевой объект, направляемый в поток вывода).
	 * @return Изменённый поток вывода.
	*/
	template<typename T>
	std::ostream& operator<< (std::ostream& os, const Array<T>& array);

	/**
	 * @brief Опрератор сдвига в поток вывода "широких" символов.
	 * @tparam T Тип данных массива.
	 * @param os Поток вывода.
	 * @param array Массив (целевой объект, направляемый в поток вывода).
	 * @return Изменённый поток вывода.
	*/
	template<typename T>
	std::wostream& operator<< (std::wostream& os, const Array<T>& array);

	/**
	 * @brief Оператор равенства двух массивов.
	 * @tparam T Тип данных массива.
	 * @param lha Первый массив.
	 * @param rha Второй массив.
	 * @return \c true в случае равенства массивов, иначе \c false.
	*/
	template<typename T>
	bool operator==(const Array<T>& lha, const Array<T>& rha);

	/**
	 * @brief Оператор неравенства двух массивов.
	 * @tparam T Тип данных массива.
	 * @param lha Первый массив.
	 * @param rha Второй массив.
	 * @return \c false в случае равенства массивов, иначе \c true.
	*/
	template<typename T>
	bool operator!=(const Array<T>& lha, const Array<T>& rha);

	/**
	 * @brief Функция вывода масива в строку "широких" символов.
	 * @tparam T Тип данных массива.
	 * @param array Массив (целевой объект).
	 * @return Строковое представление данных массива.
	*/
	template<typename T>
	std::wstring ToString(const Array<T>& array);

	/**
	* @brief Класс массив.
	*/
	template<typename T>
	class Array final
	{
	private:
		/**
		* @brief Размер массива.
		*/
		size_t size;

		/**
		* @brief Данные массива.
		*/
		T* data;

		/**
		* @brief Проверка существования индекса.
		* @param i Индекс.
		*/
		void CheckIndex(const size_t i) const;
	public:
		/**
		 * @brief Конструктор.
		 * @param size Размер массива.
		*/
		explicit Array(const int size);

		/**
		 * @brief Конструктор.
		 * @param list Список инициализируемых объектов.
		*/
		Array(const std::initializer_list<T> list);

		/**
		 * @brief Конструктор копирования.
		 * @param other Другой массив, копируемый объект.
		*/
		Array(const Array& other);

		/**
		 * @brief Конструктор перемещения.
		 * @param other Другой массив (перемещаемый объект).
		*/
		Array(Array&& other) noexcept;

		/**
		 * @brief Деструктор.
		*/
		~Array();

		/**
		 * @brief Оператор копирования.
		 * @param other Другой массив, подлежащий копированию.
		 * @return Скопированный объект.
		*/
		Array& operator=(const Array& other);

		/**
		 * @brief Оператор перемещения.
		 * @param other Другой массив, подлежащий перемещению.
		 * @return Перемещенны объект.
		*/
		Array& operator=(Array&& other) noexcept;

		/**
		 * @brief Индексатор. Предоставляет доступ только на чтение.
		 * @param i Индекс.
		 * @return Значение разыменованного объекта по индексу.
		*/
		const T& operator[](size_t i) const;

		/**
		 * @brief Индексатор. Предоставляет доступ на изменение.
		 * @param i Индекс.
		 * @return Значение разыменованного объекта по индексу.
		*/
		T& operator[](size_t i);

		/**
		 * @brief Метод получения размера массива.
		 * @return Размер массива.
		*/
		size_t GetSize() const;
	};

	template<typename T>
	Array<T>::Array(const int size)
	{
		if (size <= 0)
		{
			throw std::logic_error("Размер массива должен быть неотрицательным!");
		}

		this->size = static_cast<size_t>(size);
		this->data = new T[this->size];
	}

	template<typename T>
	Array<T>::Array(const std::initializer_list<T> list)
		: size{ list.size() }, data{ new T[this->size] }
	{
		std::copy(list.begin(), list.end(), this->data);
	}

	template<typename T>
	Array<T>::Array(const Array& other)
		: size{ other.size }, data{ new T[this->size] }
	{
		*this = other;
	}

	template<typename T>
	Array<T>::Array(Array&& other) noexcept
		: size{ 0 }, data{ nullptr }
	{
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
			this->data = new T[this->size];

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
			// Почему-то не работает
			//std::exchange(other.size, this->size);
			std::swap(other.size, this->size);
		}

		return *this;
	}

	template<typename T>
	void Array<T>::CheckIndex(const size_t i) const
	{
		if (i >= this->GetSize())
		{
			throw std::out_of_range("Неправильное значение индекса!");
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
		std::stringstream buffer{};
		size_t i = 0;
		for (; i < array.GetSize() - 1; ++i)
		{
			buffer << array[i] << ", ";
		}
		buffer << array[i] << "\n";

		return os << buffer.str();
	}

	template<typename T>
	std::wostream& operator<<(std::wostream& os, const Array<T>& array)
	{
		std::stringstream temp{};
		temp << array;
		std::string tempString = temp.str();

		std::wstringstream buffer{};
		buffer << temp.rdbuf();

		return os << buffer.str();
	}

	template<typename T>
	std::wstring ToString(const Array<T>& array)
	{
		std::wstringstream buffer{};
		buffer << array;

		return buffer.str();
	}

	template<typename T>
	bool operator== (const Array<T>& lha, const Array<T>& rha)
	{
		if (lha.GetSize() != rha.GetSize())
		{
			return false;
		}

		for (size_t i = 0; i < lha.GetSize(); ++i)
		{
			if (lha[i] != rha[i])
			{
				return false;
			}
		}

		return true;
	}

	template<typename T>
	bool operator!= (const Array<T>& lha, const Array<T>& rha)
	{
		return !(lha == rha);
	}
}
