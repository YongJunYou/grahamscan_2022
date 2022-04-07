#include <iostream>
#include <string>
#include <vector>
#include "Point2D.h"
#include "ReadPoint.h"
#include "Preprocess.h"
#include "GrahamScan.h"

using namespace std;

int main(int argc, char* argv[])
{
    string input_data_path  = "..\\data\\percent_10\\N100000_10.txt";
    string output_data_path = "..\\data\\percent_10\\Result_N100000_10.txt";

    vector<Point2D> inputVertices; 
    read_point(input_data_path, inputVertices);

    preprocess(inputVertices);

    GrahamScan GrahamScanAlgo;
    GrahamScanAlgo.find_hull_vertices(inputVertices);
    
    string fin = "finish";
    cout << fin << endl;

    return 0;
}