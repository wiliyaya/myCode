#include <iostream>
#include <string>
using namespace std;
void campare(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    cin >> n;
    /*char *str=new char[n];
    for(int i=0;i<n;i++){
        cin>>str[n];
    }*/
    string str1;
    cin >> str1;
    string str2(str1);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (str2[j] > str2[j + 1])
            {
                campare(str2[j], str2[j + 1]);
            }
        }
    }
    int N=str1.size();
    int numb[N];
    
}