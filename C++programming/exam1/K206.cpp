#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    int Limak = 1, Bob = 2;
    int A[T];
    int B[T];
    for (int i = 0; i < T; i++)
    {
        cin >> A[i] >> B[i];
    }
    for (int i = 0; i < T; i++)
    {

        while (1)
        {
            if (A[i] >= Limak)
            {
                cout << "Bob" << endl;
                break;
            }
            else
                Limak += 2;

            if (B[i] >= Bob)
            {
                cout << "Limak" << endl;
                break;
            }
            else
                Bob += 2;
        }
    }
    return 0;
}