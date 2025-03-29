#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
class Cus
{
public:
    string name;
    float money;
    long long date; 
};

bool cmp(Cus& a,Cus& b)
{
    if(a.money==b.money)
    {
        if(a.date==b.date)
        {
            return a.name[0]<b.name[0];
        }
        else{
            return a.date<b.date;
        }

    }
    else
    {
        return a.money>b.money;
    }
}

void makeCus(vector<Cus>&vec)
{
    while(true)
    {
        string input;
        Cus cus;
        if(getline(cin,input))
        {
            if(input=="end")
            {
                break;
            }   
        }

        istringstream iss(input);
        if(iss>>cus.name>>cus.money>>cus.date)
        {
            vec.push_back(cus);
        }
    }
}

int main()
{
    vector<Cus>vec;
    makeCus(vec);
    sort(vec.begin(),vec.end(),cmp);
    for(vector<Cus>::iterator it=vec.begin();it!=vec.end();it++)
    {
        cout<<it->name<<endl;
    }
    return 0;
}

