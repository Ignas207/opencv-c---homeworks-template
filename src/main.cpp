#include "main.h"

int main(int argc, char **argv)
{
    char path[PATH_MAX_LEN] = {0};

    LOG_EVENT("Program start!");
    if(argc != 2)
    {
        LOG_ERROR("Invalid usage! No path submitted!");
        puts("Usage: ./hw1 [PATH TO VIDEO FILE]");
        return 1;
    }

    if(GetPath(path, *(argv +1)))
    {
        return 1;
    }

    LOG_EVENT("Configured path: %s", path);

    cv::VideoCapture cap(cv::CAP_FFMPEG);
    try
    {
        if(!cap.open(path))
        {
            LOG_ERROR("Failed to open video file: %s", path);
            return 1;
        }
        // cap.open(0);
    }
    catch(const std::exception& e)
    {
        LOG_ERROR("Failed to open video stream: %s", e.what());
        return 1;
    }
    
    if(ProcessVideo(cap) != PROCESS_OK)
    {
        LOG_ERROR("ProcessVideo return with an error!");
        return 1;
    }

    cv::destroyAllWindows();

    LOG_EVENT("Processing okay!");
    return 0;
}

uint8_t GetPath(char *path, char *argv)
{
    size_t pathLen = strlen(argv);
    if(pathLen >= PATH_MAX_LEN)
    {
        LOG_ERROR("Maximum path lenght exceeded!");
        return 1;
    }

    strncpy(path, argv, pathLen);
    return 0;
}

void ShowImage(cv::Mat &image, const char* imageName)
{
    cv::namedWindow(imageName, cv::WINDOW_NORMAL | cv::WINDOW_KEEPRATIO | cv::WINDOW_GUI_EXPANDED);
    cv::imshow(imageName, image);
}