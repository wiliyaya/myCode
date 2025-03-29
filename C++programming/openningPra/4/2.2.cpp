#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//判断是否为闰年
bool isLeapYear(int year)
{
    return (year%4==0 && year%100!=0)||(year%400==0);
}

//获取指定年份和月份的天数
int getDaysInMonth(int year,int month)
{
    if(month==2)
    {
        return isLeapYear(year)? 29:28;
    }
    //其它月份的天数
    return (month==4||month==6||month==9||month==11)? 30:31;
}
//输出月历
void printCalendar(int year,int month)
{
    //获取该月的第一天
    tm time_in={0};
    time_in.tm_year=year-1900;//tm_year是从1900年开始
    time_in.tm_mon=month-1;//tm_mon是从0开始
    time_in.tm_mday=1;//设置为该月的第一天
    mktime(&time_in);//将 tm 结构体转换为 time_t 值

    //获取该月的第一天是星期几
    int firstDay=time_in.tm_wday;

    //获取该月的天数
    int daysInMonth=getDaysInMonth(year,month);

    //输出月历头部
    cout<<"Sun Mon Tus Wed Thu Fri Sat"<<endl;

    //输出空格
    for(int i=0;i<firstDay;i++)
    {
        cout<<"    ";
    }

    //输出每一天
    for(int day=1;day<=daysInMonth;day++)
    {
        cout<<setw(3)<<day<<" ";
        if((day+firstDay)%7==0)
        {
            cout<<endl;//每7天换行
        }
    }
    cout<<endl;
}

int main()
{
    int year,month;
    cin>>year>>month;

    printCalendar(year,month);
    return  0;
}