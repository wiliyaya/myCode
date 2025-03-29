#include <iostream>
using namespace std;
int getCandy(int, int);
int main()
{
    int k, r;
    cin >> k >> r;
    //cout<<k<<' '<<r<<endl;
    int result = getCandy(k, r);
    cout << result << endl;
    return 0;
}
int getCandy(int k, int r)
{
    int g=k%10;
    if(g==0){
        return 1;
    }
    else {
        for(int i=1;i<10;i++){
            int temp=g*i%10;
            if(temp==r){
                return i;
            }
        }
    }
}