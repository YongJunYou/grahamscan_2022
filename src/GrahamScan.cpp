#include <iostream>
#include <vector>
#include "Point2D.h"
#include "GrahamScan.h"

using namespace std;

double ccw(const Point2D &p1,const Point2D &p2,const Point2D &p3)
{
    double v1x = p2.get_x() - p1.get_x();
    double v1y = p2.get_y() - p1.get_y();
    double v2x = p3.get_x() - p2.get_x();
    double v2y = p3.get_y() - p2.get_y();

    return v1x * v2y - v2x * v1y;
}

void GrahamScan::find_hull_vertices(vector<Point2D> &inputVertices)
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    int next = 2;
    // 다음 넣을 점

    while (next < inputVertices.size())
    // convex hull 만들기
    {
        while (v.size() >= 2)
        {
            int first, second;
            second = v.back();
            v.pop_back();
            first = v.back();
            if (ccw(inputVertices[first], inputVertices[second], inputVertices[next]) > 0)
            // 바로 이전 2개의 점과 새로운 다음 점이 반 시계방향이라면 넣는다.
            {
                v.push_back(second);
                break;
            }
        }
        v.push_back(next++);
    }

    FILE* fp2 = fopen("../output.txt", "wt"); 

    for (int index : v)
    {
        char str[22];
        sprintf(str, "%f %f\n", inputVertices[index].get_x(), inputVertices[index].get_y());
        fputs(str,fp2);
    }
    fclose(fp2);
}