#include <iostream>
#include <functional>
using namespace std;

struct squareFunctor
{
    double operator() (double x) { return x * x; };  
};

double square(double x)
{
    return x * x;
}

void applyFunction(function <double (double)> &f, double arg)
{
    cout << f(arg);
}

int main()
{
    // double (*f)(double) = [](double x) -> double { return x * x; };
    // // [] - capture; (double x) - args; -> double - return type; { return x * x; } - body;
    // int y = 5;
    // [y](double x) -> double { return y * x; };
    // cout << ([y](double x) -> double { return y * x; })(4);

    // ([&y](double x) -> void { return y *= x; })(5);
    // cout << y << endl;

    function<double (double)> f = [](double x) -> double { return x * x; };
    cout << f(5) << endl;
    f = square;
    cout << f(5) << endl;
    squareFunctor sqf;
    cout << f(5) << endl;
    
    applyFunction([](double x) -> double { return x * x; }, 5);
    //applyFunction(square, 5);
    //applyFunction(sqf, 5);

    return 0;
}