#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace cv;
using namespace std;

class Detection {

public:
    Detection();
    Detection(const string& path);
    ~Detection();
    string getFilePath() const;
    void setFilePath(const string& path);
    virtual void writeToFile(const vector<Point2f>& features, const string& pathofFile);
    virtual void visualizeF(vector<Point2f> features);

private:
    string pathofFile;

};
