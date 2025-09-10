#include <iostream>
#include <vector>
using namespace std;
//行列的和为偶数的时候为黑（1）
//找最大尺寸的话，从N开始递减，判断
/*int cur_size;
for(int i=0;i<N;i++){
  cur_size=N-i;
  for(int r=0;r<)  
}

*/

//复制
void Copy(){

}


int main(){
  //数据输入
  int N;cin>>N;
  vector<vector<char>> matrix(N,vector<char>(N));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>matrix[i][j];
    }
  }


  int cur_size=N;
  while(cur_size){
    int start_row,start_col;
    
  }
}

