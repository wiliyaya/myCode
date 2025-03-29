#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 求小于入轨中第一个车厢编号的最大队尾元素所在队列编号
int MaxTailQueue(int temp, vector<queue<int>>& buffer_Q)
{
  int resultNum = -1, index = -1;
  for (size_t i = 0; i < buffer_Q.size(); i++)
  {
    if (!buffer_Q[i].empty() && temp > buffer_Q[i].back()) // 添加非空检查
    {
      // resultNum=(index>buffer_Q[i].back() ? resultNum: i);
      // index=(index>buffer_Q[i].back() ? index:buffer_Q[i].back());
      if (buffer_Q[i].back() > index)
      {
        index = buffer_Q[i].back();
        resultNum = i;
      }
    }
  }
  return resultNum;
}

// 判断已使用的队列中是否有空队列
// int isempty(vector<queue<int>>& buffer_Q)
// {
//   for (size_t i = 0; i < buffer_Q.size(); i++)
//   {
//     if (buffer_Q[i].empty())
//     {
//       return i;
//     }
//   }
//   return -1;
// }

//返回第一个空队列的索引，没有则返回-1
int findEmptyQueue(vector<queue<int>>& buffer_Q){
  for(size_t i=0;i<buffer_Q.size();i++){
    if(buffer_Q[i].empty()) return i;
  }
  return -1;
}

// 统一处理出队操作
void processedExits(vector<queue<int>>& buffer_Q, queue<int> &q, int& nowOut)
{
  bool processed;
  do
  {
    processed = false;
    // 直接处理入轨队头
    //第一种情况
    if(!q.empty()&&q.front()==nowOut){
      q.pop();
      nowOut++;
      processed=true;
    }
    //处理缓冲队列队头（第二种情况）
    for(auto& bq:buffer_Q){
      if(!bq.empty()&&bq.front()==nowOut){
        bq.pop();
        nowOut++;
        processed=true;
        //break;//需要重新扫描
      }
    }
  } while (processed);
}

int QueueNumber()
{
  // 队列初始化
  queue<int> q;
  int n = 0;// carNum = 0;
  while (cin >> n)
  {
    q.push(n);
  }
  vector<queue<int>> buffer_Q; // 用vector数组来存储所用队列数
  int nowOut = 1;
  // int queueNumber = 0;
  while (!q.empty() || !buffer_Q.empty())
  {
    //优先处理所有可能的出队操作
    processedExits(buffer_Q,q,nowOut);
    // if(q.empty()){
    //   continue;
    // }当入轨队列空但缓冲队列仍有元素时，这个continue会导致：
// 无法处理缓冲队列中可出队的元素
// nowOut无法继续增长
// 缓冲队列永远无法清空
    
    if(!q.empty()){
    int temp = q.front();
    q.pop();
    // // 情况一
    // if (nowOut == temp)
    // {
    //   q.pop();
    //   nowOut++;
    //   continue;
    // }

    // // 情况二
    // // if(!buffer_Q.empty()){
    // //   for(size_t i=0;i<buffer_Q.size();i++){
    // //     if(nowOut==buffer_Q[i].front()){
    // //       buffer_Q[i].pop();
    // //       nowOut++;
    // //       break;
    // //     }
    // //   }
    // // }这段代码处理得不够彻底，仅处理第一个匹配的队列，但是缓冲队列中可能还有适配的元素
    // // 以下是根据deepseek的建议修改后的代码
    // bool processed;
    // do
    // {
    //   processed = false;
    //   for (size_t i = 0; i < buffer_Q.size(); i++)
    //   {
    //     if (!buffer_Q[i].empty() && buffer_Q[i].front == nowOut)
    //     {
    //       buffer_Q[i].pop();
    //       nowOut++;
    //       processed = true;
    //       // 处理完一个队列后，需要重新遍历，因为可能有其他队列的对头也等于新的nowOut
    //       break;
    //       // 退出当前循环，重新开始遍历
    //     }
    //   }
    // } while (processed); // 这样，每当处理一个队列后，`nowOut`会递增，然后继续检查所有队列，直到没有可处理的队头。
    // 情况三
    // if (buffer_Q.empty())
    // {
    //   queue<int> Q;
    //   Q.push(temp);
    //   buffer_Q.push_back(Q);
    //   q.pop();
    //   queueNumber++;
    //   continue;
    // }

    //寻找合适的缓冲队列
    int target = MaxTailQueue(temp, buffer_Q);
    if (target == -1)
    {
      int emptyIdx=findEmptyQueue(buffer_Q);
      // 判断已使用的队列中是否有空队列
      if (emptyIdx != -1)
      {
        buffer_Q[emptyIdx].push(temp);
      }
      else
      {
        buffer_Q.emplace_back();
        buffer_Q.back().push(temp);
        // queue<int> Q;
        // Q.push(temp);
        // buffer_Q.push_back(Q);
        // queueNumber++;
      }
    }
    else
    {
      buffer_Q[target].push(temp);
    }
  }
  else {
    processedExits(buffer_Q,q,nowOut);
  }
  }
  return buffer_Q.size();
}

int main()
{
  int num = QueueNumber();
  cout << num;
  return 0;
}