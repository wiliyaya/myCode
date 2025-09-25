#include<iostream>
#include<vector>

using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  vector<int> b(n-1);
  cin>>a[0];
  int sum=0;
  int maxSum=0;
  int minSum=0;
  for(int i=1;i<n;i++){
    cin>>a[i];
    b[i-1]=(a[i]-a[i-1])>=0 ? (a[i]-a[i-1]) : -(a[i]-a[i-1]);
    sum+=b[i-1];
  }

  int temp=sum;
  maxSum=sum;
  minSum=sum;
  // //单独写第一个和最后一个
  // //第一个
  // //加k
  // sum-=b[0];
  // //addk
  // int addk=(a[0]+k-a[1])>0 ? (a[0]+k-a[1]) :-(a[0]+k-a[1]);
  // sum+=addk;
  // maxSum=max(maxSum,sum);
  // minSum=min(minSum,sum);
  // //恢复sum的值
  // sum=temp;
  // //减k
  // sum-=b[0];
  // int subk=(a[0]-k-a[1])>0 ? (a[0]-k-a[1]) :-(a[0]-k-a[1]);
  // sum+=subk;
  // maxSum=max(maxSum,sum);
  // minSum=min(minSum,sum);
  // //恢复sum的值
  // sum=temp;
  for(int i=0;i<n;i++){
    //加k
    if(i==0){
      sum-=b[0];
      int addk=(a[0]+k-a[1])>0 ? (a[0]+k-a[1]) :-(a[0]+k-a[1]);
      sum+=addk;
      maxSum=max(maxSum,sum);
      minSum=min(minSum,sum);
      //恢复sum的值
      sum=temp;
      //减k
      sum-=b[0];
      int subk=(a[0]-k-a[1])>0 ? (a[0]-k-a[1]) :-(a[0]-k-a[1]);
      sum+=subk;
      maxSum=max(maxSum,sum);
      minSum=min(minSum,sum);
      //恢复sum的值
      sum=temp;
      continue;
    }
    if(i==n-1){
      sum-=b[n-2];
      int addk=(a[n-1]+k-a[n-2])>0 ? (a[n-1]+k-a[n-2]) :-(a[n-1]+k-a[n-2]);
      sum+=addk;
      maxSum=max(maxSum,sum);
      minSum=min(minSum,sum);
      //恢复sum的值
      sum=temp;
      //减k
      sum-=b[n-2];
      int subk=(a[n-1]-k-a[n-2])>0 ? (a[n-1]-k-a[n-2]) :-(a[n-1]-k-a[n-2]);
      sum+=subk;
      maxSum=max(maxSum,sum);
      minSum=min(minSum,sum);
      //恢复sum的值
      sum=temp;
      continue;
    }
    sum-=b[i-1]+b[i];
    int addk1=(a[i]+k-a[i-1])>0 ? (a[i]+k-a[i-1]) :-(a[i]+k-a[i-1]);
    int addk2=(a[i]+k-a[i+1])>0 ? (a[i]+k-a[i+1]) :-(a[i]+k-a[i+1]);
    sum+=addk1+addk2;
    maxSum=max(maxSum,sum);
    minSum=min(minSum,sum);

    //恢复sum的值
    sum=temp;

    //减k
    sum-=b[i-1]+b[i];
    int subk1=(a[i]-k-a[i-1])>0 ? (a[i]-k-a[i-1]) :-(a[i]-k-a[i-1]);
    int subk2=(a[i]-k-a[i+1])>0 ? (a[i]-k-a[i+1]) :-(a[i]-k-a[i+1]);
    sum+=subk1+subk2;
    maxSum=max(maxSum,sum);
    minSum=min(minSum,sum);
    //恢复sum的值
    sum=temp;
  }
  cout<<maxSum<<' '<<minSum<<endl;
  return 0;
}