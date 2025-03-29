#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
/*列车车厢重排全局变量*/
queue<int>* trackQueue;//缓冲轨道数组
queue<int> outputTrackQueue;//输出数组
int numberOfCarsQueue;//需要重排的列车数目
int numberOfTracksQueue;//缓冲轨道数目
int smallestCarQueue;//在缓冲轨道中编号最小的车厢
int itsTrackQueue;//停靠着最小编号车厢的缓冲轨道

/*列车车厢重排问题*/
/*将编号最小的车厢从缓冲轨道移到出轨道*/
void outputFromHoldingTrackQueue()
{
    //从队列itsTrack中删除编号最小的车厢
    outputTrackQueue.push(smallestCarQueue);
    trackQueue[itsTrackQueue].pop();
    // cout << "Move car " << smallestCarQueue << " from holding track " << itsTrackQueue << " to output track" << endl;
    //检查所有的队头，寻找编号最小的车厢和它所属的队itsTrackQueue
    smallestCarQueue = numberOfCarsQueue + 2;
    for (int i = 1; i <= numberOfTracksQueue; i++)
    {
        if (!trackQueue[i].empty() && (trackQueue[i].front() < smallestCarQueue))
        {
            smallestCarQueue = trackQueue[i].front();
            itsTrackQueue = i;
        }
    }
}
/*将车厢c移到一个缓冲轨道。返回false,当且仅当没有可用的缓冲轨道*/
/*此处使用了单调队列：从队头元素到队尾元素是从小到大的顺序*/
bool putInHoldingTrackQueue(int c)
{
    //为车厢c寻找最适合的缓冲轨道
    //初始化
    int bestTrack = 0;//目前没有适合的缓冲轨道
    int bestTop = 0;//取bestTrack为0，便于比较
    //扫描缓冲轨道
    for (int i = 1; i <= numberOfTracksQueue; i++)
    {
        //缓冲轨道i不为空
        if (!trackQueue[i].empty())
        {
            if (c > trackQueue[i].back() && trackQueue[i].back() > bestTop)
            {//缓冲轨道i的队尾具有编号更大的车厢
                bestTop = trackQueue[i].back();
                bestTrack = i;
            }
        }
        else//缓冲轨道i为空
            if (bestTrack == 0) bestTrack = i;
    }
    if (bestTrack == 0) return false;//没有可用的缓冲轨道
    //把车厢c移动到轨道bestTrack
    trackQueue[bestTrack].push(c);
    // cout << "Move car " << c << " from input track to holding track " << bestTrack << endl;
    //如果需要，更新smallestCar和itsTrack
    if (c < smallestCarQueue)
    {
        smallestCarQueue = c;
        itsTrackQueue = bestTrack;
    }
    return true;
}
/*从初始顺序开始重排车厢；如果重排成功，返回true,否则返回false*/
bool railRoadQueue(vector<int>& inputOrder, int& theNumberOfCars, int& theNumberOfTracks)
{
    numberOfCarsQueue = theNumberOfCars;
    numberOfTracksQueue = theNumberOfTracks;
    /*创建用于缓冲轨道的队列*/
    trackQueue = new queue<int>[numberOfTracksQueue + 1];
    smallestCarQueue = numberOfCarsQueue + 1;//缓冲轨道中无车厢

    int nextCarToOutput = 1;//当前需要被输出轨道的车厢编号
    //重排车厢
    for (int i = 0; i < numberOfCarsQueue; i++)
    {
        if (inputOrder[i] == nextCarToOutput)
        {
            /*将车厢inputOrder[i]直接移到出轨道*/
            // cout << "Move car " << inputOrder[i] << " from input track to output track" << endl;
            outputTrackQueue.push(inputOrder[i]);
            nextCarToOutput++;
            /*从缓冲轨道移到出轨道*/
            while (smallestCarQueue == nextCarToOutput)
            {
                outputFromHoldingTrackQueue();
                nextCarToOutput++;
            }
        }
        else
        {
            if (!putInHoldingTrackQueue(inputOrder[i]))
                return false;
        }
    }
    return true;
}


int main()
{
    //列车车厢重排问题
    // cout << "railRoadQueue()*****************" << endl;
    // int inputOrder[9] = { 5, 8, 1, 7, 4, 2, 9, 6, 3 };
    // if(railRoadQueue(inputOrder, 9, 3)){
    //     for(int i = 0; i < outputTrackQueue.size(); i++){
    //         cout << outputTrackQueue.front() << " ";
    //         outputTrackQueue.pop();
    //     }
    //     cout << endl;
    // }
    vector<int> inputOrder;
    int n=0;
    while(cin>>n){
      // cout<<n<<' ';
      inputOrder.push_back(n);
    }
    reverse(inputOrder.begin(),inputOrder.end());
    // cout<<endl;
    int carnumber=inputOrder.size();
    int bufferT=0;
    while(!railRoadQueue(inputOrder,carnumber,bufferT)){
      bufferT++;
    }
    cout<<bufferT+1;

    return 0;
}


