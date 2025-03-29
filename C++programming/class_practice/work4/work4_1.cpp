 #include "judge.h"
#include <iostream>
using namespace std;
bool prime(int a)
{
    for (int i = 1; i < a; i++)
    {
        if (a % i == 0)
        {
            return false;
            break;
        }
    }
    return true;
}
bool plalindrome(int a){
    int reserve=0;
    int temp=a;
    while(a!=0){
        reserve+=a%10;
        a=a/10;
    }
    if(reserve==temp){
        return true;
    }
    else return false;
}