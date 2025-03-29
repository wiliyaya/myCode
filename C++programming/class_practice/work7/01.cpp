#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool ifnzero(int &n)
{
    for (int NUM : n)
    {
        if (NUM == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string *str = new string[n];
    char cha[26];
    cha[0] ="A";
    // char& A=cha[0];
    for (int i = 1; i < 26; i++)
    {
        cha[i] = cha[i - 1]++;
    }
    int num[26];
    for (int i = 0; i < n; i++)
    {
        getline(cin, str[i]);
        for (int j = 0; j < str[i].size(); j++)
        {
            str[i][j] = toupper(str[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < str.size(); j++)
        {
            for (int k = 0; k < 26; k++)
            {
                if (str[i][j] == cha[k])
                {
                    num[k]++;
                }
            }
        }
    }
    for(int I=0;I<n;I++){
    if (ifnzero(num))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << ' ';
        for (int i = 0; i < 26; i++)
        {
            if (num[i] == 0)
            {
                cout << cha[i] << ' ';
            }
        }
    }}
    // 输出有点复杂，写个函数吧
    /*char cha[26];
    cha[0] = "A";
    // char& A=cha[0];
    for (int i = 1; i < 26; i++)
    {
        cha[i] = cha[i - 1]++;
    }*/
}