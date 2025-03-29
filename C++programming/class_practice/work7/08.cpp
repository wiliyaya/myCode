#include <iostream>
#include <string>
using namespace std;
bool left(char a)
{
    if (a == 'q' || a == 'w' || a == 'e' || a == 'r' || a == 't' || a == 'a' || a == 's' || a == 'd' || a == 'f' || a == 'g' || a == 'z' || a == 'x' || a == 'c' || a == 'v' || a == 'b'||a == 'Q' || a == 'W' || a == 'E' || a == 'R' || a == 'T' || a == 'A' || a == 'S' || a == 'D' || a == 'F' || a == 'G' || a == 'Z' || a == 'X' || a == 'C' || a == 'V' || a == 'B')
    {
        return true;
    }
    else
        return false;
}
int main()
{
    int n;
    cin >> n;
    string *str = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    // int num;
    int all=0;
    int *time = new int[n];
    for (int i = 0; i < n; i++)
    {
        int num = str[i].size();
        time[i] = 2;
        for (int j = 1; j < num; j++)
        {
            if (left(str[i][j]))
            {
                if (left(str[i][j - 1]))
                {
                    time[i] += 4;
                }
                else
                    time[i] += 2;
            }
            else
            {
                if (left(str[i][j - 1]))
                {
                    time[i] += 2;
                }
                else
                    time[i] += 4;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(str[i]==str[j])
            {
                time[i]=time[i]/2;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        all+=time[i];
    }
    cout<<all;
    delete[] str;
    delete[] time;
    return 0;
}
