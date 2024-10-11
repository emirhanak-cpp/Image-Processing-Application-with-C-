#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <stdexcept>
#include "Detection.h"

using namespace cv;
using namespace std;

class LineDetection : public Detection {

public:
    LineDetection();
    ~LineDetection();
    void detectLines(Mat image);
    vector<Vec2f> getLines() const;
    void setLines(const vector<Vec2f>& lines);
    void printLineFeatures() const;

private:
    vector<Vec2f> _detectedLines;
};
