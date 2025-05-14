//满足删除的条件：1.自己的Ci等于1    2.以其子节点的Ci都为1

#include <iostream>
#include <vector>

using namespace std;

//找出要删除的节点
void DeleteNode(int n,vector<int >& c,vector<vector<int>>& children,vector<int>& p,vector<int>& ans){
  // 1. 按照从小到大的顺序，找到所有的Ci=1的节点
  for(int i=1;i<n+1;i++){
    if(c[i]==1){
      // 2. 判断其子节点是否都为1
      bool isAllChildren1=true;
      for(int j=0;j<children[i].size();j++){
        if(c[children[i][j]]!=1){
          isAllChildren1=false; // 如果有一个子节点不为1，跳出循环
          break; // 如果有一个子节点不为1，跳出循环
        }
      }

      if(isAllChildren1){
        // 3. 如果是，删除该节点
        ans.push_back(i); // 将该节点加入到要删除的节点中
        // 4. 让其父节点收纳它的children
        for(int j=0;j<children[i].size();j++){
          p[children[i][j]]=p[i]; // 将子节点的父节点改为当前节点的父节点
        }
        // 5. 将当前节点的父节点的children中删除当前节点
        int parent=p[i];
        for(int j=0;j<children[parent].size();j++){
          if(children[parent][j]==i){
            children[parent].erase(children[parent].begin()+j); // 删除当前节点
            break; // 删除后跳出循环
          }
        }
        // 6. 删除当前节点的children  (这是我没想到的)
        children[i].clear(); // 删除当前节点的children

      }
    }
  }
}

int main(){
  int n;
  cin>>n;
  vector<int> p(n+1); // 父节点
  vector<int> c(n+1); 
  vector<vector<int>> children(n+1); // 邻接表
  for(int i=1;i<n+1;i++){
    cin>>p[i]>>c[i];
    if(p[i]!=-1){
      children[p[i]].push_back(i); 
    }
  }

  vector<int> ans; // 存放要删除的节点
  DeleteNode(n,c,children,p,ans); // 找出要删除的节点

  if(ans.empty()){
    cout<<-1<<endl; // 如果没有要删除的节点，输出-1
    return 0;
  }

  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" "; // 输出要删除的节点
  }
  cout<<endl; // 换行

  return 0;
}
