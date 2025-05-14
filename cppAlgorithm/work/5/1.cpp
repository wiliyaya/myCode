#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
int dx[4] = {0, 0, 1, -1}; // 四个方向
int dy[4] = {1, -1, 0, 0};

// Dijkstra 算法，从 (sx, sy) 出发计算最短路
vector<vector<ll>> dijkstra(const vector<vector<ll>>& grid, int n, int m, ll w, int sx, int sy) {
    vector<vector<ll>> dist(n, vector<ll>(m, INF));
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;

    dist[sx][sy] = 0;
    pq.emplace(0, sx, sy);

    while (!pq.empty()) {
        // auto [cost, x, y] = pq.top(); pq.pop();
        ll cost = std::get<0>(pq.top());
        int x = std::get<1>(pq.top());
        int y = std::get<2>(pq.top());
        pq.pop();

        if (cost > dist[x][y]) continue;

        // 四个方向尝试
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 越界
            if (grid[nx][ny] == -1) continue; // 墙，不能走

            ll new_cost = cost + w;
            if (new_cost < dist[nx][ny]) {
                dist[nx][ny] = new_cost;
                pq.emplace(new_cost, nx, ny);
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    ll w;
    cin >> n >> m >> w;

    vector<vector<ll>> grid(n, vector<ll>(m));

    // 输入地图
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    // 1. 从起点 (0,0) 出发的最短路
    vector<vector<ll>> dist_start = dijkstra(grid, n, m, w, 0, 0);

    // 2. 从终点 (n-1,m-1) 出发的最短路
    vector<vector<ll>> dist_end = dijkstra(grid, n, m, w, n - 1, m - 1);

    // 3. 枚举所有时空通道，找出从起点/终点到任意传送门的最小代价 + 本身通道代价
    ll min_to_portal = INF;
    ll min_from_portal = INF;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] > 0) {
                if (dist_start[i][j] != INF)
                    min_to_portal = min(min_to_portal, dist_start[i][j] + grid[i][j]);

                if (dist_end[i][j] != INF)
                    min_from_portal = min(min_from_portal, dist_end[i][j] + grid[i][j]);
            }

    // 4. 比较两种路径：
    //    ① 直接走过去
    //    ② 借助传送门（到达某传送门 + 传送 + 从另一个传送门走到终点）
    ll answer = dist_start[n - 1][m - 1];
    if (min_to_portal != INF && min_from_portal != INF)
        answer = min(answer, min_to_portal + min_from_portal);

    if (answer == INF)
        cout << -1 << endl;
    else
        cout << answer << endl;

    return 0;
}