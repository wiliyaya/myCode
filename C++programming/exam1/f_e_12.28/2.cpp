#include <iostream>
#include <string>
using namespace std;

void Erase(string &s)
{
    while (s.find("*") != string::npos)
    {
        s.erase((s.find("*") - 1), 1);
        s.erase(s.find("*"), 1);
    }
}

int main()
{
    string s;
    cin >> s;
    Erase(s);
    // long long num=s.size();
    // for(long long )
    cout << s << endl;
    return 0;
}