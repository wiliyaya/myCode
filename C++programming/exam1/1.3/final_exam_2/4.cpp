#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string t, s;
        cin >> t >> s;
        bool isok = true;
        for (size_t i = 0; i < t.size(); i++)
        {
            if (s.find(t[i], 0) == string::npos)
            {
                isok = false;
                break;
            }
        }

        if (!isok)
        {
            sort(s.begin(), s.end());
            cout << s << endl;
            return 0;
        }

        size_t pos1, pos2;
        pos1 = s.size();
        pos2 = 0;

        set<char> tt;
        for (size_t i = 0; i < t.size(); i++)
        {
            tt.insert(t[i]);
        }

        for (char c : tt)
        {
            size_t pos = s.find(c);
            if (pos != string::npos)
            {
                pos1 = min(pos1, pos);
                pos2 = max(pos2, pos);
            }
        }

        /*for(set<char>::iterator it=tt.begin();it!=tt.end();it++)
        {
            size_t pos=s.find(*it,0);
            if(pos<pos1)
            {
                pos1=pos;
            }
            if(pos>pos2)
            {
                pos2=pos;
            }

        }

        /*vector<char> vv;
        for(set<char>::iterator it=tt.begin();it!=tt.end();it++)
        {
            vv.push_back(*it);
        }*/

        /*for(size_t i=0;i<tt.size();i++)
        {
            size_t pos=s.find(vv[i],0);
            if(pos<pos1)
            {
                pos1=pos;
            }
            if(pos>pos2)
            {
                pos2=pos;
            }
        }*/

        cout << s.substr(pos1, pos2 - pos1 + 1) << endl;
    }
    return 0;
}
