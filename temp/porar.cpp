#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

# define M_PI 3.14159265358979323846  /* pi */
# define DM_PI 6.28318530717958647692  /* 2*pi */

#define TAYLOR_PREC 110
#define EPS 1e-13

using namespace std;

const long double piii = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263;


// https://stackoverflow.com/questions/22050980/working-on-code-to-calculate-cosine-with-factorial-sum

// https://stackoverflow.com/questions/3518973/floating-point-exponentiation-without-power-function


unsigned long long int fact2(int x){
    return (x == 0) ? 1 : (x * fact2(x-1));
}

double abs2(double x){
    if (x < 0.0){
        // this->sign = '+';
        // return x; 
        return x*(-1.0); //ezt itt az FPN-nél majd egy előjelváltásra csere.
    }
    return x;
    
}

double round2(double x){
    /*

    if (fract[0] >= 5){
        intPart+=1;
        fractPart = [000];
        return number;
    }
    if (fract[0] < 4){
        fractPart = [000];
        return number;
    }

    */
    return round(x);
}

long double sSquare(double n, double i, double j) 
{ 
    double mid = (i + j) / 2; 
    double mul = mid * mid; 
  
    if ((mul == n) || (abs2(mul - n) < EPS)) 
        return mid; 
    else if (mul < n) 
        return sSquare(n, mid, j); 
    else
        return sSquare(n, i, mid); 
} 
  
long double sqrt2(double n) 
{ 
    double i = 1; 

    while (true) { 
  
        if (i * i == n) { 
            // cout << fixed << setprecision(0) << i; 
            return i; 
        } 
        else if (i * i > n) { 
            double res = sSquare(n, i - 1, i); 
            // cout << fixed << setprecision(5) << res; 
            return res;
        } 
        i++; 
    } 
} 


long double pow2(double x, double y){

    if (x < 0 && abs2( round2(y)-y ) < EPS) {
        return pow2(-x, y) * ( (int)round2(y)%2==1 ? -1 : 1);
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


long double sin2(double x) 
{ 
    //convert the number X to an equal value with the 2pi period
    if (x > 0 && x>(DM_PI) ){
        while (x > (DM_PI) ){
            x -= (DM_PI);
        }
    }
    else if (x < 0 && x<(-DM_PI) ){
        while (x < (-DM_PI) ){
            x += (DM_PI);
        }
    }
    else if (x == 0){
        return 0;
    }
    
    double res = x; 
    double sign = 1, fact = 1,  pow = x; 

    // cout << "sign" << "\t"<< "fact" << "\t"<<"pow" << "\t" << "res" << endl;
    // cout << sign << "\t"<< fact << "\t"<<pow << "\t" << res << endl;
    // cout << endl;

    for (int i = 1; i < TAYLOR_PREC; i++) 
    { 
        sign = sign * -1; 
        fact = fact * (2 * i +1) *  (2 * i ); 
        // cout << fact << endl;
        pow = pow * x * x; 
        // cout << pow << endl;
        res = res + sign *  pow / fact; 
        // cout << sign << "\t"<< fact << "\t"<<pow << "\t" << res << endl;

        if (i==10) break;
    } 
  
    return res;  
} 

long double cos2(double x) 
{ 

    if (x > 0 && x>(DM_PI) ){
        while (x > (DM_PI) ){
            x -= (DM_PI);
        }
    }
    else if (x < 0 && x<(-DM_PI) ){
        while (x < (-DM_PI) ){
            x += (DM_PI);
        }
    }
    else if (x == 0){
        return 1.0;
    }

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

int main (){
    


    // std::cout << std::setprecision(10) <<  "sqrt \t" << sqrt(13.0) <<endl;
    // std::cout << std::setprecision(10) <<  "sqrt2 \t" << sqrt2(13.0) <<endl; // ez lesz a jó.

    // cout << std::setprecision(10) << "pow \t" <<  pow(11.3, -3.1) << endl;
    // cout << std::setprecision(10) << "pow2 \t" <<  pow2(11.3, -3.1) << endl; // ez lesz a jó
    
    // std::cout << std::setprecision(10) <<  "sin\t" << sin(22.2) <<endl;
    // std::cout << std::setprecision(10) <<  "sin2\t" << sin2(22.2) <<endl; // ez áll a legközelebb a jóhoz.
    // std::cout << std::setprecision(10) <<  "sin2\t" << sin2(6.0) <<endl; // ez áll a legközelebb a jóhoz.
    // std::cout << std::setprecision(10) <<  "sin\t" << sin(6.0) <<endl; // ez áll a legközelebb a jóhoz.

    // std::cout << std::setprecision(10) <<  "cos\t" << cos(22.2) <<endl;
    // std::cout << std::setprecision(10) <<  "cos2\t" << cos2(22.2) <<endl; //ok

    // std::cout << "round: " << round2(-2.491) << endl;
    // std::cout << "fact2: " << fact2(3) << endl;

    // cout << std::sin(2.3) << endl;
    // cout << sin2(2.3) << endl;

    // cout << sin2(-100.7292) << endl; // 0.666273
    // cout << sin2(-100.7292) << endl; // 0.666273
    // cout << sin2(-69.3133) << endl; // 0.666273
    // cout << sin2(-12.7646) << endl; // 0.666273
    // cout << sin2(-6.48142) << endl; // 0.666273
    // cout << sin2(-0.198235) << endl; // 0.666273
    // cout << sin2(6.08495) << endl; // 0.666273
    // cout << sin2(12.3681) << endl; // 0.666273

    // cout << sin2(-1000.7292) << endl; // 0.666273
    // cout << sin(-1000.7292) << endl; // 0.666273

    // cout << sin2(1000.7292) << endl; // 0.666273
    // cout << sin(1000.7292) << endl; // 0.666273

    // cout << cos2(-1000.7292) << endl; // 0.666273
    // cout << cos(-1000.7292) << endl; // 0.666273

    // cout << cos2(1000.7292) << endl; // 0.666273
    // cout << cos(1000.7292) << endl; // 0.666273


    cout << sin2(5.7292) << endl; // 0.666273
    cout << sin(5.7292) << endl; // 0.666273

    cout << cos2(-5.7292) << endl; // 0.666273
    cout << cos(-5.7292) << endl; // 0.666273

    // return 0;
}

