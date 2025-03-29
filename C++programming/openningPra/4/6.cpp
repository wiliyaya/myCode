#include <iostream>
using namespace std;
class Time
{
public:
    friend ostream& operator<<(ostream& cout,const Time& a);

public:
    int h;
    int m;

    Time()
    {
        h=0;
        m=0;
    }

    Time operator+(const int s)
    {
        Time a;
        a.h=this->h+(s/60);
        a.m=this->m+(s%60);
        if(a.h>=24)
        {
            a.h-=24;
        }
        if(a.m>=60)
        {
            a.h+=1;
            a.m-=60;
        }
        return a;
        // this->h=this->h+(s/60);
        // this->m=this->m+(s%60);
        // if(this->m>=60)
        // {
        //     this->h+=1;
        //     this->m=this->m-60;
        // }
        // return *this;
    }

    bool operator<(const Time& other)
    {
        if(this->h<other.h)
        {
            return true;
        }
        else if(this->h>other.h)
        {
            return false;
        }

        else
        {
            if(m<other.m)
            {
                return true;
            }
        }
        return false;
    }

};


ostream& operator<<(ostream& os, const Time& a)
{
    os<<a.h<<" "<<a.m;
    return os;
}

int main()
{
    int n,s;
    cin>>n>>s;

    //cout<<n<<" "<<s<<endl;

    Time* time=new Time[n];
    for(int i=0;i<n;i++)
    {
        cin>>time[i].h>>time[i].m;
    }

    for(int i=0;i<n;i++)
    {
        if(time[i]+2+2*s<time[i+1])
        {
            cout<<(time[i]+1+s)<<endl;
            break;
        }
    }

    delete[] time;
    return 0;
}







