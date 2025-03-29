#include <iostream>
#include <string>

using namespace std;
class Fish
{
    protected:
        float length;
        float ambientTempture;
    public:
        string fishName;
        Fish(float ambTemp)
        {
            ambientTempture=ambTemp;
            cin>>length;
        }
        virtual float operator++()=0;
        virtual ~Fish() {};
};

class Guppy : public Fish
{
        float brightness;
    public:
        Guppy(float brtness,float ambTemp) ;
        float operator++();
        virtual ~Guppy();
        static int GuppyExitNum;
};

class Macropodus : public Fish
{
    private:
        float speed;
    public:
        static int MacroExitNum;
        Macropodus(float ambTemp) ;
        float operator++();
        virtual ~Macropodus();
};

class CoralReef
{
        Fish** pFishes;
        int orgFishNum;
        float  guppyLen;
        float  macropodusLen;
        float ambientTempture;
        float brightness;
    public:
        CoralReef()
        {
            cin>>brightness;
            cin>>ambientTempture;
        }
        void hatchFishes();
        void expelFishes()
        {
            for(int i=0; i<orgFishNum; i++)
            {
                if((pFishes[i]->fishName=="Guppy")&&(++(*pFishes[i])>=guppyLen)||((pFishes[i]->fishName=="Macropodus")&&(++(*pFishes[i])>=macropodusLen)))
                {
                    delete pFishes[i];
                    pFishes[i]=NULL;
                }
            }
        }
        void report();
        ~CoralReef();
};
int main()
{
    CoralReef crlrf;
    crlrf.hatchFishes();
    crlrf.expelFishes();
    cout<<"report:"<<endl;//插入提示防偷机
    crlrf.report();
    return 0;
}
Guppy::Guppy(float brtness,float ambTemp) : Fish(ambTemp)
{
    fishName="Guppy";
    brightness=brtness;
}
Guppy::~Guppy()
{
    GuppyExitNum=GuppyExitNum+1;
};


float Guppy::operator++()
{
    return length*(1.0+(int(length)*10+int(brightness/100)*10+(ambientTempture<25?10:0))/100.0);
}


int Guppy::GuppyExitNum=0;

Macropodus::Macropodus(float ambTemp) : Fish(ambTemp)
{
    fishName="Macropodus";
    cin>>speed;
}
Macropodus:: ~Macropodus()
{
    MacroExitNum=MacroExitNum+1;
};

float Macropodus::operator++()
{
    return length*(1.0+(int(speed)/2*10+(ambientTempture>26?20:0))/100.0);
}








int Macropodus::MacroExitNum=0;
void CoralReef::hatchFishes()
{
    cin>>orgFishNum;
    pFishes=new Fish*[orgFishNum];
    for(int i=0; i<orgFishNum; i++)
    {
        string a;
        cin>>a;
        if(a=="Guppy")
            pFishes[i]=new Guppy(brightness,ambientTempture);
        else
            pFishes[i]=new Macropodus(ambientTempture);
    }
    cin>>guppyLen>>macropodusLen;
}
void CoralReef::report()
{
    cout<<"exit Guppy:"<< Guppy::GuppyExitNum<<endl;
    cout<<"exit Macropodus:"<<Macropodus::MacroExitNum<<endl;
    cout<<"remaining Fish:"<<orgFishNum-Guppy::GuppyExitNum-Macropodus::MacroExitNum;
}
CoralReef::~CoralReef()
{
    for(int i=0; i<orgFishNum; i++)
    {
        if(pFishes[i])
            delete pFishes[i];
    }
    delete[]pFishes;
}