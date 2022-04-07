#include <iostream>
#include <vector>
#include <algorithm>
#include "Point2D.h"

using namespace std;

double standard_point_x;
double standard_point_y;

int angle(const void* p1, const void* p2)
{
    double x1 = ((Point2D*)p1)->get_x();
    double y1 = ((Point2D*)p1)->get_y();  
    double x2 = ((Point2D*)p2)->get_x();
    double y2 = ((Point2D*)p2)->get_y();
    double external_product = (x1-standard_point_x)*(y2-standard_point_y)-(x2-standard_point_x)*(y1-standard_point_y);

    if (external_product > 0)
        return -1;
    if (external_product < 0)
        return 1;
    if (y1 < y2)   
        return -1;    
    if (y1 > y2)   
        return 1;      
        
    return 0;
}

void preprocess(vector<Point2D> &inputVertices)
{ 
    Point2D standard_point = *min_element(inputVertices.begin(), inputVertices.end(), [](Point2D p1, Point2D p2){
        return p1.get_y() < p2.get_y();
    });
    standard_point_x = standard_point.get_x();
    standard_point_y = standard_point.get_y();
    qsort(&inputVertices[0], inputVertices.size(), sizeof(Point2D), angle);
}