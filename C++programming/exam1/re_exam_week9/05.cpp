#include <iostream>
#include <vector>
using namespace std;
long long number(int, vector<long long>);
int main()
{
    int n;
    cin >> n;
    vector<long long> num;
    cout << number(n,num) << endl;
    return 0;
}
long long number(int n,vector<long long> &num)
{
    //long long num[n];
    if (n == 1 || n == 2)
    {
        return n;
    }
    else
    {
        //int num = new int[n];
        num[n]=number(n-1,num)+number(n-2,num);
        //num[n-1]=number(n-1);
        //num[n-2]=number(n-2);
        //num[n]=num[n-1]+num[n-2];
    }
    return num[n];
}