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
    Fpn fa("3.0");
    

    Fpn r("-1234.51283745623847236847384652387654823764872364827364283756248756248756283765236");
    Fpn q("7.890005348756348765348765823765139485739847539847594827539847593847593847598343475634875601");

    double i = -22.9911;
    double j = 3333.111189;
    double k = -123.234;
    double l = 0.456;
    double m = 0.111111;

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
    fa= fa + Fpn("1.0") ;
    cout << fa << endl;
    // cout << Fpn::fact(Fpn("4.0")) << endl;
    // cout << Fpn::round(b) << endl;
    // cout << Fpn::round(c) << endl;
    // cout << Fpn::round(fa) << endl;

    // cout << (&fa == new Fpn("3.0")) << endl;
    // cout << (fa == Fpn("3.0")) << endl;
    
    
   


    return 0;
}
