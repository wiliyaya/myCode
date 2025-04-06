#include <iostream>
#include<queue>
#include <vector>
using namespace std;

class Position{
public:
  int row;
  int col;
};

//识别图元
void Label(){
  int m=10;
  //初始化“围墙”
  //定义一个数组
  vector<vector<int>> pixel(m);
  for(int i=0;i<=m+1;i++){
    pixel[0][i]=pixel[m+1][i]=0;
    //底和顶
    pixel[i][0]=pixel[i][m+1]=0;
    //左和右
  }

  //初始化offset
  Position offset[4];
  offset[0].row = 0; offset[0].col=1;//右
  offset[1].row = 1; offset[1].col = 0;//下
  offset[2].row = 0; offset[2].col = -1;//左
  offset[3].row = -1; offset[3].col = 0;//上
  
  //一个像素的相邻像素个数
  int NumOfNbrs=4;
  queue<Position> Q;
  int id=1;//图元ID
  Position here,nbr;
  //扫描所有像素
  for(int r=1;r<=m;r++){//图像的第r行
    for(int c=1;c<=m;c++){//图像的第c列
      if(pixel[r][c]==1){ //新图元
        pixel[r][c]=++id; //赋予新的id值
        here.row=r;
        here.col=c;
        //顺着该点的周围循环遍历所有相邻的点
        do{
          for(int i=0;i<NumOfNbrs;i++){
            //检查当前像素的所有相邻像
            nbr.row=here.row+offset[i].row;
            nbr.col=here.col+offset[i].col;
            if(pixel[nbr.row][nbr.col]==1){
              pixel[nbr.row][nbr.row]=id;
              Q.push(nbr);  // 将相邻像素加入队列
            }
          }
          if(Q.empty()){break;} // 队列为空，退出循环
          Q.pop();// 从队列中取出下一个待处理的像素
          //就是要把here从Q中删除，类似图的广度优先搜索
        }while(true);

      }
    }
  }
}
