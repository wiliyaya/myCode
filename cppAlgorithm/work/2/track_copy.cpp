#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 列车车厢重排全局变量
queue<int>* trackQueue;//缓冲轨道数组
queue<int> outputTrackQueue;//输出数组
int numberOfCarsQueue;//需要重排的列车数目
int numberOfTracksQueue;//缓冲轨道数目
int smalleastCarQueue;//在缓冲轨道中编号最小的车厢
int itsTrackQueue;//停靠着最小编号车厢的缓冲轨道

//将编号最小的车厢从缓冲轨道移到出轨道
void outputFromHoldingTrackQueue(){
  //从队列itsTrack中删除编号最小的车厢
  outputTrackQueue
}