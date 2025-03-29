#include <iostream>
#include <vector>
using namespace std;
int solve(int n,vector<int> &saved){
    if(n==1||n==2){
        return n;
    }

    saved[n]=solve(n-1,saved)+solve(n-2,saved);
    return saved[n];
}
int main(){
    int n;
    cin>>n;
    vector<int> saved(n);
    int num=solve(n,saved);
    cout<<num;
    return 0;

}