#include "CommonProcesses.h"

CommonProcesses::CommonProcesses(const string& filePathToReadImage, const string& filePathToWriteRGBData)
{
    setPathToWriteRGBData(filePathToWriteRGBData);
    setPathToReadImage(filePathToReadImage);
    readFromFile();
}

void CommonProcesses::readFromFile() {
    rawRGBData = imread(filePathToReadImage, IMREAD_COLOR);
    if (rawRGBData.empty()) {
        throw runtime_error("Failed to read image file");
    }
}

void CommonProcesses::writeToFile() {
    imwrite(filePathToWriteRGBData, rawRGBData);
}

void CommonProcesses::showImage() {
    imshow("RGB Image", rawRGBData);
    waitKey(0);
}

void CommonProcesses::rescaleImage(double scale_factor) {
    resize(rawRGBData, rawRGBData, Size(), scale_factor, scale_factor);
}

void CommonProcesses::filterNoise() {
    GaussianBlur(rawRGBData, rawRGBData, Size(3, 3), 0);
}

void CommonProcesses::rgbToGrayscale() {
    cvtColor(rawRGBData, rawRGBData, COLOR_BGR2GRAY);
}

Mat CommonProcesses::getRawRGBData() const {
    return rawRGBData.clone();
}

void CommonProcesses::setRawRGBData(const Mat& image) {
    rawRGBData = image.clone();
}

void CommonProcesses::printImageFeatures() const {
    cout << "Image Size: " << rawRGBData.size() << endl;
}

string CommonProcesses::getPathToReadImage() const {
    return filePathToReadImage;
}

void CommonProcesses::setPathToReadImage(const string& filePath) {
    filePathToReadImage = filePath;
}

string CommonProcesses::getPathToWriteRGBData() const {
    return filePathToWriteRGBData;
}

void CommonProcesses::setPathToWriteRGBData(const string& filePath) {
    filePathToWriteRGBData = filePath;
}
