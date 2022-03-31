#ifndef __POINT2D_H__
#define __POINT2D_H__

using namespace std;

class Point2D
{
private:
    double m_X;
    double m_Y;

public:
    inline double   get_x() const { return m_X; };
    inline double   get_y() const { return m_Y; };

    inline void     set_x(const double &px) { m_X = px; }; // inline 으로 사용가능하고, 참조자를 활용하였다.
    inline void     set_y(const double &py) { m_Y = py; };
    inline void     set_point(const Point2D &point) { m_X = point.m_X; m_Y = point.m_Y; };
    inline void     set_point(const double& px, const double& py) { m_X = px; m_Y = py; };
};

#endif