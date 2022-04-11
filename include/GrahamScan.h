#ifndef __GRAHAMSCAN_H__
#define __GRAHAMSCAN_H__

using namespace std;

class GrahamScan
{
    private:
        double ccw(const Point2D &p1,const Point2D &p2,const Point2D &p3);
    public:
        vector<Point2D> find_hull_vertices(vector<Point2D> &inputVertices);
};

#endif