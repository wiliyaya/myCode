#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *grade = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> grade[i];
    }
    int arr[101];
    for (int i = 0; i < 101; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (grade[i] == j)
            {
                arr[j]++;
                break;
            }
        }
    }
    int j=101;
    while(j--){
        if(arr[j]!=0){
            cout<<j<<' '<<arr[j]<<endl;
        }
    }
    delete[] grade;
    return 0;
}