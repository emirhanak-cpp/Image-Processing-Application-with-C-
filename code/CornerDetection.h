#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <stdexcept>
#include "Detection.h"

using namespace cv;
using namespace std;

class CornerDetection : public Detection {
public:
    CornerDetection();
    ~CornerDetection();
    void Cornersfound(Mat image);
    vector<Point2f> getCorners() const;
    void printCorner() const;
    void setCorners(const vector<Point2f>& corners);

private:
    vector<Point2f> _detectedCorners;
};
