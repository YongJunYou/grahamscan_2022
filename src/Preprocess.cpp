#include <iostream>
#include <cstdlib>
#include "Point2D.h"
#include "Compare.h"

using namespace std;

void preprocess(Point2D inputVertices[], int n)
{
    cout << inputVertices[1].get_x() << endl;
    qsort(inputVertices,n,sizeof(Point2D),compare_y_x);
}