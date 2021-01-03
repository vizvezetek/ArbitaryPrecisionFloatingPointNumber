#include <iostream>
#include <iomanip>

int main(){

    int i = 0;
    float min = 2.0000001;
    for (float f = min; f < 2.0000099; f= min + i*0.0000002){
        i++;
        std::cout << i<< ": " << std::setprecision(50) << f << std::endl;
    }
    std::cout << "i: " << i << std::endl; //expected: 49; real: 50
    
    return 0;
}