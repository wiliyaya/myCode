#include <iostream>

using namespace std;

long getSumOfDiv(long n){
  if(n<=1) return 0;
  long sum=1;

  //从1到n的平方根遍历
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      //说明i是n的一个因子
      sum+=i;
      if(i*i!=n){ //前面已经加上了1，就不用再判断一次
        sum+=n/i;
      }
    }
  }

  return sum;
}

int main(){
  long A,B;
  while(cin>>A>>B){
    long sumA=getSumOfDiv(A);
    long sumB=getSumOfDiv(B);
    if(sumA==B && sumB==A){
      cout<<"YES"<<endl;
    } 
    else {
      cout<<"NO"<<endl;
    }
  }
  return 0;

}


