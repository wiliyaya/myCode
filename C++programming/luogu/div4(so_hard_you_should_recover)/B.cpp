#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int a_num,b_num;
    bool A=false,B=false;
    if(a%2==0)
    {
        a_num=a/2;
        A=true;
    }
    else {a_num=(a+1)/2;}
    if(b%2==0)
    {
        b_num==b/2;
        B=true;
    }
    else {b_num=(b+1)/2;}
    if(A&&B)
    {
        if(a_num-b_num-1>=0)
        {
            cout<<a_num-b_num-1;
        }
        else cout<<-(a_num-b_num-1);
    }
    else if(A||B)
    {
        cout<<a_num+b_num-2;
    }
    else{
        if(a_num-b_num-1>=0)
        {
            cout<<a_num-b_num-1;
        }
        else cout<<-(a_num-b_num-1);

    }
    return 0;

}
