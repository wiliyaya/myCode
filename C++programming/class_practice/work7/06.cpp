#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string t;
    getline(cin, t);
    int n = t.size();
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            reverse(t.begin(),t.begin()+i);
        }
    }
    cout<<t<<endl;
    return 0;
}