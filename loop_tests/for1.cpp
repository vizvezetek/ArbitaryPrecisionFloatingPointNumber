#include <iostream>
#include <iomanip>

int main(){

    int i = 0;
    for (float f = 2.0000001; f < 2.0000099; f+= 0.0000002){
        i++;
        std::cout  << i<< ": " <<  std::setprecision(50) << f << std::endl;
    }
    std::cout << "i: " << i << std::endl; //expected: 49; real: 42
    
    return 0;
}