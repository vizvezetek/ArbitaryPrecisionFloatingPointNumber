#include <iostream>
#include "Fpn.hpp"

using namespace std;

int main(int argc, char* argv[]){

	int i = 0;
    for (Fpn f("2.0000001") ; f < Fpn("2.0000099"); f = f + Fpn("0.0000002") ){
        i++;
        std::cout  << i<< ": " <<  f << std::endl;
    }
    std::cout << "i: " << i << std::endl; //expected: 49; real: 49
  
    return 0;
}