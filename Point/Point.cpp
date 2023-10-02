#include "Point.h"
#include <sstream>
#include <limits>
namespace Point
{
    Point::Point(const double x, const double)
        :x{ x }, y{ y }
    {

    }

    bool operator==(const Point& lha, const Point& rha)
    {
        return (abs(lha.x - rha.x) <= std::numeric_limits<double>::min()) &&
            (abs(lha.y - rha.y) <= std::numeric_limits<double>::min());
    }

    bool operator!=(const Point& lha, const Point& rha)
    {
        return !(lha == rha);
    }

    std::wstring ToString(Point* point)
    {
        std::wstringstream buffer{};
        buffer << point->x << L" " << point->y;
        return buffer.str();;
    }

    std::ostream& operator<<(std::ostream& out, const Point& point)
    {
        std::stringstream buffer{};
        buffer << point.x << " " << point.y;
        return out << buffer.str();
    }

    std::wostream& operator<<(std::wostream& out, Point& point)
    {
        return out << ToString(&point);
    }
}