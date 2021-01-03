#include <iostream>
#include "Fpn.hpp"

using namespace std;

int main(int argc, char* argv[]){

    Fpn i("0.0");
    Fpn min("2.0000001");
    for (Fpn f = min; f < Fpn("2.0000099"); f= min + (i*Fpn("0.0000002")) ){
        i= i+ Fpn("1.0");
        std::cout << i<< ": " << f << std::endl;
    }
    std::cout << "i: " << i << std::endl; //expected: 49; real: 49
    
    return 0;
}