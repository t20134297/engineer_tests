#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
  VideoCapture capture("youyisi.mpeg");
  Mat frame;
  int rate=capture.get(CV_CAP_PROP_FPS);
  int delay=1000/rate;
  if(!capture.isOpened())
    return 0;
  while(capture.read(frame))
    {
      imshow("original video",frame);
      waitKey(delay);
    }
  int number=capture.get(CV_CAP_PROP_FRAME_COUNT);
  int position=number/3;
  capture.set(CV_CAP_PROP_POS_FRAMES,position);//设置视频从第position帧开始播放
  while(capture.read(frame))
  {
    imshow("position video",frame);
    waitKey(delay);
  }
  double time=9000;
  capture.set(CV_CAP_PROP_POS_MSEC,time);//从第time毫秒开始
  while(capture.read(frame))
    {
      imshow("time video",frame);
      waitKey(delay);
    }
  return 0;
}
