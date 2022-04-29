#ifndef __READPOINT_H__
#define __READPOINT_H__

using namespace std;

class ReadWrite
{
    private:
        vector<string> split(string &input, const char delimiter);
    public:
        vector<Point2D> read_point(const string &input_data_path, vector<Point2D> &input_vertices);
        vector<Point2D> read_point_c(const string &input_data_path, vector<Point2D> &input_vertices);
        void write_point(const string &output_data_path, const vector<Point2D> &output_vertices);
        void write_point_c(const string &output_data_path, const vector<Point2D> &output_vertices);
        bool same(const vector<Point2D> &v1, const vector<Point2D> &v2);
};

#endif