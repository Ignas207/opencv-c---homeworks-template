#include "processing.h"

static uint8_t IsProcessingCanceled();

/**
 * @brief Sends the video stream to our algorithm.
 * 
 * @param video Video stream to process.
 * @author https://learnopencv.com/read-write-and-display-a-video-using-opencv-cpp-python/
 * @return PROCESS_STATUS_t 
 */ 
PROCESS_STATUS_t ProcessVideo(cv::VideoCapture &video)
{
    if(!video.isOpened())
    {
        LOG_ERROR("Video is not openned!");
        return PROCESS_FAILED;
    }

    cv::Mat frame;
    while (video.read(frame))
    {
        if(frame.empty())
        {
            LOG_EVENT("Frame is empty, processing done!");
            return PROCESS_OK;
        }

        cv::imshow("Raw frame", frame);

        // HW1_ExtractCubes(frame);

        if(IsProcessingCanceled())
            break;
    }
    return PROCESS_OK;
}

/**
 * @brief Checks if a cancelation is requested
 *        with ESC key.
 * 
 * @return uint8_t: 1 if requested.
 */
static uint8_t IsProcessingCanceled()
{
    char c = (char)cv::waitKey(25);
    if(c == PROCESSING_ESC_KEY)
    {
        return 1;
    }
    return 0;
}