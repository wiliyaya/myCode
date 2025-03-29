#include <iostream>
#include<string>
using namespace std;
class Film
{
protected:
    string title;
    string director;
    int time;
    int quality;
public:
    Film():title(""),director(""),time(0),quality(0){}
    Film(string &str,string &dir,int t,int q):title(str),director(dir),time(t),quality(q){}

    void output()
    {
        cout<<"\ttitle: "<<title
        <<"\tdirector: "<<director
        <<"\ttime: "<<time
        <<"\tquality"<<quality<<endl;
    }

    ~Film()
    {
        cout<<"over";
    }
};

int main()
{
    Film a;
    string aaa="aaa";
    string b="ANN";
    a(aaa,b,120,5);
    a.output();
    return 0;
}