#include <iostream>
using namespace std;

class Square
{
public:
    Square() { cin >> this->r; }
    int area() const { return r * r; }

    virtual void shapeName() const { cout << "Square:"; }
    friend ostream &operator<<(
        ostream &out, Square &sq)
    {
        out << " r=" << sq.r;
        return out;
    }
    virtual void display() const
    {
        cout << "r= " << r;
    }

protected:
    int r;
};

class Cube : public Square
{
public:
    Cube()
        //const
    {
    }
    int area() const
    {
        return 6 * r * r;
    }
    void shapeName() const
    {
        cout << "Cube:";
    }
    void display() const
    {

        Square::
            display();
    }
};

void display(
    Square *s)
{
    s->shapeName();
    s->display();
    cout << " area=" << s->area() << endl;
}

int main()
{
    Square sq1;
    Cube cub1;
    Square *SQptr[2] = {&sq1, &cub1};
    for (int i = 0; i < 2; i++)
    {
        display(SQptr[i]);
    }
    return 0;
}