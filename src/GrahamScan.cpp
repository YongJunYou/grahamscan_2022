#include <iostream>
#include <algorithm>
#include <vector>
#include "Point2D.h"
#include "GrahamScan.h"

using namespace std;

double GrahamScan::ccw(const Point2D &p1,const Point2D &p2,const Point2D &p3)
{
    double v1x = p2.get_x() - p1.get_x();
    double v1y = p2.get_y() - p1.get_y();
    double v2x = p3.get_x() - p2.get_x();
    double v2y = p3.get_y() - p2.get_y();

    return v1x * v2y - v2x * v1y;
}

vector<Point2D> GrahamScan::find_hull_vertices(vector<Point2D> &input_vertices)
{
    vector<Point2D> output_vertices;
    vector<Point2D>::iterator it;
    vector<Point2D>::iterator second, first;
    
    it = input_vertices.begin();
    output_vertices.push_back(*it);
    it++;
    output_vertices.push_back(*it);
    it++;


    for(it; it != input_vertices.end();it++)
    {
        while (true)
        {
            first = --(--output_vertices.end());
            second = --output_vertices.end();
            if (ccw(*first, *second, *it) > 0)
            {
                output_vertices.push_back(*it);
                break;
            }
            output_vertices.pop_back();
        }
    }  
/*
    vector<int> index_set;
    index_set.push_back(0);
    index_set.push_back(1);
    int next_index = 2;

    while (next_index < input_vertices.size())
    {
        while (index_set.size() >= 2)
        {
            int first_index, second_index;
            second_index = index_set.back();
            index_set.pop_back();
            first_index = index_set.back();
            if (ccw(input_vertices[first_index], input_vertices[second_index], input_vertices[next_index]) > 0)
            {
                index_set.push_back(second_index);
                break;
            }
        }
        index_set.push_back(next_index++);
    }

    for (int index : index_set)
    {
        output_vertices.push_back(input_vertices[index]);
    }
*/
    /*
    sort(output_vertices.begin(), output_vertices.end(), [](Point2D p1, Point2D p2){
        return p1.id < p2.id;
    });
    */
    return output_vertices;
}

vector<Point2D> GrahamScan::preprocess(vector<Point2D> &input_vertices)
{ 
    
    Point2D min_y_point = *min_element(input_vertices.begin(), input_vertices.end(), [](Point2D p1, Point2D p2){
        return p1.get_y() < p2.get_y();
    });
    
    GrahamScan::ExProductCompare Compare;
    Compare.m_standard_point_x = min_y_point.get_x();
    Compare.m_standard_point_y = min_y_point.get_y();

    sort(input_vertices.begin(), input_vertices.end(), Compare );

    return input_vertices;
}