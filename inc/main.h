#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <stdint.h>
#include <string.h>
#include "logs.h"
#include "processing.h"

#define PATH_MAX_LEN 100U

void ShowImage(cv::Mat &image, const char* imageName);
uint8_t GetPath(char *path, char *argv);

#endif