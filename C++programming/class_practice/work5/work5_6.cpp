#include <iostream>
//#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A=1;
    //string result = "Yes";
    int month[24];
    bool if29=false;
    for (int i = 0; i < n; i++)
    {
        cin >> month[i];
        if(month[i]==29){
            if(if29){
                cout<<"No"<<endl;
                return 0;
            }
            if29=true;
        }

    }
    for (int i = 0; i < n-1; i++)
    {
        switch (month[i])
        {
        case 28: 
        case 29:
            if (month[i + 1] != 31)
            {
                A--;//result = "No";
                break;
            }
            for (int j = i + 1; j < i + 12; j++)
            {
                if (month[j] == 28 || month[j] == 29)
                {
                    A--;//result = "No";
                    break;
                }
            }
            break;
        case 30:
            if (month[i + 1] != 31)
            {
                A--;//result = "No";
                break;
            }
            break;
        case 31:
            if (month[i + 1] == 31 && month[i + 2] == 31)
            {
                A--;//result = "No";
                break;
            }
            break;
        }
    }
    /*for(int i=0;i<n;i++){
        cout<<month[i]<<' ';
    }*/
    cout<<(A ?  "Yes" : "No")<<endl;//cout<<result;
    return 0;
}