#ifndef __POINT2D_H__
#define __POINT2D_H__

using namespace std;

class Point2D
{
private:
    double m_X;
    double m_Y;

public:
    Point2D(double X=0.0, double Y=0.0)
    {
        this->m_X = X;
        this->m_Y = Y;
    }
    inline double   get_x() const { return m_X; };
    inline double   get_y() const { return m_Y; };

    inline void     set_x(const double &px) { m_X = px; };
    inline void     set_y(const double &py) { m_Y = py; };
    inline void     set_point(const Point2D &point) { m_X = point.m_X; m_Y = point.m_Y; };
    inline void     set_point(const double& px, const double& py) { m_X = px; m_Y = py; };

};

#endif