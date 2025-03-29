#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct student
{
    string name;
    int arr[7] = {0};
    int grade;
};
void trans(student& a,student& b){
    student c = a;
    a=b;
    b=c;
}
int main()
{
    int n;
    cin >> n;
    student *stuArr = new student[n];
    for (int i = 0; i < n; i++)
    {
        cin >> stuArr[i].name;
        for (int j = 0; j < 7; j++)
        {
            cin >> stuArr[i].arr[j];
        }
        sort(stuArr[i].arr, stuArr[i].arr + 7);
        int all = 0;
        for (int j = 1; j < 6; j++)
        {
            all += stuArr[i].arr[j];
        }
        stuArr[i].grade = all;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (stuArr[i].grade > stuArr[j].grade)
            {
                trans(stuArr[i],stuArr[j]);
                /*int temp = stuArr[i].grade;
                stuArr[i].grade = stuArr[j].grade;
                stuArr[j].grade = temp;*/
            }
        }
    }
    while(n--){
        cout<<stuArr[n].name<<' '<<stuArr[n].grade<<endl;
    }

    delete[] stuArr;
    return 0;
}