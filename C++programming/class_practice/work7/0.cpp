#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int> arr={3,4,6,2,8};
    sort(arr.begin(),arr.end());
    reverse(arr.begin()+2,arr.end());
    for(int a:arr){
        cout<<a<<' ';
    }
    return 0;
}