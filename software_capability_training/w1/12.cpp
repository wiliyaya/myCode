// 三个操作
// alloc n :分配n个连续字节的空闲块，重复时选最接近开始的；emmmm然后什么意思没看懂
// erase x :标记x为空闲;......
// defragment :合并相邻的空闲块,使他们更接近开头

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Block
{
  int x=0;
  bool isfree=true;
  int start=0;
  int size=0;
};

int findSuitableBlock(int n, vector<bool> &marked, vector<Block> &block, int m,int &X)
{
  bool canAllocate = true;

  for (int i = 0; i <= m-n; i++)
  {
    canAllocate = true;
   
      for (int j = i;  j<m &&j - i < n; j++)
      {
        if (marked[j]){          
          canAllocate=false;
          break; // 如果遇到已分配的块，跳出循环
        }
      }
        if(canAllocate){//代表成功找到一个空闲位置
          Block newblock;
          newblock.start=i;
          newblock.size=n;
          newblock.isfree=false; // 分配的块标记为已分配
          newblock.x = ++X; // 分配块的正整数标识符
          block.push_back(newblock);
          for(int k=i;k<i+n;k++){
            marked[k]=true; // 标记为已分配
          }
          return X;
        }
    
  }
  return 0;
}

void eraseBlock(int erase_x,vector<bool>& marked,vector<Block>& block){
  if(erase_x<=0 || erase_x>block.size() || block[erase_x-1].isfree){
    cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
    return ;
  }
  else {
    block[erase_x-1].isfree=true; // 将块标记为空闲
    for(int i=block[erase_x-1].start;i<block[erase_x-1].start+block[erase_x-1].size;i++){
      marked[i]=false;
    }
  }

}

void defragment(vector<bool>& marked,vector<Block>& block){

  // 先按起始地址排序（确保处理顺序正确）
    sort(block.begin(), block.end(), [](const Block& a, const Block& b) {
        return a.start < b.start;
    });

  int cur=0;
  for(auto& b:block){
    if(!b.isfree){
      //如果需要移动
      if(b.start!=cur){
        b.start=cur;
      }
      cur+=b.size;
    }
  }
  //更新marked的值
  for(int i=0;i<marked.size();i++){
    if(i<cur) marked[i]=true;
    else marked[i]=false;
  }

}
// void defragment(vector<bool>& marked, vector<Block>& block) {
//     // 先按起始地址排序（确保处理顺序正确）
//     sort(block.begin(), block.end(), [](const Block& a, const Block& b) {
//         return a.start < b.start;
//     });

//     int new_pos = 0;
//     for (auto& b : block) {
//         if (!b.isfree) {
//             // 移动块到新位置
//             if (b.start != new_pos) {
//                 // 清除原标记
//                 for (int i = b.start; i < b.start + b.size; i++) {
//                     marked[i] = false;
//                 }
//                 // 更新块位置
//                 b.start = new_pos;
//                 // 设置新标记
//                 for (int i = new_pos; i < new_pos + b.size; i++) {
//                     marked[i] = true;
//                 }
//             }
//             new_pos += b.size;
//         }
//     }
//     // 剩余空间全部标记为空闲
//     for (int i = new_pos; i < marked.size(); i++) {
//         marked[i] = false;
//     }
// }

int main()
{
  int t, m;
  cin >> t >> m;
  // cout << t << ' ' << m << endl;
  vector<bool> marked(m, false); // 标记数组，false表示空闲，true表示已分配
  vector<Block> block;
  int X = 0; // 分配块的正整数标识符x
  while (t--)
  {
    string order;
    cin >> order;

    if (order == "alloc")
    {
      int n;
      cin >> n;

      // cout << "alloc " <<' '<< n <<endl;

      int alloc_x=findSuitableBlock(n,marked,block,m,X);
      if(alloc_x){
        cout<<alloc_x<<endl; // 分配成功，输出分配块的标识符
      }
      else {
        cout<<"NULL"<<endl;
      }

    }
    else if (order == "erase")
    {
      int erase_x;
      cin>>erase_x;

      // cout << "erase " <<' '<< erase_x << endl;

      eraseBlock(erase_x,marked,block);

    }
    else if (order == "defragment")
    {
      // cout << "defragment" << endl;
      defragment(marked,block);
    }
  }

  return 0;
}
