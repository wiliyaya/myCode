#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// 判断是否为闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取指定年份和月份的天数
int getDaysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28; // 二月的天数
    }
    // 其他月份的天数
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

// 输出月历
void printCalendar(int year, int month) {
    // 获取该月的第一天
    tm time_in = {0};
    time_in.tm_year = year - 1900; // tm_year是从1900年开始的
    time_in.tm_mon = month - 1; // tm_mon是从0开始的
    time_in.tm_mday = 1; // 设置为该月的第一天
    mktime(&time_in); // 计算时间

    // 获取该月第一天是星期几
    int firstDay = time_in.tm_wday; // tm_wday: 星期几，0=星期天

    // 获取该月的天数
    int daysInMonth = getDaysInMonth(year, month);

    // 输出月历头部
    cout << "Su Mo Tu We Th Fr Sa" << endl;

    // 输出空格
    for (int i = 0; i < firstDay; i++) {
        cout << "   "; // 每个数字占3个字符
    }

    // 输出每一天
    for (int day = 1; day <= daysInMonth; day++) {
        cout << setw(2) << day << " "; // 输出日期，宽度为2
        if ((day + firstDay) % 7 == 0) {
            cout << endl; // 每7天换行
        }
    }
    cout << endl; // 最后换行
}

int main() {
    int year, month;
    cout << "Enter year (Y > 1920) and month (1 <= M <= 12): ";
    cin >> year >> month;

    if (year <= 1920 || month < 1 || month > 12) {
        cout << "Invalid input." << endl;
        return 1; // 输入无效
    }

    printCalendar(year, month); // 打印月历
    return 0;
}
