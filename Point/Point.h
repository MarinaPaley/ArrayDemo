#pragma once
#include <iostream>
namespace Point 
{
	struct Point;
	bool operator==(const Point& lha, const Point& rha);
	bool operator!=(const Point& lha, const Point& rha);
	std::wstring ToString(Point* point);
	struct Point final
	{
		double x;
		double y;
		explicit Point(const double x = 0, const double y = 0);

		friend std::ostream& operator<<(std::ostream& out, const Point& point);
		friend std::wostream& operator<<(std::wostream& out, Point& point);
	};
}
