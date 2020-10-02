#include <iostream>
using namespace std;

const size_t maxPower = 5;
struct Poly
{
    double coefs[maxPower];
    size_t power;

    int diff1()
    {
        
    }

    void diff2(Poly p)
    {
        for (int i = 0; i < p.coefs; i++)
        {
            cout << coefs[i] * (power - i) << "x^" << (power - i); 
        }
    }
};

int main()
{

    Poly p;
    p.diff2(p);

    return 0;
}