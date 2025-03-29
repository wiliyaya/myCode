#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *grade = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> grade[i];
    }
    vector<int> num(101, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (grade[i]==j){
                num[j]++;
                break;
            }
        }
    }
    //int j=101;
    for(int j=100;j>=0;j--) {
        if(num[j]!=0){
            cout<<j<<' '<<num[j]<<endl;
        }
    }
    delete[] grade;
    return 0;
}