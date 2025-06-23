#include <iostream>
#include <vector>
using namespace std;

//并查集
class UnionFind {
public:
  vector<int> parent;
  vector<int> rank;
  int size;
    UnionFind(int n){
      size=n;
      parent.resize(n+1);
      rank.resize(n+1,1);
      for(int i=0;i<=n;i++){
        parent[i]=i;
      }
    }

    int find(int x){
        if(parent[x]==x){
          return x;
        }
        return parent[x]=find(parent[x]);
    }

    void unionSet(int x,int y){
      int rootX=find(x);
      int rootY=find(y);
      if(rootX!=rootY){
        size--;
        if(rank[rootX]<rank[rootY]){
          rank[rootY]+=rank[rootX];
          parent[rootX]=rootY;
        }
        else {
          rank[rootX]+=rank[rootY];
          parent[rootY]=rootX;
        }
      }
    }
};

int main(){
  while(true){
    int N,M;
    cin>>N>>M;
    if(N==0 && M==0) {break;}
    UnionFind uf(N);
    for(int i=0;i<M;i++){
      int x,y;
      cin>>x>>y;
      uf.unionSet(x,y);
    }
    if(uf.size==1){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
  return 0;
}