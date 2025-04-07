#include <iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

//树节点结构
struct HuffmanNode {
  int weight;
  int depth;//路径长度（根节点到该叶子的边数）
  bool is_leaf;
  HuffmanNode* left;
  HuffmanNode* right;

  //构造叶子节点
  HuffmanNode(int w):weight(w),depth(0),is_leaf(true),left(nullptr),right(nullptr) {}

  //构造内部节点
  HuffmanNode(HuffmanNode* l,HuffmanNode* r):weight(l->weight + r->weight),depth(0),is_leaf(false),left(l),right(r){}
};

//比较函数对象（用于优先队列）
struct cmp{
  bool operator()(const HuffmanNode* a,const HuffmanNode* b){
    return a->weight > b->weight;//最小堆
  }
};

//计算所有叶子的WPL
int calWPL(HuffmanNode* root){
  if(!root){//root为空的话值为nullptr， !nullptr就代表出现这种情况
    return 0;
  }
  if(root->is_leaf){
    return root->weight*root->depth;
  }
  return calWPL(root->left) + calWPL(root->right);
}

int buildHuffman_getWPL(const vector<int>& weights){
  if(weights.empty())return 0;

  //创建最小堆，初始为所有叶子节点
  priority_queue<HuffmanNode*,vector<HuffmanNode*>,cmp> min_heap;

  //初始化所有节点，初始化深度为0
  for(int w :weights){
    HuffmanNode* hn=new HuffmanNode(w);
    min_heap.push(hn);
  }

  //合并节点直到只剩根节点
  while(min_heap.size()>1){
    HuffmanNode* left=min_heap.top();
    min_heap.pop();
    HuffmanNode* right=min_heap.top();
    min_heap.pop();

    //创建内部节点，并设置子节点
    HuffmanNode* parent=new HuffmanNode(left,right);
    min_heap.push(parent);
  }

  //获取根节点
  HuffmanNode* root=min_heap.top();

  //遍历树计算各叶子的depth
  queue<HuffmanNode*> q;
  if(root){
    root->depth=0;//根节点的深度为0
    q.push(root);
  }

  while(!q.empty()){
    HuffmanNode* node=q.front();
    q.pop();
    if(node->left){
      node->left->depth=node->depth+1;
      q.push(node->left);
    }
    if(node->right){
      node->right->depth=node->depth+1;
      q.push(node->right);
    }
  }

  //计算WPL
  return calWPL(root);

}

int main(){
  while(true){
    int n;cin>>n;
    if(n==0){
      break;
    }
    vector<int> weights;
    for(int i=0;i<n;i++){
      int temp;
      cin>>temp;
      weights.push_back(temp);
    }

    cout<<buildHuffman_getWPL(weights)<<endl;

  }
  return 0;
}

