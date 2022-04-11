#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Point2D.h"
#include "ReadWritePoint.h"
#include "Preprocess.h"
#include "GrahamScan.h"
#include "Same.h"

using namespace std;

int main(int argc, char* argv[])
{
    clock_t start, end1, end2, end3, finish;
    double duration1, duration2, duration3, duration4, total;

    start = clock();
    string input_data_path  = "..\\data\\percent_10\\N100000_10.txt";
    string output_data_path = "..\\output.txt";
    //string answer_data_path  = "..\\data\\percent_10\\N100000_10.rslt";

    vector<Point2D> inputVertices, outputVertices;
    //vector<Point2D> answerVertices; 

    ReadWrite ReadWriteAlgo;
    inputVertices = ReadWriteAlgo.read_point(input_data_path, inputVertices);
    //answerVertices = ReadWriteAlgo.read_point(answer_data_path, answerVertices);

    end1 = clock();

    PreProcess PreProcessAlgo;
    inputVertices = PreProcessAlgo.preprocess(inputVertices);

    end2 = clock();

    GrahamScan GrahamScanAlgo;
    outputVertices = GrahamScanAlgo.find_hull_vertices(inputVertices);

    end3 = clock();
    
    //if(same(outputVertices, answerVertices))
        //cout << "is the correct answer!!" << endl;

    ReadWriteAlgo.write_point(output_data_path, outputVertices);

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
    //cout << "finish" << endl;


    return 0;
}
