#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include "Detection.h"

using namespace std;
using namespace cv;

class CommonProcesses : public Detection {
      public:
    CommonProcesses(const string& filePathToReadImage, const string& filePathToWriteRGBData);
    ~CommonProcesses() {};
    void readFromFile();
    void writeToFile();
    void showImage();
    void rescaleImage(double scale_factor);
    void filterNoise();
    void rgbToGrayscale();
    Mat getRawRGBData() const;
    void setRawRGBData(const Mat& image);
    void printImageFeatures() const;
    string getPathToReadImage() const;
    void setPathToReadImage(const string& filePath);
    string getPathToWriteRGBData() const;
    void setPathToWriteRGBData(const string& filePath);

private:
    string filePathToReadImage; 
    string filePathToWriteRGBData; 
    Mat rawRGBData;
};
             
