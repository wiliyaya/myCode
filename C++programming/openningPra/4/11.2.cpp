#include <iostream>
using namespace std;

int main() {
    int n, L, a;
    cin >> n >> L >> a;
    
    int last_time = 0; // 上一个客人服务结束的时间
    int rest_count = 0; // 小希可以放松的次数

    for (int i = 0; i < n; i++) {
        int t, l;
        cin >> t >> l;
        // 计算当前客人到来之前和上一个客人服务结束后的空闲时间
        if (t > last_time) {
            rest_count += (t - last_time) / a;
        }
        // 更新上一个客人服务结束的时间
        last_time = t + l;
    }
    
    // 计算最后一个客人服务结束后到工作日结束的空闲时间
    if (L > last_time) {
        rest_count += (L - last_time) / a;
    }

    cout << rest_count << endl;

    return 0;
}
