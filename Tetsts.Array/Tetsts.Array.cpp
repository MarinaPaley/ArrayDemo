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
			//Assert::IsTrue(a1 == a2);
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
	};
}
