//I can't understand.
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

string minwindow(string S,string T)
{
    if(T.empty()||S.empty())return "";
    unordered_map<char,int> charCount;

    for(char c:T)
    {
        charCount[c]++;
    }

    int required=charCount.size();
    int l=0,r=0;//左右指针初始化
    int formed =0;//当前窗口中满足条件的字符的数量

    unordered_map<char,int> windowCount;//当前窗口中字符的计数

    int minLength=INT_MAX,minLeft=0; //最小窗口长度和起始位置初始化

    //开始滑动窗口
    while(r<s.size())
    {
        char c=S[r];//当前右指针指向的字符
        windowCount[c]++; //当前字符加入窗口计数

        //检查当前字符是否是目标字符，并且数量是否满足要求
        if(charCount.count(c)>0&&windowCount[c]==charCount[c])
        {
            formed++;
        }

        //尝试收缩窗口直到不再满足条件
        while(l<+r&&formed==required)
        {
            c=S[l];//当前左指针指向的字符

            //更新最小窗口
            if(r-l+1<minLength)
            {
                minLength=r-l+1;//更新最小长度
                minLeft=1;//更新最小窗口的起始位置
            }

            windowCount[c]--;//从窗口中移除左指针指向的字符
            //检查移除后是否仍满足条件
            if(charCount.count(c)>0&&windowCount[c]<charCount[c])
            {
                formed--;//不再满足条件，减少满足的字符数量
            }
            l++;//收缩左指针
        }
        r++;//拓展右指针
    }

    //如果没有找到有效的窗口，返回空字符串，否者返回最小窗口的子串
    return minLength==INT_MAX ? "":S.substr(minLeft,minLength);
}

int main()
{
    string S,T;
    cin>>S;
    cin>>T;

    string result=minWindow(S,T);

    if(result.empty())
    {
        cout<<"No such substring exists."<<endl;
    }
    else{
        cout<<result<<endl;
    }
    return 0;
}