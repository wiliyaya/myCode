#include <iostream>
using namespace std;
int main()
{
    int n = 0,distance = 0;
    cin >> n >> distance;
    int dot = 2;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] + 2*distance < arr[i + 1])
        {
            dot += 2;
        }
        else if (arr[i] + 2*distance == arr[i + 1])
        {
            dot++;
        }
    }
    cout<<dot<<endl;
    return 0;

}