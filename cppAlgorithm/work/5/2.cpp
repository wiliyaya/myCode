#include <iostream>
#include <vector>
#include <queue>
#include <set>


using namespace std;

int main() {
  int n;
  cin >> n; // 输入节点数
  vector<vector<int>> adj(n+1); // 邻接表
  vector<int> visited(n+1,0); // 访问标记
  for(int i=0;i<n-1;i++){
    int x,y;
    cin >> x >> y; // 输入边
    adj[x].push_back(y); // 添加边
    adj[y].push_back(x); // 添加边
  }

  vector<int> bfs_seq(n); // BFS队列
  for(int i=0;i<n;i++){
    cin>> bfs_seq[i]; // 输入BFS序列
    // int x;
    // cin>>x;
    // bfs_seq.push(x);
  }

  if(bfs_seq[0]!=1){
    cout<<"No"<<endl;
    return 0;
  }

  queue<int> q; // BFS队列
  visited[1]=1; // 标记起点已访问
  q.push(1); // 将起点加入队列
  int pos=1; //指向bfs_seq的下一个待匹配的位置

  while(!q.empty()){
    int t=q.front(); // 取出队头元素
    q.pop(); // 弹出队头元素

    set<int> children; // 存储当前节点的子节点
    for(int v:adj[t]){
      if(!visited[v]){ // 如果子节点未访问
        children.insert(v); // 将子节点加入集合
      }
    }

    int cnt=children.size(); // 当前节点的子节点数
    //检查bfs_seq的下cnt个元素是否正好是children集合
    set<int> next_nodes;
    for(int i=pos;i< pos+cnt;i++){
      if(i>=n){
        cout<<"No"<<endl;
        return 0;
      }
      next_nodes.insert(bfs_seq[i]); // 将下cnt个元素加入集合
    }
    if(next_nodes!=children){ // 如果集合不相等，输出No
      cout<<"No"<<endl;
      return 0;
    }
    //标记并入列
    for(int i=pos;i<pos+cnt;i++){
      visited[bfs_seq[i]]=1; // 标记已访问
      q.push(bfs_seq[i]); // 将子节点加入队列
    }
    pos+=cnt; // 更新指向bfs_seq的下一个待匹配的位置

  }
  cout<<"Yes"<<endl; // 如果匹配成功，输出Yes
  return 0;
}