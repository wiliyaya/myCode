#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// void otest(const vector<string> & lines)
// {
//     ofstream ofs;
//     ofs.open("listin.txt",ios::out);
//     for(auto& line:lines)
//     {
//         ofs<<line<<endl;
//     }
// }

int main()
{
    vector<string> lines;
    string input;

    while(true)//用lines储存listin里的内容
    {
        getline(cin,input);
        if(input.empty())
        {
            break;
        }
        lines.push_back(input);
    }

    //把lines里的内容写入listin
    ofstream ofs;
    ofs.open("listin.txt",ios::out);
    for(auto& line:lines)
    {
        ofs<<line<<endl;
    }
    



}