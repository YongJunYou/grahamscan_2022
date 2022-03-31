#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Point2D.h"
#include "Split.h"
using namespace std;

void read_point(string inputFileNameWithPath,Point2D inputVertices[])
{
    ifstream file_s;
    string line;
    int index = 0;
    
    file_s.open(inputFileNameWithPath);
    
    if(file_s.is_open())
    {
        getline(file_s, line);

        while (getline(file_s, line))
        {
            vector<string> result = split(line,'	'); // '	' 이게 뭔지는 모르겠지만 tab, space 둘다 인식됨
            double p_x = stod(result[1]); 
            double p_y = stod(result[2]);

            inputVertices[index].set_x(p_x);
            inputVertices[index].set_y(p_y);

            index++;
        }
    }
    file_s.close();
}
