#include <iostream>
#include <iomanip>
#include <math.h> 

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
    Fpn o("3.14", 100);
    cout << Fpn::sin(o) << "\t" << std::sin(3.14) << endl;
    cout << Fpn::sin(Fpn("2.0")) << "\t" << std::sin(2.0) << endl;
    cout << Fpn::sin(Fpn("3.9")) << "\t" << std::sin(3.9) << endl;
    cout << Fpn::sin(Fpn("1.345")) << "\t" << std::sin(1.345) << endl;
    cout << Fpn::sin(Fpn("2.345")) << "\t" << std::sin(2.345) << endl;
    cout << Fpn::sin(Fpn("-2.012")) << "\t" << std::sin(-2.012) << endl;
    cout << Fpn::sin(Fpn("-4.12")) << "\t" << std::sin(-4.12) << endl;
    // cout << Fpn::cos(o) << "\t" << std::cos(3.14) << endl;

    // cout << Fpn("216.0")/Fpn("6.0") << endl;

    // cout << (fa/aa).toString() << endl;

    // Fpn y("279936.0",100);
    // Fpn x("5040.0",100);
    // Fpn w("34.800000000",100);
    // Fpn z("55.54285714285714200000",100);

    // double a = 279936.0;
    // double b = 5040.0;
    // double c = 34.800000000;
    // double d = 55.54285714285714200000;

    // cout << (y-x).toString() << "\t" << (a-b) << endl;
    // cout << (y-w).toString() << "\t" << (a-c) << endl;
    // cout << (y-z).toString() << "\t" << (a-d) << endl;
    // cout << (x-y).toString() << "\t" << (b-a) << endl;
    // cout << (x-w).toString() << "\t" << (b-c) << endl;
    // cout << (x-z).toString() << "\t" << (b-d) << endl;
    // cout << (w-y).toString() << "\t" << (c-a) << endl;
    // cout << (w-x).toString() << "\t" << (c-b) << endl;
    // cout << (w-z).toString() << "\t" << (c-d) << endl;
    // cout << (z-y).toString() << "\t" << (d-a) << endl;
    // cout << (z-x).toString() << "\t" << (d-b) << endl;
    // cout << (z-w).toString() << "\t" << (d-c) << endl;

    // double a = 279936.0;
    // double b = 5040.0;
    // double c = 34.800000000;
    // double d = 55.54285714285714200000;

    // cout << (a-b) << endl;
    // cout << (a-c) << endl;
    // cout << (a-d) << endl;
    // cout << (b-a) << endl;
    // cout << (b-c) << endl;
    // cout << (b-d) << endl;
    // cout << (c-a) << endl;
    // cout << (c-b) << endl;
    // cout << (c-d) << endl;
    // cout << (d-a) << endl;
    // cout << (d-b) << endl;
    // cout << (d-c) << endl;

    // cout << Fpn("-1234.51283745623847236847384652387654823764872364827364283756248756248756283765236")/Fpn("7.890005348756348765348765823765139485739847539847594827539847593847593847598343475634875601") << endl;
    // cout << Fpn("+188.9568")/Fpn("+0.120") << endl;
    // cout << Fpn("+188.01")* Fpn("1.0") /Fpn("+2.01") << endl;
    // cout << Fpn("+12.0")/Fpn("1.1") << endl;

    // string number = "123.0";
    // string divisor = "25.0000000000";

    // int numPrec = number.substr(number.find("."), number.size() ).size();
    // int divPrec = divisor.substr(divisor.find("."), divisor.size() ).size();

    // cout << numPrec << "\t" << number.find(".") << "\t" << number.size() << "\t" << number.substr(number.find("."), number.size() ) << endl;
    // cout << divPrec << "\t" << divisor.find(".") << "\t" << divisor.size() << "\t" << divisor.substr(divisor.find("."), divisor.size() ) << endl;



    return 0;
}