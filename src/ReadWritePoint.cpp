#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Point2D.h"
#include "ReadWritePoint.h"
using namespace std;

vector<string> ReadWrite::split(string &input, const char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

vector<Point2D> ReadWrite::read_point(const string &input_data_path, vector<Point2D> &inputVertices)
{
    ifstream ifile;
    string line;
    int index = 0;
    
    ifile.open(input_data_path);
    
    if(ifile.is_open())
    {
        getline(ifile, line);

        while (getline(ifile, line))
        {
            vector<string> result = split(line,'	');
            double p_x = stod(result[1]); 
            double p_y = stod(result[2]);
            int p_id = stoi(result[0]);

            inputVertices.push_back(Point2D(p_id,p_x,p_y));
        }
    }
    ifile.close();

    return inputVertices;
}

void ReadWrite::write_point(const string &output_data_path, const vector<Point2D> &outputVertices)
{
    ofstream ofile;
    ofile.open(output_data_path);
    if(ofile.is_open())
    {
        for (Point2D point : outputVertices)
        {
            ofile << point.get_x() << " " << point.get_y() << endl;
        }
    }
    ofile.close();
}