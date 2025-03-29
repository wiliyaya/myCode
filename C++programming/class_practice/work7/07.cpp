#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    cin >> T;
    cin.ignore();
    string s;
    int begin=0;
    for (int i = 0; i < T; i++)
    {
        cin >> s;
        int n = s.size();
        int end=0;
        bool issafe=true;
        for (int j = 0; j < n; j++)
        {
            if (s[j] != '.')
            {
                begin=j-s[j]+'0';
                if(begin<0){
                    begin=-begin;
                }
                if(begin<=end){
                    issafe=false;
                    //cout<<"unsafe"<<endl;
                    break;
                }
                end=j+s[j]-'0';
            }
        }
        cout<<(issafe ? "safe":"unsafe")<<endl;
        //cout<<"safe"<<endl;
    }
    return 0;
}