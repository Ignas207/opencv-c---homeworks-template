#include "main.h"

int main(int argc, char **argv)
{
    char path[PATH_MAX_LEN] = {0};

    LOG_EVENT("Program start!");
    if(argc != 2)
    {
        LOG_ERROR("Invalid usage! No file submitted!");
        puts("Usage:    ./process [path_to_video_file].mp4\n \
         ./process [path_to_image_file].png\n \
         ./process [path_to_image_file].jpg\n \
         ./process camera=[camera device index, default=0]");
        return 1;
    }

    if(GetPath(path, *(argv +1)))
    {
        return 1;
    }

    LOG_EVENT("Configured path: %s", path);

    switch (GetMediaType(path))
    {
    case MEDIA_VIDEO:
        LOG_EVENT("Processing mode set to VIDEO!");
        if(SetupVideoProcessing(path))
            return 1;
        break;

    case MEDIA_PICTURE:
        LOG_EVENT("Processing mode set to PICTURE!");
        if(SetupImageProcessing(path))
            return 1;
        break;
    
    case MEDIA_CAMERA_VIDEO:
        LOG_EVENT("Processing mode set to CAMERA VIDEO!");
        LOG_ERROR("Not implemented!");
        break;

    default:
        LOG_ERROR("Unknown datatype detected: %s", path);
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

MEDIA_TYPE_t GetMediaType(const char *file)
{
    for (char ch = *file; ch != '\0'; ch = *++file)
    {
        if(ch == '.')
        {
            if(strncmp(file, MEDIA_EXT_MP4, sizeof(MEDIA_EXT_MP4)) == 0)
                return MEDIA_VIDEO;

            if(strncmp(file, MEDIA_EXT_PNG, sizeof(MEDIA_EXT_PNG)) == 0)
                return MEDIA_PICTURE;

            if(strncmp(file, MEDIA_EXT_JPEG, sizeof(MEDIA_EXT_JPEG)) == 0)
                return MEDIA_PICTURE;
        }
        if(ch == MEDIA_EXT_CAMERA[0])
        {
            // TODO: this can go out of bounds, so in the future
            //       find a better method!
            if(strncmp(file, MEDIA_EXT_CAMERA, sizeof(MEDIA_CAMERA_VIDEO)) == 0)
                return MEDIA_CAMERA_VIDEO;
        }
    }
    
    return MEDIA_UNKNOWN;
}

uint8_t SetupImageProcessing(const char* file)
{
    cv::Mat image;
    try
    {
        image = cv::imread(file);
        if(!image.data)
        {
            LOG_ERROR("Image is empty!");
            return 1;
        }

        if(ProcessImage(image) != PROCESS_OK)
        {
            LOG_ERROR("Process image returned ERROR!");
            return 1;
        }

    }
    catch(const std::exception& e)
    {
        LOG_ERROR("Failed to open image: %s", e.what());
        return 1;
    }
    return 0;
}

uint8_t SetupVideoProcessing(const char* file)
{
    cv::VideoCapture cap(file);
    try
    {
        if(!cap.open(file))
        {
            LOG_ERROR("Failed to open video file: %s", file);
            return 1;
        }
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

    return 0;
}

void ShowImage(cv::Mat &image, const char* imageName)
{
    cv::namedWindow(imageName, cv::WINDOW_NORMAL | cv::WINDOW_KEEPRATIO | cv::WINDOW_GUI_EXPANDED);
    cv::imshow(imageName, image);
}