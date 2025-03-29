//5个选手ABCDE，10个评委分别对每一名选手打分，去除最高分和最低分，取平均
#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include <string>
#include <algorithm>
#include<ctime>

class Person
{
public:
    Person(string name,int score)
    {
        this->m_name=name;
        this->m_score=score;
    }

    string m_name;
    int m_score;
};


void creatPerson(vector<Person> &v)
{
    string nameSeed="ABCDE";
    for(int i=0;i<5;i++)
    {
        string name=" Ally";
        name+=nameSeed[i];
        int score=0;
        Person p(name,score);

        //将创建的person对象 放入到容器中
        v.push_back(p);
    }
}

//打分
void setScore(vector<Person>&v)
{
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        //将评委的打分放入deque中
        deque<int>d;
        for(int i=0;i<10;i++)
        {
            int score=rand()% 41+60;//随机数60~100
            d.push_back(score);
        }

        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
        {
            cout<<*dit<<" ";
        }
        cout<<endl;

        //排序
        sort(d.begin(),d.end());
        //去除最高，最低分
        d.pop_back();
        d.pop_front();

        //取平均
        int sum=0;
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
        {
            sum+= *dit;
        }

        int avg=sum/d.size();

        it->m_score=avg;

    }
}

void showScore(const vector<Person>&v)
{
    for(vector<Person>::const_iterator it=v.begin();it!=v.end();it++)
    {
        cout<<" 姓名："<<it->m_name<<" 平均分： "<<it->m_score<<endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    //设置种子
    //1.创建5个人
    vector<Person>v;
    creatPerson(v);

    // //测试是否创建成功
    // for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    // {
    //     cout<<"姓名："<<(*it).m_name<<"分数: "<<(*it).m_score<<endl;

    // }

    //打分
    setScore(v);


    //显示
    showScore(v);


    return 0;


    
}