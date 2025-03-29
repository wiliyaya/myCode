#include <iostream>
using namespace std;
#include <string>

int caculateWeekday(int year,int month,int day)
{
    if(month<3)
    {
        month+=12;
        year--;
    }
    int k=year%100;
    int j=year/100;

    int h=(day+ (13*(month+1))/5 + k + k/4 + j/4 - 2*j )%7;
    return (h+7)%7;
}
int main()
{
    int T;
    cin>>T;
    cin.ignore();

    while(T--)
    {
        string date;
        getline(cin,date);

        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,2));
        int day=stoi(date.substr(8,2));

        int cur_weekday=caculateWeekday(year,month,day);

        while(true)
        {
            year++;
            int next_weekday=caculateWeekday(year,month,day);
            if(next_weekday==cur_weekday)
            {
                cout<<year<<endl;
                break;
            }
        }
    }
    return 0;
}