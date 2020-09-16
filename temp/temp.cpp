#include <iostream>
#include <iomanip>
#include <cmath>

#define TAYLOR_PREC 25
#define EPS 1e-8

using namespace std;

const long double piii = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263;


// 12 faktoriális már nem fér bele az integer ábrázolási tartományába
// unsigned long long int factorial(int x){
//     int out = 1;

//     if (x==0){
//         return out;
//     }
//     else{
//         for (int i = 1; i<=x; i++){
//             out *= i;
//         }
//     }
//     return out;
// }

unsigned long long int factorial(double number){
    if (number == 0) return 1;
    return number * factorial(number-1);
}

//taylor series -> ez feltehetőleg nem lesz jó.
double fsin(double x){
    
    double taylor_series = 0;

    for (int n = 0; n <= TAYLOR_PREC; n++){
        taylor_series += ( (pow(-1, n) * pow(x, 2*n+1)) / factorial(2*n+1) );
    }
    return taylor_series;

}

long double fsin1(float radian){
    float result = 0.0;

    for(int x=1; x<TAYLOR_PREC; x++)
    {
        float firstPart = pow (-1, (x+1)); //(-1)^n+1
        float secondPart = pow(radian,((2*x)-1)); // x^2n-1
        float thirdPart = factorial((2*x)-1); // (2n-1)!
        result = result + firstPart*(secondPart/thirdPart);
    }

    return result;
}

long double fsin2(long double x){
    long double tolerance = 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001; // or whatever limit you want
    long double sin = 0.;
    int n = 1;
    long double term = x;
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

long double fcos(double x) 
{ 
    double res = 1; 
    double sign = 1, fact = 1,  
                     pow = 1; 
    for (int i = 1; i < TAYLOR_PREC; i++) 
    { 
        sign = sign * -1; 
        fact = fact * (2 * i - 1) *  
                           (2 * i); 
        pow = pow * x * x; 
        res = res + sign *  
              pow / fact; 
    } 
  
    return res;  
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
    // cout << std::setprecision(50) <<  pow2(10.0, -3.0) << endl;


    // std::cout << std::setprecision(50) <<  "sin1\t" << fsin(piii) <<endl; 

    std::cout << std::setprecision(50) <<  "sin1\t" << fsin1(piii) <<endl;
    std::cout << std::setprecision(50) <<  "sin2\t" << fsin2(piii) <<endl;
    std::cout << std::setprecision(50) <<  "mat.sin\t" << sin(piii) <<endl;

    std::cout << std::setprecision(50) <<  "cos\t" << fcos(piii) <<endl;
    std::cout << std::setprecision(50) <<  "mat.cos\t" << cos(piii) <<endl;
    
    return 0;
}

