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

vector<Point2D> GrahamScan::find_hull_vertices(vector<Point2D> &inputVertices)
{
    vector<Point2D> OutputVertices;

    vector<int> IndexSet;
    IndexSet.push_back(0);
    IndexSet.push_back(1);
    int next_index = 2;

    while (next_index < inputVertices.size())
    {
        while (IndexSet.size() >= 2)
        {
            int first_index, second_index;
            second_index = IndexSet.back();
            IndexSet.pop_back();
            first_index = IndexSet.back();
            if (ccw(inputVertices[first_index], inputVertices[second_index], inputVertices[next_index]) > 0)
            // 바로 이전 2개의 점과 새로운 다음 점이 반 시계방향이라면 넣는다.
            {
                IndexSet.push_back(second_index);
                break;
            }
        }
        IndexSet.push_back(next_index++);
    }

    for (int index : IndexSet)
    {
        OutputVertices.push_back(inputVertices[index]);
    }

    sort(OutputVertices.begin(), OutputVertices.end(), [](Point2D p1, Point2D p2){
        return p1.id < p2.id;
    });

    return OutputVertices;
}