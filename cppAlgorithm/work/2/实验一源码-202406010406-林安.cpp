#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include <algorithm>
using namespace std;

int MaxTailQueue(int temp, vector<queue<int>>& buffer_Q) {
    int max_tail = -1, result = -1;
    for (size_t i = 0; i < buffer_Q.size(); ++i) {
        if (buffer_Q[i].empty()) {
            // 空轨道队尾视为极小值，优先选择第一个空轨道
            if (max_tail == -1) {
                result = i;
                max_tail = 0; // 标记已找到空轨道
            }
        } else if (buffer_Q[i].back() < temp) {
            if (buffer_Q[i].back() > max_tail) {
                max_tail = buffer_Q[i].back();
                result = i;
            }
        }
    }
    return result;
}

bool processExits(vector<queue<int>>& buffer_Q, stack<int>& q, int& nowOut) {
    bool processed;
    do {
        processed = false;
        // 处理入轨队头
        if (!q.empty() && q.top() == nowOut) {
            q.pop();
            nowOut++;
            processed = true;
        }
        // 处理所有缓冲队列的队头
        for (auto& bq : buffer_Q) {
            while (!bq.empty() && bq.front() == nowOut) {
                bq.pop();
                nowOut++;
                processed = true;
            }
        }
    } while (processed);

    return processed;
}

int QueueNumber() {
    stack<int> q;
    int num;
    while (cin >> num) q.push(num);

    vector<queue<int>> buffer_Q;
    int nowOut = 1;

    while (!q.empty() || !buffer_Q.empty()) {
        bool changed=processExits(buffer_Q, q, nowOut);

        if (q.empty()) 
        {
            if(!changed)break;
            continue;
        }

        int temp = q.top();
        q.pop();

        int target = MaxTailQueue(temp, buffer_Q);
        if (target != -1) {
            buffer_Q[target].push(temp);
        } else {
            // 没有合适轨道且无空轨道，必须创建新轨道
            buffer_Q.emplace_back();
            buffer_Q.back().push(temp);
        }
    }
    //加1是因为除了buffer_Q还要有一条轨道让车出轨
    return buffer_Q.size()+1;
}

int main() {
    cout << QueueNumber();
    return 0;
}