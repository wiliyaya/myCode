#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    char arr[100];
    char t;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            count++;
        }
        else{
            cout<<arr[i-1]<<":"<<count<<' ';
            count=1;
        }
    }
    cout<<arr[n-1]<<':'<<count<<' ';
    return 0;
}