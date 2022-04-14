#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include "Point2D.h"
#include "ReadWritePoint.h"
#include "GrahamScan.h"

using namespace std;

int main(int argc, char* argv[])
{
    string input_data_path  = "..\\data\\percent_10\\N10000_10.txt";
    string output_data_path = "..\\output.txt";
    string answer_data_path  = "..\\data\\percent_10\\N10000_10.rslt";

    vector<Point2D> input_vertices, output_vertices;
    vector<Point2D> answer_vertices; 

    ReadWrite ReadWriteFunc;
    input_vertices = ReadWriteFunc.read_point(input_data_path, input_vertices);
    answer_vertices = ReadWriteFunc.read_point(answer_data_path, answer_vertices);

    GrahamScan GrahamScanAlgo;
    input_vertices = GrahamScanAlgo.preprocess(input_vertices);
    output_vertices = GrahamScanAlgo.find_hull_vertices(input_vertices);

    if(ReadWriteFunc.same(output_vertices, answer_vertices))
        cout << "is the correct answer!!" << endl;

    ReadWriteFunc.write_point(output_data_path, output_vertices);
 
    cout << "finish" << endl;

    return 0;
}
