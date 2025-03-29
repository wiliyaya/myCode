#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    int result[T];

    for (int t = 0; t < T; t++)
    {
        result[t] = 1;
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i < n - 1; i++)
        {
            bool lastbigger = a[i] > a[i - 1];
            bool bigger = a[i] > a[i + 1];
            if (a[i - 1] == a[i] || a[i] == a[i + 1])
            {
                result[t]--;
                break;
            }
            else if (lastbigger)
            {
                if (!bigger)
                {
                    result[t]--;
                    break;
                }
            }
            else if (bigger)
            {
                result[t]--;
                // result[i - 1] = "No";
                // cout << result[i - 1];
                break;
            }
        }
    }
    for (int i = 0; i < T; i++)
    {
        cout << (result[i] ? "Yes" : "No") << endl;
        /*if (result[i] == 0)
        {
            cout << "No" << endl;
        }
        else
            cout << "Yes" << endl;
        /*switch(result[i]){
            case 0:cout<<"No"<<endl;break;
            case 1:cout<<"Yes"<<endl;break;
        }*/
    }
    /*for (int i = 0; i < T; i++)
    {
        cout << result[i] << endl;
    }*/
    return 0;
}