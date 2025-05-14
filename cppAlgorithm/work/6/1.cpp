// 有向图
// 邻接矩阵？
// 有无经过自环的点
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int u, vector<bool> &visited, vector<vector<int>> &adj)
{
  visited[u] = true;
  for (int v : adj[u])
  {
    if (visited[v] == false)
    {
      DFS(v, visited, adj);
    }
  }
}

vector<bool> Topo(int n, vector<vector<int>> &adj, vector<int> &in, vector<bool> &visited, vector<int> &dp)
{
  // top排序+DP
  for(int i = 1; i < n + 1; i++)
  {
    if(visited[i] == false)
    {
      for(int v: adj[i])
      {
        in[v]--;
      }
    }
  }
  queue<int> topo;
  for (int i = 1; i < n + 1; i++)
  {

    if (in[i] == 0 && visited[i])
    {
      topo.push(i);
    }
    dp[1] = 1; // 从1到1只有一条路径（路径长度为0）

    vector<bool> in_cycle(n + 1, false); // 记录是否有环
    int processed = 0;                   // 记录处理的点数
    while (!topo.empty())
    {
      int u = topo.front();
      topo.pop();
      processed++; // 在topo中的点都是入度为0的点
      for (int v : adj[u])
      {
        if (!visited[v])
        {
          continue;
        }
        dp[v] += dp[u]; // 更新路径数
        if (dp[v] > 2)
        {
          dp[v] = 2; // 只关心1/2/更多
        }
        in[v]--; // 入度减1
        if (in[v] == 0)
        {
          topo.push(v);
        }
      }
    }

    // 判断是否有环或是否可以通过有环的路径到达
    for (int i = 1; i <= n; i++)
    {
      if (visited[i] && in[i] > 0)
      {
        in_cycle[i] = true;
      }
    }
    return in_cycle;
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;                      // n个点，m条边
    vector<vector<int>> adj(n + 1);     // 邻接表
    vector<bool> visited(n + 1, false); // 记录是否可访问
    vector<int> in(n + 1, 0);           // 入度
    vector<int> dp(n + 1, 0);           // 路径数

    // 初始化邻接表，统计入度
    for (int i = 0; i < m; i++)
    {
      int a, b;
      cin>>a>>b;
      // cout << a << " " << b << endl;
      adj[a].push_back(b);
      in[b]++; // 入度加1
    }
    // 找出所有能到的点，并标记
    DFS(1, visited, adj);

    // 用top排序来判断是否有环
    vector<bool> in_cycle = Topo(n, adj, in, visited, dp);

    // 标记所有能从1到达 且经过环的点 (用BFS或DFS从环出发)
    queue<int> q_cycle;
    for (int i = 1; i <= n; i++)
    {
      if (in_cycle[i])
      {
        q_cycle.push(i);
      }
    }

    // BFS或DFS标记所有能从环出发到达的点
    // vector<bool> visited_cycle(n+1,false);
    // while(!q_cycle.empty()){
    //   int u=q_cycle.front();
    //   q_cycle.pop();
    //   visited_cycle[u]=true;
    //   for(int v:adj[u]){
    //     if(!visited_cycle[v]){
    //       q_cycle.push(v);
    //       visited_cycle[v]=true;
    //     }
    //   }
    // }

    // 输出结果
    for (int i = 1; i <= n; i++)
    {
      if (!visited[i])
      {
        cout << 0 << " ";
      }
      else if (in_cycle[i])
      {
        cout << -1 << " ";
      }
      else
        cout << dp[i] << " ";
    }
    cout << endl;
  }
}
