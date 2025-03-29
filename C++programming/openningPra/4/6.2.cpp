#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findEarliestTakeoff(int n, int s, const vector<pair<int, int>>& landingTimes) {
    // 将着陆时间转换为分钟
    vector<int> minutes(n);
    for (int i = 0; i < n; ++i) {
        minutes[i] = landingTimes[i].first * 60 + landingTimes[i].second;
    }

    // 检查从当前时刻到第一个着陆航班之间的时间
    if (minutes[0] >= s + 1) {
        return {0, 0}; // 可以在0时0分起飞
    }

    // 检查两个连续着陆航班之间的时间差
    for (int i = 1; i < n; ++i) {
        if (minutes[i] - minutes[i - 1] >= s + 1) {
            // 找到最早可以插入起飞的时间
            int takeoffTime = minutes[i - 1] + s + 1;
            return {takeoffTime / 60, takeoffTime % 60};
        }
    }

    // 如果没有足够的间隔，计算最后一个着陆航班结束后s+1分钟的时间
    int lastLanding = minutes[n - 1] + 1; // 最后一个着陆航班结束时间
    int takeoffTime = lastLanding + s + 1;
    return {takeoffTime / 60, takeoffTime % 60};
}

int main() {
    int n, s;
    cin >> n >> s;
    vector<pair<int, int>> landingTimes(n);

    for (int i = 0; i < n; ++i) {
        int h, m;
        cin >> h >> m;
        landingTimes[i] = {h, m};
    }

    // 找到最早可以插入起飞的时间
    auto [h, m] = findEarliestTakeoff(n, s, landingTimes);

    // 输出结果
    cout << h << " " << m << endl;

    return 0;
}
