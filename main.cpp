#include <iostream>
#include <iomanip>

#include "Fpn.hpp"

using namespace std;

int main(){

    Fpn a("-22.9911");
    Fpn aa("-22.9911");
    Fpn b("3333.111189");
    Fpn c("-123.234");
    Fpn d("0.456");
    Fpn e("0.111111");

    Fpn fa("200.0");

    Fpn r("-1234.51283745623847236847384652387654823764872364827364283756248756248756283765236");
    Fpn q("7.890005348756348765348765823765139485739847539847594827539847593847593847598343475634875601");

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

    // Fpn res(x); 
    // Fpn sign("1.0",100);
    // Fpn fact = sign;
    // Fpn pow = x; 

    // // cout << res << sign << fact << pow <<endl;

    // for (int i = 1; i < TAYLOR_PREC; i++) 
    // { 
    //     std::string s = std::to_string((float)i);
    //     Fpn fpni(s);
    //     // cout << i << "\t" << s <<"\t" << fpni<< endl;
    //     sign = sign * Fpn("-1.0",100); 
    //     cout << "sign\t" << sign << endl;
    //     fact = fact * ( Fpn("2.0", 100) * fpni + Fpn("1.0", 100) ) *  (Fpn("2.0", 100) * fpni ); 
    //     cout << "fact\t" << fact << endl;
    //     pow = pow * x * x; 
    //     cout << "pow\t" << pow << endl;
    //     res = res + ( pow / fact * sign); 
    //     cout << "res\t" << res << endl;
    // } 

    Fpn p("122.00000000");
    Fpn o("6.000");
    // cout << Fpn::sin(o) << endl;

    cout << (fa/aa).toString() << endl;

    // Fpn y("+188956800000.01",10);
    // Fpn x("+120.01",10);
    // Fpn z = y/x;

    // cout << z.toString() << endl;

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