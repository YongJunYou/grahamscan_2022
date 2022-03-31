#include <iostream>
#include <string>
#include "Point2D.h"
#include "ReadPoint.h"
#include "Preprocess.h"
#include "GrahamScan.h"

using namespace std;

int main(int argc, char* argv[])
{
    string inputFileNameWithPath  = "..\\data\\percent_10\\N100000_10.txt";
    string outputFileNameWithPath = "..\\data\\percent_10\\Result_N100000_10.txt";

    Point2D inputVertices[100000];
    read_point(inputFileNameWithPath,inputVertices);

    cout << inputVertices[0].get_x() << endl;

    preprocess(inputVertices,1000000);

    cout << inputVertices[0].get_x() << endl;

    GrahamScan GrahamScanAlgo;
    GrahamScanAlgo.find_hull_vertices();

    cout << "finish" << endl;
    return 0;
}