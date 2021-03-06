/**
 * @file UVCamera.h
 * @author Yutaka Kondo <yutaka.kondo@youtalk.jp>
 * @date Aug 22, 2013
 */

#pragma once

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <boost/thread/thread.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ColorCamera.h"

namespace rgbd {

class UVCamera: public ColorCamera {
public:
    UVCamera(size_t deviceNo,
             const cv::Size& size = cv::Size(640, 480),
             double fps = 60.0);

    virtual ~UVCamera();

    cv::Size colorSize() const;

    virtual void start();

    virtual void captureColor(cv::Mat& buffer);

private:
    cv::VideoCapture _capture;

    const cv::Size _size;

    const long _usleep;

    cv::Mat _buffer;

    boost::mutex _mutex;

    void update();
};

}
