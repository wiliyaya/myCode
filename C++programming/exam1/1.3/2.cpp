#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Sen
{
    int num;
    string s;
};

/*void getSen(string &a,vector<Sen>& vec)
{
    int len=a.size();
    Sen sen;
    sen.num=a[len]-48;
    sen.s=a.substr(0,len-1);

    vec.push_back(sen);
}*/
void getSen(string &A, vector<Sen> &vec)
{
    size_t pos1 = 0, pos2;
    pos2 = A.find(' ');
    while (pos2 != string::npos)
    {
        string a;
        a = A.substr(pos1, pos2);
        int len = a.size();
        Sen sen;
        sen.num = a[len-1] - 48;
        sen.s = a.substr(0, len - 1);

        vec.push_back(sen);

        pos1=pos2;
        pos2=A.find(' ',pos1+1);
    }
}

bool cmp(Sen &a, Sen &b)
{
    return a.num < b.num;
}
int main()
{
    vector<Sen> vec;
    string a;
    getline(cin, a);

    // len=a.size();  num=a[len];  s=s.substr(0,len);
    /*while(cin>>a)
    {
        getSen(a,vec);
    }*/
   getSen(a,vec);

    sort(vec.begin(), vec.end(), cmp);

    for (vector<Sen>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << it->s << ' ';
    }
    cout << endl;
    return 0;
}