#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Point2D.h"
#include "Split.h"
using namespace std;

void read_point(const string input_data_path, vector<Point2D> &inputVertices)
{
    ifstream file_s;
    string line;
    int index = 0;
    
    file_s.open(input_data_path);
    
    if(file_s.is_open())
    {
        getline(file_s, line);

        while (getline(file_s, line))
        {
            vector<string> result = split(line,'	');
            double p_x = stod(result[1]); 
            double p_y = stod(result[2]);

            inputVertices.push_back(Point2D(p_x,p_y)); //
        }
    }
    file_s.close();
}
