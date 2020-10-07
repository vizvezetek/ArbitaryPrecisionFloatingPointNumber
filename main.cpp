#include <iostream>
#include <iomanip>
#include <math.h> 
#include <cmath> 

#include "Fpn.hpp"

using namespace std;

int main(){

    // Fpn a("-22.9911",100);
    // Fpn aa("-22.9911",100);
    // Fpn b("3333.111189");
    // Fpn c("-123.234");
    // Fpn d("0.456");
    // Fpn e("0.111111");

    // Fpn fa("200.0");

    // Fpn r("-1234.51283745623847236847384652387654823764872364827364283756248756248756283765236");
    // Fpn q("7.890005348756348765348765823765139485739847539847594827539847593847593847598343475634875601");

    // double i = -22.9911;
    // double j = 3333.111189;
    // double k = -123.234;
    // double l = 0.456;
    // double m = 0.111111;

    // Fpn f = a*b*c*d*e;
    // double o = i*j*k*l*m;

    // cout << (r/q).toString() << endl;

    // cout << "FPN: " << f.toString() << endl;
    // cout << "double: " << std::setprecision(50) << o << endl;

    // if (a < aa){
    //     cout << "true" << endl;
    // }
    // else
    // {
    //     cout << "false" << endl;
    // }

    //
    // cout << '\n' << Fpn::fact(fa) << endl;
    // Fpn one = Fpn("1.0");
    // fa = fa + Fpn("1.0") ;
    // cout << fa << endl;
    // cout << Fpn::fact(Fpn("4.0")) << endl;
    // cout << Fpn::round(b) << endl;
    // cout << Fpn::round(c) << endl;
    // cout << Fpn::round(fa) << endl;

    // cout << (&fa == new Fpn("3.0")) << endl;
    // cout << (fa == Fpn("3.0")) << endl;

    // Fpn fa("200.0");
    // cout << Fpn::fact(fa) << endl;

    // Fpn f("0.0");
    // f = f/a;

    // Fpn nulla("0.0");
    // cout << (nulla<Fpn("20")) << endl;


    // for (Fpn i("0.0"); i <= Fpn("20.0") ; i = i + Fpn("1.0") ){

    //     cout << i << endl;
    //     // cout << i << "\t" << Fpn("20.0") << "\t" << (i==Fpn("20.0")) << "\t" <<  (i<Fpn("20.0")) << endl;
    //     // Fpn j("20.0");
    //     // cout << (j < Fpn("20.0")) << endl ;
    // }



    // Fpn test("100.0", 100);
    // Fpn test2("3.0", 100);
    // cout << Fpn::sin(test) << endl;
    // cout << test/test2 << endl;
 
    // Fpn x("180.0");

    // Fpn res= x; 
    // Fpn sign("1.0",10);
    // Fpn fact = sign;
    // Fpn pow = x; 

    // // cout << res << sign << fact << pow <<endl;

    // for (int i = 1; i < TAYLOR_PREC; i++) 
    // { 
    //     std::string s = std::to_string((float)i);
    //     Fpn fpni(s);
    //     // cout << i << "\t" << s <<"\t" << fpni<< endl;
    //     sign = sign * Fpn("-1.0",10); 
    //     cout << "sign\t" << sign << endl;
    //     fact = fact * ( Fpn("2.0", 10) * fpni + Fpn("1.0", 10) ) *  (Fpn("2.0", 10) * fpni ); 
    //     cout << "fact\t" << fact << endl;
    //     pow = pow * x * x; 
    //     cout << "pow\t" << pow << endl;
    //     res = res + ( pow / fact * sign); 
    //     cout << "res\t" << res << endl;
    // } 

    // cout << Fpn("5832000.0",100)/Fpn("-6.0",100) << endl;

    // Fpn asd("5832000.0",100);
    // Fpn yxc("-6.0",100);

    // cout << asd/yxc << endl;

    // Fpn p("122.00000000");
    // Fpn o("3.14", 100);
    // cout << Fpn::sin(o) << "\t" << std::sin(3.14) << endl;
    
    // cout << Fpn::sin(Fpn("2.3",100)) << "\t" << std::sin(2.3) << endl;

    // cout << "sin(3.9) \t" << Fpn::sin(Fpn("3.9",100)) << "\t" << std::sin(3.9) << endl;
    // cout << "sin(1.345) \t" << Fpn::sin(Fpn("1.345",100)) << "\t" << std::sin(1.345) << endl;
    // // cout << "sin(0.0" << Fpn::sin(Fpn("0.0",100)) << "\t" << std::sin(0.0) << endl;
    // cout << "sin(2.3) \t" << Fpn::sin(Fpn("2.3",100)) << "\t" << std::sin(2.3) << endl;
    // cout << "sin(-2.012) \t" << Fpn::sin(Fpn("-2.012",100)) << "\t" << std::sin(-2.012) << endl;
    // cout << "sin(-4.12) \t" << Fpn::sin(Fpn("-4.12",100)) << "\t" << std::sin(-4.12) << endl;
    // cout << "cos(3.14) \t" << Fpn::cos(o) << "\t" << std::cos(3.14) << endl;
    // cout << "cos(-3.24556) \t" << Fpn::cos(Fpn("-3.24556", 100)) << "\t" << std::cos(-3.24556) << endl;
    // cout << "cos(4.567) \t" << Fpn::cos(Fpn("4.567", 100)) << "\t" << std::cos(4.567) << endl;
    // cout << "cos(6.78) \t" << Fpn::cos(Fpn("6.78", 100)) << "\t" << std::cos(6.78) << endl;
    // // cout << "cos(0.0" << Fpn::cos(Fpn("0.0", 100)) << "\t" << std::cos(0.0) << endl;
    // // cout << "cos(0.7292) \t" << Fpn::cos(Fpn("0.7292", 100)) << "\t" << std::cos(0.7292) << endl;


    // cout << "sin(7.012385) \t" << "\t" << std::sin(0.7292) <<"\t" << std::sin(7.012385) << endl;
    
    // cout << "sin(7.012385) \t" << Fpn::sin(Fpn("7.012385", 100)) << "\t" << std::sin(7.012385) << endl;
    // cout << "sin(0.7292) \t" << Fpn::sin(Fpn("0.7292", 100)) << "\t" << std::sin(0.7292) << endl;

    // cout << Fpn::sin(Fpn("-0.7292", 100)) << endl; 
    // cout << std::sin(0.7292) << "\t" << Fpn::sin(Fpn("0.7292", 100)) << endl; // 0.666273
    // cout << Fpn::sin(Fpn("10.7292", 100)) << endl; // 0.666273
    cout << Fpn::sin(Fpn("-100.7292", 100)) << endl; // 0.666273
    // cout << Fpn::sin(Fpn("0.7292", 100)) << endl; // 0.666273
    // cout << Fpn::sin(Fpn("20.7292", 100)) << endl; // 0.666273
    // cout << Fpn::sin(Fpn("-20.0", 100)) << endl; // 0.666273

    // cout << Fpn("0.1096292946485810868172341248")*Fpn("0.7292") << endl;

    // cout << (fa/aa).toString() << endl;

    Fpn y("279936.0",100);
    Fpn x("5040.0",100);
    Fpn w("34.800000000",100);
    Fpn z("55.54285714285714200000",100);

    double a = 279936.0;
    double b = 5040.0;
    double c = 34.800000000;
    double d = 55.54285714285714200000;

    //y+z ok
    //z+y nem
    // cout << "z + y \t" << z << "\t" << y << endl;
    // cout << (d+a) << "\t = \t" << (z+y) <<endl;
    // cout << (d+a) << "\n" << endl;
    // cout << (z+y) <<endl;

    // cout << "(y+x)=\t" << (y+x).toString() << "\t\t" << std::setprecision(16) << (a+b) << endl;
    // cout << "(y+w)=\t" << (y+w).toString() << "\t\t" << std::setprecision(16) << (a+c) << endl;
    // cout << "(y+z)=\t" << (y+z).toString() << "\t\t" << std::setprecision(16) << (a+d) << endl;
    // cout << "(x+y)=\t" << (x+y).toString() << "\t\t" << std::setprecision(16) << (b+a) << endl;
    // cout << "(x+w)=\t" << (x+w).toString() << "\t\t" << std::setprecision(16) << (b+c) << endl;
    // cout << "(x+z)=\t" << (x+z).toString() << "\t\t" << std::setprecision(16) << (b+d) << endl;
    // cout << "(w+y)=\t" << (w+y).toString() << "\t\t" << std::setprecision(16) << (c+a) << endl;
    // cout << "(w+x)=\t" << (w+x).toString() << "\t\t" << std::setprecision(16) << (c+b) << endl;
    // cout << "(w+z)=\t" << (w+z).toString() << "\t\t" << std::setprecision(16) << (c+d) << endl;
    // cout << "(z+y)=\t" << (z+y).toString() << "\t\t" << std::setprecision(16) << (d+a) << endl;
    // cout << "(z+x)=\t" << (z+x).toString() << "\t\t" << std::setprecision(16) << (d+b) << endl;
    // cout << "(z+w)=\t" << (z+w).toString() << "\t\t" << std::setprecision(16) << (d+c) << endl;

    // cout << endl;

    // cout << "(y-x)=\t" << (y-x).toString() << "\t\t" << std::setprecision(16) << (a-b) << endl;
    // cout << "(y-w)=\t" << (y-w).toString() << "\t\t" << std::setprecision(16) << (a-c) << endl;
    // cout << "(y-z)=\t" << (y-z).toString() << "\t\t" << std::setprecision(16) << (a-d) << endl;
    // cout << "(x-y)=\t" << (x-y).toString() << "\t\t" << std::setprecision(16) << (b-a) << endl;
    // cout << "(x-w)=\t" << (x-w).toString() << "\t\t" << std::setprecision(16) << (b-c) << endl;
    // cout << "(x-z)=\t" << (x-z).toString() << "\t\t" << std::setprecision(16) << (b-d) << endl;
    // cout << "(w-y)=\t" << (w-y).toString() << "\t\t" << std::setprecision(16) << (c-a) << endl;
    // cout << "(w-x)=\t" << (w-x).toString() << "\t\t" << std::setprecision(16) << (c-b) << endl;
    // cout << "(w-z)=\t" << (w-z).toString() << "\t\t" << std::setprecision(16) << (c-d) << endl;
    // cout << "(z-y)=\t" << (z-y).toString() << "\t\t" << std::setprecision(16) << (d-a) << endl;
    // cout << "(z-x)=\t" << (z-x).toString() << "\t\t" << std::setprecision(16) << (d-b) << endl;
    // cout << "(z-w)=\t" << (z-w).toString() << "\t\t" << std::setprecision(16) << (d-c) << endl;

    // cout << endl;

    // cout << "(y*x)=\t" << (y*x).toString() << "\t\t" << std::setprecision(16) << (a*b) << endl;
    // cout << "(y*w)=\t" << (y*w).toString() << "\t\t" << std::setprecision(16) << (a*c) << endl;
    // cout << "(y*z)=\t" << (y*z).toString() << "\t\t" << std::setprecision(16) << (a*d) << endl;
    // cout << "(x*y)=\t" << (x*y).toString() << "\t\t" << std::setprecision(16) << (b*a) << endl;
    // cout << "(x*w)=\t" << (x*w).toString() << "\t\t" << std::setprecision(16) << (b*c) << endl;
    // cout << "(x*z)=\t" << (x*z).toString() << "\t\t" << std::setprecision(16) << (b*d) << endl;
    // cout << "(w*y)=\t" << (w*y).toString() << "\t\t" << std::setprecision(16) << (c*a) << endl;
    // cout << "(w*x)=\t" << (w*x).toString() << "\t\t" << std::setprecision(16) << (c*b) << endl;
    // cout << "(w*z)=\t" << (w*z).toString() << "\t\t" << std::setprecision(16) << (c*d) << endl;
    // cout << "(z*y)=\t" << (z*y).toString() << "\t\t" << std::setprecision(16) << (d*a) << endl;
    // cout << "(z*x)=\t" << (z*x).toString() << "\t\t" << std::setprecision(16) << (d*b) << endl;
    // cout << "(z*w)=\t" << (z*w).toString() << "\t\t" << std::setprecision(16) << (d*c) << endl;

    // cout << endl;

    // cout << "(y/x)=\t" << (y/x).toString() << "\t\t" << std::setprecision(16) << (a/b) << endl;
    // cout << "(y/w)=\t" << (y/w).toString() << "\t\t" << std::setprecision(16) << (a/c) << endl;
    // cout << "(y/z)=\t" << (y/z).toString() << "\t\t" << std::setprecision(16) << (a/d) << endl;
    // cout << "(x/y)=\t" << (x/y).toString() << "\t\t" << std::setprecision(16) << (b/a) << endl;
    // cout << "(x/w)=\t" << (x/w).toString() << "\t\t" << std::setprecision(16) << (b/c) << endl;
    // cout << "(x/z)=\t" << (x/z).toString() << "\t\t" << std::setprecision(16) << (b/d) << endl;
    // cout << "(w/y)=\t" << (w/y).toString() << "\t\t" << std::setprecision(16) << (c/a) << endl;
    // cout << "(w/x)=\t" << (w/x).toString() << "\t\t" << std::setprecision(16) << (c/b) << endl;
    // cout << "(w/z)=\t" << (w/z).toString() << "\t\t" << std::setprecision(16) << (c/d) << endl;
    // cout << "(z/y)=\t" << (z/y).toString() << "\t\t" << std::setprecision(16) << (d/a) << endl;
    // cout << "(z/x)=\t" << (z/x).toString() << "\t\t" << std::setprecision(16) << (d/b) << endl;
    // cout << "(z/w)=\t" << (z/w).toString() << "\t\t" << std::setprecision(16) << (d/c) << endl;

    // cout << Fpn("-1234.51283745623847236847384652387654823764872364827364283756248756248756283765236")/Fpn("7.890005348756348765348765823765139485739847539847594827539847593847593847598343475634875601") << endl;
    // cout << (188.9568/0.120) << "\t" << Fpn("+188.9568")/Fpn("+0.120") << endl;
    // cout << (188.01*1.0/2.01) << "\t" << Fpn("+188.01")* Fpn("1.0") /Fpn("+2.01") << endl;
    // cout << Fpn("+12.0")/Fpn("1.1") << endl;

    // string number = "123.0";
    // string divisor = "25.0000000000";

    // int numPrec = number.substr(number.find("."), number.size() ).size();
    // int divPrec = divisor.substr(divisor.find("."), divisor.size() ).size();

    // cout << numPrec << "\t" << number.find(".") << "\t" << number.size() << "\t" << number.substr(number.find("."), number.size() ) << endl;
    // cout << divPrec << "\t" << divisor.find(".") << "\t" << divisor.size() << "\t" << divisor.substr(divisor.find("."), divisor.size() ) << endl;


    // cout << Fpn("0.0")/Fpn("+1.0") << "\t\t" << std::setprecision(16) << (188.9568/0.120) << endl;
    // cout << Fpn("0.000000000000000100")/Fpn("+0.0") << endl;
    // cout << 1/0 << endl;

    // cout << (188.9568/0.120) << "\n" << Fpn("+188.9568")/Fpn("+0.120") << endl;
    // cout << (188.9568/0.34420) << "\n" << Fpn("+188.9568")/Fpn("+0.34420") << endl;

    // cout << std::sin(2.3) << endl;
    // cout << Fpn::sin(Fpn("2.3",100)) << endl;

    // cout << (64.3634/120) << endl;
    // cout << Fpn("-0.27") - (Fpn("64.3634")/Fpn("120.0")) << endl;
    // cout << Fpn("+0.536361916666666666666666666666666666666666666666") - Fpn("-0.27216666666666666666666666666666666666666") << endl;
    
    // cout << Fpn::sqrt(Fpn("9999.22",100)) << "\t" << std::sqrt(9999.22) << endl;
    // cout << Fpn::sqrt(Fpn("16.7",100))/Fpn("10.0") << "\t" << std::sqrt(0.167) << endl;
    // cout << Fpn::sqrt(Fpn("26.7",100))/Fpn("10.0") << "\t" << std::sqrt(0.267) << endl;
    // cout << Fpn::sqrt(Fpn("36.7",100))/Fpn("10.0") << "\t" << std::sqrt(0.367) << endl;
    // cout << Fpn::sqrt(Fpn("46.7",100))/Fpn("10.0") << "\t" << std::sqrt(0.467) << endl;
    // cout << Fpn::sqrt(Fpn("56.7",100))/Fpn("10.0") << "\t" << std::sqrt(0.567) << endl;
    // cout << Fpn::sqrt(Fpn("66.7",100))/Fpn("10.0") << "\t" << std::sqrt(0.667) << endl;
    // cout << Fpn::sqrt(Fpn("76.7",100))/Fpn("10.0") << "\t" << std::sqrt(0.767) << endl;
    // cout << Fpn::sqrt(Fpn("86.7",100))/Fpn("10.0") << "\t" << std::sqrt(0.867) << endl;
    // cout << Fpn::sqrt(Fpn("96.7",100))/Fpn("10.0") << "\t" << std::sqrt(0.967) << endl;
    // cout << Fpn::sqrt(Fpn("0.36000",100)) << "\t" << std::sqrt(0.36) << endl;
    // cout << Fpn::sqrt(Fpn("0.12200",100)) << "\t" << std::sqrt(0.122) << endl;
    // cout << Fpn::sqrt(Fpn("0.168",100)) << "\t" << std::sqrt(0.168) << endl;
    // cout << Fpn::sqrt(Fpn("0.1689",100)) << "\t" << std::sqrt(0.1689) << endl;
    // cout << Fpn::sqrt(Fpn("0.16",100)) << "\t" << std::sqrt(0.16) << endl;
    // cout << Fpn::sqrt(Fpn("0.016",100)) << "\t" << std::sqrt(0.016) << endl;
    // cout << Fpn::sqrt(Fpn("0.0016",100)) << "\t" << std::sqrt(0.0016) << endl;
    // cout << Fpn::sqrt(Fpn("0.00016",100)) << "\t" << std::sqrt(0.00016) << endl;
    // cout << Fpn::sqrt(Fpn("0.000016",100)) << "\t" << std::sqrt(0.000016) << endl;
    // cout << Fpn::sqrt(Fpn("0.0000016",100)) << "\t" << std::sqrt(0.0000016) << endl;
    // cout << Fpn::sqrt(Fpn("0.00000016",100)) << "\t" << std::sqrt(0.00000016) << endl;
    // cout << Fpn::sqrt(Fpn("0.000000016",100)) << "\t" << std::sqrt(0.000000016) << endl;
    // cout << Fpn::sqrt(Fpn("0.0000000016",100)) << "\t" << std::sqrt(0.0000000016) << endl;
    // cout << Fpn::sqrt(Fpn("0.122",100)) << "\t" << std::sqrt(0.122) << endl;
    // cout << Fpn::sqrt(Fpn("0.0122",100)) << "\t" << std::sqrt(0.0122) << endl;
    // cout << Fpn::sqrt(Fpn("0.00122",100)) << "\t" << std::sqrt(0.00122) << endl;
    // cout << Fpn::sqrt(Fpn("0.000122",100)) << "\t" << std::sqrt(0.000122) << endl;
    // cout << Fpn::sqrt(Fpn("0.0000122",100)) << "\t" << std::sqrt(0.0000122) << endl;
    // cout << Fpn::sqrt(Fpn("0.00000122",100)) << "\t" << std::sqrt(0.00000122) << endl;
    // cout << Fpn::sqrt(Fpn("0.000000122",100)) << "\t" << std::sqrt(0.000000122) << endl;
    // cout << Fpn::sqrt(Fpn("0.0000000122",100)) << "\t" << std::sqrt(0.0000000122) << endl;
    // cout << Fpn::sqrt(Fpn("0.00000000122",100)) << "\t" << std::sqrt(0.00000000122) << endl;
    // cout << Fpn::sqrt(Fpn("1234.5678",100)) << "\t" << std::sqrt(1234.5678) << endl;
    // cout << Fpn::sqrt(Fpn("1.111111111",100)) << "\t" << std::sqrt(1.111111111) << endl;

    // cout << "-2.0278333333333333333333333333333333333333333333 + 2.3 =" << Fpn("-2.0278333333333333333333333333333333333333333333")+Fpn("2.3") << endl;

    return 0;
}