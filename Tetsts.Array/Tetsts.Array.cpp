#include <string>
#include <stdexcept>
#include "pch.h"
#include "CppUnitTest.h"
#include "..\TemplateArray\Array.h"
#include "..\Point\Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace rut::cip::array;

namespace TetstsArray
{
	TEST_CLASS(TetstsArray)
	{
	public:
		
		TEST_METHOD(CtorInt_ValidData_Success)
		{
			// Arrange & Act
			const size_t size = 5;
			auto array = new Array<int>(size);
			

			Assert::IsNotNull(array);
			Assert::AreEqual(array->GetSize(), size);
		}

		TEST_METHOD(CtorString_ValidData_Success)
		{
			// Arrange & Act
			const size_t size = 5;
			auto array = new Array<std::string>(size);


			Assert::IsNotNull(array);
			Assert::AreEqual(array->GetSize(), size);
		}

		TEST_METHOD(CtorInt_NegativeSize_ExpectedException)
		{
			// Arrange
			const int size = -5;

			// Act & Assert
			Assert::ExpectException<std::logic_error>(
				[]() {auto x = new Array<int>(size); });
		}

		TEST_METHOD(CtorString_NegativeSize_ExpectedException)
		{
			// Arrange
			const int size = -5;

			// Act & Assert
			Assert::ExpectException<std::logic_error>(
				[]() {auto x = new Array < std::string > (size); });
		}

		TEST_METHOD(IntArraysAreEqual_ValidData_Success)
		{
			// Arrange
			const Array<int> a1{ 1, 2, 3, 4, 5 };
			const Array<int> a2{ 1, 2, 3, 4, 5 };
			// Act & Assert
			Assert::AreEqual(a1, a2);
		}

		TEST_METHOD(StringArraysAreEqual_ValidData_Success)
		{
			// Arrange
			const std::string s1 = "1";
			const std::string s2 = "2";
			const std::string s3 = "3";
			const Array<std::string> a1{ s1, s2, s3 };
			const Array<std::string> a2{ s1, s2, s3 };
			// Act & Assert
			Assert::AreEqual(a1, a2);
		}

		TEST_METHOD(OperatorEqualInt_ValidData_Success)
		{
			// Arrange
			const Array<int> a1{ 1, 2, 3, 4, 5 };
			const Array<int> a2{ 1, 2, 3, 4, 5 };

			//Act & Assert
			Assert::IsTrue(a1 == a2);
		}

		TEST_METHOD(OperatorEqualString_ValidData_Success)
		{
			// Arrange
			const std::string s1 = "1";
			const std::string s2 = "2";
			const std::string s3 = "3";
			const Array<std::string> a1{ s1, s2, s3 };
			const Array<std::string> a2{ s1, s2, s3 };

			//Act & Assert
			Assert::IsTrue(a1 == a2);
		}

		TEST_METHOD(OperatorEqualPoint_ValidData_Success)
		{
			// Arrange
			const Point::Point point1{};
			const Point::Point point2{1, 2};
			const Point::Point point3{5, 8};

			const Array<Point::Point> a1{ point1, point2, point3 };
			const Array<Point::Point> a2{ point1, point2, point3 };

			//Act & Assert
			Assert::IsTrue(a1 == a2);
		}

		TEST_METHOD(CopyCtorStringArray_ValidData_Success)
		{
			// Arrange
			const std::string s1 = "1";
			const std::string s2 = "2";
			const std::string s3 = "3";
			const Array<std::string> a1{ s1, s2, s3 };
			// Act
			const Array<std::string> a2(a1);
			Array<std::string> a3(a1);
			a3[0] = "0";
			// Assert
			Assert::AreNotSame(a1, a2);
			Assert::AreEqual(a1, a2);
			Assert::AreNotEqual(a1, a3);
		}

		TEST_METHOD(CopyCtorIntArray_ValidData_Success)
		{
			// Arrange
			const Array<int> a1{ 1, 2, 3, 4, 5 };
			// Act
			const Array<int> a2(a1);
			Array<int> a3(a1);
			a3[0] = 0;
			// Assert
			Assert::AreNotSame(a1, a2);
			Assert::AreEqual(a1, a2);
			Assert::AreNotEqual(a1, a3);
		}

		TEST_METHOD(CopyCtorPointArray_ValidData_Success)
		{
			// Arrange
			const Point::Point point1{};
			const Point::Point point2{1, 2};
			const Point::Point point3{5, 8};

			const Array<Point::Point> a1{ point1, point2, point3 };

			// Act
			const Array<Point::Point> a2(a1);
			Array<Point::Point> a3(a1);
			const Point::Point point4{10, 23};
			a3[0] = point4;

			// Assert
			Assert::AreNotSame(a1, a2);
			Assert::AreEqual(a1, a2);
			Assert::AreNotEqual(a1, a3);
		}

		TEST_METHOD(CopyAssignStringArray_ValidData_Success)
		{
			// Arrange
			const std::string s1 = "1";
			const std::string s2 = "2";
			const std::string s3 = "3";
			Array<std::string> a1{ s1, s2, s3 };

			Array<std::string> a2{};
			Array<std::string> a3{};

			// Act
			a1 = a1;
			a2 = a1;
			a3 = a1;
			a3[0] = "0";

			// Assert
			Assert::AreNotSame(a1, a2);
			Assert::AreEqual(a1, a2);
			Assert::AreNotEqual(a1, a3);
		}

		TEST_METHOD(CopyAssignIntArray_ValidData_Success)
		{
			// Arrange
			Array<int> a1{ 1, 2, 3, 4, 5 };
			Array<int> a2{};
			Array<int> a3{};

			// Act
			a1 = a1;
			a2 = a1;
			a3 = a1;
			a3[0] = 0;

			// Assert
			Assert::AreNotSame(a1, a2);
			Assert::AreEqual(a1, a2);
			Assert::AreNotEqual(a1, a3);
		}

		TEST_METHOD(CopyAssignPointArray_ValidData_Success)
		{
			// Arrange
			const Point::Point point1{};
			const Point::Point point2{1, 2};
			const Point::Point point3{5, 8};

			Array<Point::Point> a1{ point1, point2, point3 };
			Array<Point::Point> a2{};
			Array<Point::Point> a3{};

			// Act
			a1 = a1;
			a2 = a1;
			a3 = a1;
			const Point::Point point4{10, 23};
			a3[0] = point4;

			// Assert
			Assert::AreNotSame(a1, a2);
			Assert::AreEqual(a1, a2);
			Assert::AreNotEqual(a1, a3);
		}

		/*
		*@brief Move ctors
		*/
		TEST_METHOD(MoveCtorStringArray_ValidData_Success)
		{
			// Arrange
			const std::string s1 = "1";
			const std::string s2 = "2";
			const std::string s3 = "3";
			Array<std::string> a1{ s1, s2, s3 };
			size_t size = 3;

			// Act
			const Array<std::string> a2(std::move(a1));
			
			// Assert
			Assert::AreEqual(size, a2.GetSize());
		}

		TEST_METHOD(MoveCtorIntArray_ValidData_Success)
		{
			// Arrange
			Array<int> a1{ 1, 2, 3, 4, 5 };
			size_t size = 5;

			// Act
			const Array<int> a2(std::move(a1));

			// Assert
			Assert::AreEqual(size, a2.GetSize());
		}

		TEST_METHOD(MoveCtorPointArray_ValidData_Success)
		{
			// Arrange
			const Point::Point point1{};
			const Point::Point point2{1, 2};
			const Point::Point point3{5, 8};

			Array<Point::Point> a1{ point1, point2, point3 };
			size_t size = 3;

			// Act
			const Array<Point::Point> a2(std::move(a1));

			// Assert
			Assert::AreEqual(size, a2.GetSize());
		}

		TEST_METHOD(MoveAssignStringArray_ValidData_Success)
		{
			// Arrange
			const std::string s1 = "1";
			const std::string s2 = "2";
			const std::string s3 = "3";
			Array<std::string> a1{ s1, s2, s3 };
			size_t size = 3;

			Array<std::string> a2{};
			Array<std::string> a3{};

			// Act
			a1 = std::move(a1);
			a2 = std::move(a1);

			// Assert
			Assert::AreEqual(size, a2.GetSize());
		}

		TEST_METHOD(MoveAssignIntArray_ValidData_Success)
		{
			// Arrange
			Array<int> a1{ 1, 2, 3, 4, 5 };
			Array<int> a2{};
			Array<int> a3{};
			size_t size = 5;

			// Act
			a1 = std::move(a1);
			a2 = std::move(a1);

			// Assert
			Assert::AreEqual(size, a2.GetSize());
		}

		TEST_METHOD(MoveAssignPointArray_ValidData_Success)
		{
			// Arrange
			const Point::Point point1{};
			const Point::Point point2{1, 2};
			const Point::Point point3{5, 8};

			Array<Point::Point> a1{ point1, point2, point3 };
			size_t size = 3;

			Array<Point::Point> a2{};
			Array<Point::Point> a3{};

			// Act
			a1 = std::move(a1);
			a2 = std::move(a1);

			// Assert
			Assert::AreEqual(size, a2.GetSize());
		}
	};
}
