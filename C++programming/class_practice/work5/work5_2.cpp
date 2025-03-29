#include <iostream>
#include <string>
using namespace std;
int main()
{
    string result="Yes";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 1;
    //bool A = arr[i] <= arr[i + 1];
    if (arr[0] <= arr[1])
    {
        for (; i < n - 1; i++)
        {
            if (!(arr[i] <= arr[i + 1]))
            {
                i++;
                break;
            }
        }
    }
    else if (arr[0] >= arr[1])
    {
        for (; i < n - 1; i++)
        {
            if (arr[i] <= arr[i + 1])
            {
                i++;
                break;
            }
        }
    }

    /*else if (arr[0] == arr[1])
    {
        i++;
    }*/
    if (arr[i] <= arr[i + 1])
    {
        for (; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                result="No";
                //cout << "No" << endl;
            }
        }
    }
    else if (arr[i] >= arr[i + 1])
    {
        for (; i < n - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                result="No";
                //cout << "No" << endl;
            }
        }
    }
    cout<<result<<endl;
    return 0;
}