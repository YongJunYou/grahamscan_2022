#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include "Point2D.h"
#include "ReadWritePoint.h"
using namespace std;

vector<string> ReadWrite::split(string &input, const char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

vector<Point2D> ReadWrite::read_point(const string &input_data_path, vector<Point2D> &input_vertices)
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
            input_vertices.push_back(Point2D(p_id,p_x,p_y));
        }
    }
    ifile.close();

    return input_vertices;
}

vector<Point2D> ReadWrite::read_point_c(const string &input_data_path, vector<Point2D> &input_vertices)
{
    const int max = 40;
    char line[max];
    char *pLine;
    char *Line1;
    char *Line2;
    char *Line3;
    char input_data_path_c[30];
    strcpy(input_data_path_c,input_data_path.c_str());

    FILE *fp = fopen(input_data_path_c, "r");
    while (!feof(fp)) {
        pLine = fgets(line, max, fp);

        Line1 = strtok(pLine,"\t");
        Line2 = strtok(NULL,"\t");
        Line3 = strtok(NULL,"\t");

        int p_id = atoi(Line1);
        double p_x = atof(Line2);
        double p_y = atof(Line3);
        
        input_vertices.push_back(Point2D(p_id,p_x,p_y));
    }
    fclose(fp);

    return input_vertices;
}

void ReadWrite::write_point(const string &output_data_path, const vector<Point2D> &output_vertices)
{
    ofstream ofile;
    ofile.open(output_data_path);
    if(ofile.is_open())
    {
        for (Point2D point : output_vertices)
        {
            ofile << point.get_x() << " " << point.get_y() << endl;
        }
    }
    ofile.close();
}

void ReadWrite::write_point_c(const string &output_data_path, const vector<Point2D> &output_vertices)
{
    char output_data_path_c[30];
    strcpy(output_data_path_c,output_data_path.c_str());

    FILE *fp = fopen(output_data_path_c, "r");
    if(!feof(fp))
    {
        for (Point2D point : output_vertices)
        {
            //fprintf(fp, "%f %f\n", point.get_x(), point.get_y());
            char s[30];
            sprintf(s,"%f %f", point.get_x(), point.get_y());
            fputs(s, fp);
        }
    }
    fclose(fp);
}

bool ReadWrite::same(const vector<Point2D> &v1, const vector<Point2D> &v2) {
    for (int i=0; i < v1.size(); i++)
    {
        if(v1[i].id != v2[i].id)
        {
			return false;
        }
    }
	return true;
}