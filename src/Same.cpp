#include <iostream>
#include <vector>
#include "Point2D.h"

using namespace std;

bool same(const vector<Point2D> &v1, const vector<Point2D> &v2) {
    for (int i=0; i < v1.size(); i++)
    {
        if(v1[i].id != v2[i].id)
        {
			return false;
        }
    }
	return true;
}