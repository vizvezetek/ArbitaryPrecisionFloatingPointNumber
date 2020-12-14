# ArbitaryPrecisionFloatingPointNumber

Compiled by gcc (c++ 14).

The doxygen generated docs available at: https://vizvezetek.github.io/ArbitaryPrecisionFloatingPointNumber/

### Compile
```shell
$ make
```

### How it works:
```c++
#include <iostream>
#include <iomanip>
#include "Fpn.hpp"

using namespace std;

int main(){
    
    Fpn fa("-22.9911");
    Fpn fb("3333.111189");

    double da = -22.9911;
    double db = 3333.111189;

    Fpn fo = fb/fa;
    double do = db/da;

    cout << "FPN: " << fo << endl;
    cout << "double: " << std::setprecision(50) << o << endl;

    return 0;
}
```
out:

FPN: -144.9739764082623275963307540744027036548925453762542897034069705233764369690880384148648824980100995

double: -144.974
