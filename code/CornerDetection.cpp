#include "CornerDetection.h"

CornerDetection::CornerDetection() {}

CornerDetection::~CornerDetection() {}

void CornerDetection::Cornersfound(Mat image) {
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    goodFeaturesToTrack(gray, _detectedCorners, 100, 0.01, 10);
    for (int i = 0; i < _detectedCorners.size(); i++) {
        circle(image, _detectedCorners[i], 3, Scalar(0, 255, 0), -1);
    }
    imshow("Detected Corners", image);
    waitKey(0);
}

vector<Point2f> CornerDetection::getCorners() const {
    return _detectedCorners;
}

void CornerDetection::printCorner() const {
    cout << "Number of detected corners: " << _detectedCorners.size() << endl;
}

void CornerDetection::setCorners(const vector<Point2f>& corners) {
    _detectedCorners = corners;
}
