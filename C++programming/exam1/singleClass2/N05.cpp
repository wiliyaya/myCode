#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = 0;
    string nums[n];
    string target;
    for (int i = 0; i < n; i++)
    {
        getline(cin, nums[i]);
    }
    getline(cin, target);
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[i] + nums[j] == target&&i!=j)
            {
                a++;
            }
        }
    }
    cout << a;
}