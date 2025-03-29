#include <iostream>
using namespace std;
int main(){
    int x,hh,mm;
    cin>>x>>hh>>mm;
    bool next=true;
    int k=1;
    if(hh/10==7||hh%10==7||mm/10==7||mm%10==7){
        cout<<'0';
    }
    else while(next)
    {
        int luck=0,luckh,luckm;
        luck=hh*60+mm-k*x;
        if(luck<0){
            luck+=24*60;
        }
        luckh=luck/60;
        luckm=luck%60;
        if(luckh/10==7||luckh%10==7||luckm/10==7||luckm%10==7){
            cout<<k;
            next=false;
        }
        else k++;
    }
}