#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int>number(4);
    for(int i=0;i<4;i++){
        cin>>number[i];
    }
    sort(number.begin(),number.end(),[](int a,int b){return a>b;});
    for(int num:number){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}