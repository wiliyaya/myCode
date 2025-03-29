#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    int povit = 0;
    int left = 0, right = 0;
    // string str = new string[T];
    vector<string> str(T);
    for (int b = 0; b < T; b++)
    {
        left=0,right=0;
        cin >> str[b];
        int n = str[b].size();
        povit = str[b].find('^');
        for (int i = 0; i < povit; i++)
        {
            if (isdigit(str[b][i]))
            {
                int num = str[b][i] - '0';
                left += (povit - i) * num;
            }
        }
        for (int i = povit + 1; i < n; i++)
        {
            if (isdigit(str[b][i]))
            {
                int num = str[b][i] - '0';
                right += (i - povit) * num;
            }
        }
        if (left != right)
        {
             cout<<(left>right ? "left":"right")<<endl;
        }
        else {
            cout<<"balance"<<endl;
        }
    }
    // delete[] str;
    return 0;
}