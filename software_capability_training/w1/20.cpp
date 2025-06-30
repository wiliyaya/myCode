#include <iostream>
#include <string>
using namespace std;

void paststr(string& prestr,string& instr){
if(prestr.empty() || instr.empty()) return;
char root=prestr[0];
int pos=instr.find(root);
string inLeft=instr.substr(0,pos);
string inRight=instr.substr(pos+1);
string preLeft=prestr.substr(1, pos);
string preRight=prestr.substr(pos+1);

paststr(preLeft, inLeft);
paststr(preRight, inRight);
cout<<root;

}



int main(){
  while (true)
  {
    int n;
    cin>>n;
    if(n==0) break;

    string prestr,instr;
    cin>>prestr>>instr;
    paststr(prestr,instr);
    cout<<endl;
  }
  
}
