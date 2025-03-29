#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string *nums = new string[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> nums[i];
    }
    string target;
    cin >> target;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (i != j)
            {
                //cout<<nums[i].append(nums[j])<<endl;
                if (nums[i]+nums[j]== target)
                {
                    count++;
                } 
            }
        }
    }
    cout<<count<<endl;
}