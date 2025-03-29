#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string str1,string str2)
{
    return str1[str1.length()-1]<str2[str2.length()-1];
}

int main()
{
    vector<string>arr;
    string sr;
    while(cin>>sr)
    {
        arr.push_back(sr);
    }
    sort(arr.begin(),arr.end(),cmp);

    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i].substr(0,arr[i].length()-1)<<' ';
    }
    cout<<endl;
    return 0;

}