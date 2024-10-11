#include <iostream>
#include <opencv2/opencv.hpp>
#include "CommonProcesses.h"
#include "LineDetection.h"
#include "CornerDetection.h"

using namespace std;

int main() {

    const string imagePathtoRead = ""; //insert your image read path
    const string imagePathtoWrite = ""; //insert your image write path
    const string corner = "";

    CommonProcesses imageP(imagePathtoRead, imagePathtoWrite);
    LineDetection lineD;
    CornerDetection cornerD;
    Mat rawRGBdata = imageP.getRawRGBData();
    lineD.detectLines(rawRGBdata);
    cornerD.Cornersfound(rawRGBdata);
    vector<Point2f> corners = cornerD.getCorners();
    cornerD.writeToFile(corners, corner);

    waitKey(0);

    return 0;
}


