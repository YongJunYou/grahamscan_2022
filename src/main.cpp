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
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    clock_t start, end1, end2, end3, finish;
    double duration1, duration2, duration3, duration4, total;

    start = clock();
    string input_data_path  = "..\\data\\percent_10\\N100000_10.txt";
    string output_data_path = "..\\output.txt";

    vector<Point2D> input_vertices, output_vertices;

    ReadWrite ReadWriteFunc;
    input_vertices = ReadWriteFunc.read_point_c(input_data_path, input_vertices);
    end1 = clock();

    GrahamScan GrahamScanAlgo;
    input_vertices = GrahamScanAlgo.preprocess(input_vertices);
    end2 = clock();

    output_vertices = GrahamScanAlgo.find_hull_vertices(input_vertices);
    end3 = clock();

    ReadWriteFunc.write_point(output_data_path, output_vertices);

    finish = clock();
 
    duration1 = (double)(end1 - start) / CLOCKS_PER_SEC;
    duration2 = (double)(end2 - end1) / CLOCKS_PER_SEC;
    duration3 = (double)(end3 - end2) / CLOCKS_PER_SEC;
    duration4 = (double)(finish - end3) / CLOCKS_PER_SEC;
    total = (double)(finish - start) / CLOCKS_PER_SEC;
    
    cout << duration1 << endl;
    cout << duration2 << endl;
    cout << duration3 << endl;
    cout << duration4 << endl;
    cout << total << endl;

    cout << "finish" << endl;
    return 0;
}
