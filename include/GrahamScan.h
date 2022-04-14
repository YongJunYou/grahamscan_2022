#ifndef __GRAHAMSCAN_H__
#define __GRAHAMSCAN_H__

using namespace std;

class GrahamScan
{
private:
    double ccw(const Point2D &p1,const Point2D &p2,const Point2D &p3);
    
public:
    vector<Point2D> find_hull_vertices(vector<Point2D> &input_vertices);
    vector<Point2D> preprocess(vector<Point2D> &input_vertices);
    
    class ExProductCompare {
    public:
        double m_standard_point_x ;
        double m_standard_point_y ;
        bool operator()(const Point2D &p1, const Point2D &p2)
        {
            double x1 = p1.get_x();
            double y1 = p1.get_y();  
            double x2 = p2.get_x();
            double y2 = p2.get_y();
            double external_product = (x1-m_standard_point_x)*(y2-m_standard_point_y)-(x2-m_standard_point_x)*(y1-m_standard_point_y);

            if (external_product > 0)
                return true;
            if (external_product < 0)
                return false;
            if (y1 < y2)   
                return true;    
            if (y1 > y2)   
                return false;      
                
            return true;
        }
    };
};

#endif