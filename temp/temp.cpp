#include <iostream>
#include <iomanip>
#include <cmath>

#define TAYLOR_PREC 6
#define EPS 1e-10

using namespace std;


// 12 faktoriális már nem fér bele az integer ábrázolási tartományába
unsigned int factorial(int x){
    int out = 1;

    if (x==0){
        return out;
    }
    else{
        for (int i = 1; i<=x; i++){
            out *= i;
        }
    }
    return out;
}

//taylor series
double fsin(double x){
    
    double taylor_series = 0;

    for (int n = 0; n <= TAYLOR_PREC; n++){
        taylor_series += ( (pow(-1, n) * pow(x, 2*n+1)) / factorial(2*n+1) );
    }
    return taylor_series;

}

double fsin2(double x){
    double tolerance = 0.0000007; // or whatever limit you want
    double sin = 0.;
    int n = 1;
    double term = x;
    while ( abs(term) > tolerance ) {
        sin += term;
        term *= -( (x/(n+1)) * (x/(n+2)) );
        n+= 2;
    }
    return sin;
}

double sqrt2(double x) {
    double a = 0, b = x>1 ? x : 1; 
    while(abs(a-b) > EPS) {
        double y = (a+b)/2;
        if (y*y > x) b = y; else a = y;
    }
    return a;
}

double pow2(double x, double y){

    if (x < 0 && abs( round(y)-y ) < EPS) {
        return pow2(-x, y) * ( (int)round(y)%2==1 ? -1 : 1);
    } 
    else if (y < 0) {
        return 1/pow2(x, -y);
    } 
    else if(y > 1) {
        return pow2(x * x, y / 2);
    } 
    else {
        double fraction = 1;
        double result = 1;

        while(y > EPS) {
            if (y >= fraction) {
                y -= fraction;
                result *= x;
            }

            fraction /= 2;
            x = sqrt2(x);
        }
        return result;
    }
}

int main (){
    
    // std::cout << fsin(3.141) <<endl;
    // std::cout << sin(3.141) <<endl;
    
    // cout << std::setprecision(50) <<  sqrt2(2.0) << endl;
    // cout << std::setprecision(50) <<  sqrt(2.0) << endl;

    // cout << (int)round(2.334455)%2 << endl;

    // cout << pow2(3.5, 4.5) << endl;
    cout << std::setprecision(50) <<  pow2(10.0, -3.0) << endl;

    std::cout << fsin(3.14) <<endl;
    std::cout << fsin2(3.14) <<endl;
    std::cout << sin(3.14) <<endl;

    
    return 0;
}

