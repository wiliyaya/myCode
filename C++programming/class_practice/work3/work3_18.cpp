#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int>number(4);
    for(int i=0;i<4;i++){
        cin>>number[i];
    }
    sort(number.begin(),number.end());
    for(int I=2;I>-1;I--){
    cout<<number[3]-number[I]<<' ';
    }
    return 0;
}