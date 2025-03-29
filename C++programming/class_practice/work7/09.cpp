#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    size_t pos = 0;
    // int n=s.size();
    while ((pos=s.find("WUB", pos)) != string::npos)
    //while(s.find("WUB",pos))
    {
        // pos = s.find("WUB", pos);
        s.replace(pos, 3, " ");
        pos += 1;
    }
    int n = s.size();
    for (int i = 0; i < n;)
    {
        if (s[i] == ' ')
        {
            while (i + 1 < n && s[i + 1] == ' ')
            {
                s.erase(i + 1, 1);
                n--; // 注意字符串长度改变
            }
        }
        i++;
        // if (s[i + 1] == ' ')
        // {
        //     s = s.erase(i + 1);
        // }
    }
    cout << s << endl;
    return 0;
}