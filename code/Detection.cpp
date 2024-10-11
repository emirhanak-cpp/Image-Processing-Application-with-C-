#include "Detection.h"

Detection::Detection() {}

Detection::Detection(const string& path) {
    setFilePath(path);
}

Detection::~Detection() {}

string Detection::getFilePath() const {
    return pathofFile;
}

void Detection::setFilePath(const string& path) {
    pathofFile = path;
}

void Detection::writeToFile(const vector<Point2f>& features, const string& filePath) {
    ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        throw runtime_error("Failed to open output file");
    }
    for (size_t i = 0; i < features.size(); i++) {
        outputFile << features[i].x << "," << features[i].y << "\n";
    }
    outputFile.close();
}

void Detection::visualizeF(vector<Point2f> features) {
    Mat visualization = Mat::zeros(features.size(), CV_8UC3, CV_8UC3);
    for (size_t i = 0; i < features.size(); i++) {
        circle(visualization, features[i], 5, Scalar(0, 0, 255), FILLED);
    }
    imshow("Detected Features", visualization);
    waitKey(0);
}
