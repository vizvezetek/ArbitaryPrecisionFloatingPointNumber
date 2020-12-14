#include <iostream>
#include "../Fpn.hpp"

using namespace std;

int main(){
    
    Fpn fa("-22.9911");
    Fpn fb("3333.111189");

    double da = -22.9911;
    double db = 3333.111189;

    Fpn fout = fb/fa;
    double dout = db/da;

    cout << "Fpn: " << fout << endl;
    cout << "double: " << dout << endl;

    /**
     * The output will be:
     * 
     *  Fpn: -144.9739764082623275963307540744027036548925453762542897034069705233764369690880384148648824980100995
     *  double: -144.974
     * 
    */

    return 0;
}