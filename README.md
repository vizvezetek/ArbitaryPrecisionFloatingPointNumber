# ArbitaryPrecisionFloatingPointNumber

Compiled by gcc (c++ 14).

The doxygen generated docs available at: https://vizvezetek.github.io/ArbitaryPrecisionFloatingPointNumber/

### How it works:
```c++
#include <iostream>
#include <iomanip>
#include "Fpn.hpp"

using namespace std;

int main(){
    
    Fpn a("-22.9911");
    Fpn b("3333.111189");
    Fpn c("-123.234");
    Fpn d("0.456");
    Fpn e("0.111111");

    double i = -22.9911;
    double j = 3333.111189;
    double k = -123.234;
    double l = 0.456;
    double m = 0.111111;

    Fpn f = a*b*c*d*e;
    double o = i*j*k*l*m;

    cout << "FPN: " << f.toString() << endl;
    cout << "double: " << std::setprecision(50) << o << endl;

    return 0;
}
```
out:

FPN: +478478.0242818719390477005776

double: 478478.0242818719707429409027099609375
