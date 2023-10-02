#ifndef PROCESSING_H
#define PROCESSING_H

#include "main.h"
#include <opencv2/opencv.hpp>

#define PROCESSING_ESC_KEY 27U

typedef enum
{
    PROCESS_OK,
    PROCESS_FAILED,
} PROCESS_STATUS_t;

PROCESS_STATUS_t ProcessVideo(cv::VideoCapture &video);
PROCESS_STATUS_t ProcessImage(cv::Mat &image);

#endif