#include <iostream>
#include <vector>

using namespace std;


int n, m, ans = 0;
vector<int> a; // 是否有猫
vector<vector<int>> adj;
vector<int> visited;

void DFS(int u,int parent,int cat_cnt){ //u是当前节点，parent是父节点，cat_cnt是猫的数量
  //先对猫的数量进行条件判断
  if(a[u]) cat_cnt++;
  else cat_cnt=0;
  if(cat_cnt>m) return;

  visited[u]=1; // DFS的常规操作：访问已标记

  // 判断是否是叶子节点
  // 叶子节点的定义：邻接表中唯一一条边连的是父节点
  bool isLeaf=true;
  for(int v:adj[u]){
    if(v==parent) continue;
    isLeaf=false;
    DFS(v,u,cat_cnt);  //如果不是叶节点，继续DFS
  }
  if(isLeaf && u!=1) ans++;  
}



int main(){

  // int n,m;
  cin>>n>>m;
  // vector<int> a(n+1);
  // vector<vector<int>> adj(n+1);// 邻接表
  // vector<int> visited(n+1,0);// 访问标记

  a.resize(n + 1);
  adj.resize(n + 1);
  visited.resize(n + 1, 0);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  
  // 构建邻接表
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  DFS(1,0,0); // 从节点1开始DFS，父节点为0，猫的数量为0
  cout<<ans<<endl; // 输出结果

}



