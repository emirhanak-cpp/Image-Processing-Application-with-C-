#include "LineDetection.h"

using namespace cv;
using namespace std;

LineDetection::LineDetection() {}

LineDetection::~LineDetection() {}

void LineDetection::detectLines(Mat image) {
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);

    Mat edges;
    Canny(gray, edges, 50, 150, 3);

    HoughLines(edges, _detectedLines, 1, CV_PI / 80, 100);

    for (size_t i = 0; i < _detectedLines.size(); i++) {
        float rho = _detectedLines[i][0];
        float theta = _detectedLines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        pt1.x = cvRound(x0 + 1000 * (-b));
        pt1.y = cvRound(y0 + 1000 * (a));
        pt2.x = cvRound(x0 - 1000 * (-b));
        pt2.y = cvRound(y0 - 1000 * (a));
        line(image, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);
    }

    imshow("Detected Lines", image);
    waitKey(0);
}

vector<Vec2f> LineDetection::getLines() const {
    return _detectedLines;
}

void LineDetection::setLines(const vector<Vec2f>& lines) {
    _detectedLines = lines;
}

void LineDetection::printLineFeatures() const {
    cout << "Number of detected lines: " << _detectedLines.size() << endl;
}
