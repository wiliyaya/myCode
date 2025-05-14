#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 边的结构体，表示一条水渠
struct Edge {
    int u, v, w; // u和v是麦田编号，w是修建水渠的费用
    // 重载小于号，方便排序
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<int> fa; // 并查集数组，fa[x]表示x的父节点

// 并查集查找操作，带路径压缩
int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

// 并查集合并操作，返回是否合并成功
bool unite(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return false; // 已经在同一个集合，不用合并
    fa[fx] = fy; // 合并集合
    return true;
}

int main() {
    int n, m;
    cin >> n >> m; // n个麦田，m条可建水渠
    vector<Edge> edges(m);
    // 读入所有水渠信息
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    // 按费用从小到大排序
    sort(edges.begin(), edges.end());
    // 初始化并查集
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++) fa[i] = i;

    int mst_cost = 0, cnt = 0; // mst_cost为总费用，cnt为已选边数
    // 遍历所有水渠，按费用从小到大尝试加入
    for (const auto& e : edges) {
        if (unite(e.u, e.v)) { // 如果这条边连接了两个不同集合
            mst_cost += e.w;   // 累加费用
            cnt++;             // 已选边数+1
            if (cnt == n - 1) break; // 生成树边数达到n-1时停止
        }
    }
    cout << mst_cost << endl; // 输出最小总费用
    return 0;
}