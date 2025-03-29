#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 求小于入轨中第一个车厢编号的最大队尾元素所在队列编号
int MaxTailQueue(int temp, vector<queue<int>> &buffer_Q)
{
  int resultNum = -1, index = -1;
  for (size_t i = 0; i < buffer_Q.size(); i++)
  {
    if (!buffer_Q[i].empty() && temp > buffer_Q[i].back()) // 添加非空检查
    {
      if (buffer_Q[i].back() > index)
      {
        index = buffer_Q[i].back();
        resultNum = i;
      }
    }
  }
  return resultNum;
}

// 返回第一个空队列的索引，没有则返回-1
int findEmptyQueue(vector<queue<int>> &buffer_Q)
{
  for (size_t i = 0; i < buffer_Q.size(); i++)
  {
    if (buffer_Q[i].empty())
      return i;
  }
  return -1;
}

// 统一处理出队操作
void processedExits(vector<queue<int>> &buffer_Q, queue<int> &q, int &nowOut)
{
  bool processed;
  do
  {
    processed = false;
    // 直接处理入轨队头
    // 第一种情况
    if (!q.empty() && q.front() == nowOut)
    {
      q.pop();
      nowOut++;
      processed = true;
    }
    // 处理缓冲队列队头（第二种情况）
    for (auto &bq : buffer_Q)
    {
      while (!bq.empty() && bq.front() == nowOut)
      {
        bq.pop();
        nowOut++;
        processed = true;
      }
    }
  } while (processed);
}

int QueueNumber()
{
  // 队列初始化
  queue<int> q;
  int n = 0; // carNum = 0;
  while (cin >> n)
  {
    q.push(n);
  }
  vector<queue<int>> buffer_Q; // 用vector数组来存储所用队列数
  int nowOut = 1;

  bool progress;

  // int queueNumber = 0;
  while (!q.empty() || !buffer_Q.empty())
  {
    progress = false;
    int preNowOut = nowOut;

    // 优先处理所有可能的出队操作
    processedExits(buffer_Q, q, nowOut);
    if (nowOut > preNowOut)
    {
      progress = true;
    }
    if (!q.empty())
    {
      int temp = q.front();
      q.pop();

      // 寻找合适的缓冲队列
      int target = MaxTailQueue(temp, buffer_Q);
      if (target == -1)
      {
        int emptyIdx = findEmptyQueue(buffer_Q);
        // 判断已使用的队列中是否有空队列
        if (emptyIdx != -1)
        {
          buffer_Q[emptyIdx].push(temp);
        }
        else
        {
          buffer_Q.emplace_back();
          buffer_Q.back().push(temp);
        }
      }
      else
      {
        buffer_Q[target].push(temp);
      }
      progress=true;
    }
    // else
    // {
    //   processedExits(buffer_Q, q, nowOut);
    // }

    // 无进展且缓冲队列非空时退出（死锁保护）
    if(!progress&&buffer_Q.empty()) break;
  }

  return buffer_Q.size();
}

int main()
{
  int num = QueueNumber();
  cout << num;
  return 0;
}