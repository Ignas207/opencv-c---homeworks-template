#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <stdint.h>
#include <string.h>
#include "logs.h"
#include "processing.h"

#define PATH_MAX_LEN 100U

#define MEDIA_EXT_MP4 ".mp4"
#define MEDIA_EXT_PNG ".png"
#define MEDIA_EXT_JPEG ".jpeg"
#define MEDIA_EXT_CAMERA "camera="

typedef enum
{
    MEDIA_VIDEO,
    MEDIA_PICTURE,
    MEDIA_CAMERA_VIDEO,
    MEDIA_UNKNOWN,
} MEDIA_TYPE_t;

void ShowImage(cv::Mat &image, const char* imageName);
uint8_t GetPath(char *path, char *argv);
MEDIA_TYPE_t GetMediaType(const char *file);
uint8_t SetupVideoProcessing(const char* file);
uint8_t SetupImageProcessing(const char* file);


#endif