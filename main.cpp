#include <iostream>
#include <iomanip>
#include <math.h> 
#include <cmath> 

#include "Fpn.hpp"

using namespace std;

int main(int argc, char* argv[]){

    if (argc == 2){
        try
		{
            //char* -> double && double -> string -> Fpn
            double d1 = (double)strtod(argv[1],NULL);
            Fpn f1(std::to_string((double)d1),100);

			if (d1>0) cout << d1 << ";" << f1 << ";sqrt(" << d1 << ");" << std::sqrt(d1) << ";" << Fpn::sqrt(f1) << ";" << endl;
			// // // cout << d1 << ";" << f1 << ";pow(" << d1 << ");" << std::pow(d1) << ";" << Fpn::pow(f1) << ";" << endl;
			cout << d1 << ";" << f1 << ";abs(" << d1 << ");" << std::abs(d1) << ";" << Fpn::abs(f1) << ";" << endl;
			cout << d1 << ";" << f1 << ";round(" << d1 << ");" << std::round(d1) << ";" << Fpn::round(f1) << ";" << endl;
			cout << d1 << ";" << f1 << ";sin(" << d1 << ");" << std::sin(d1) << ";" << Fpn::sin(f1) << ";" << endl;
			cout << d1 << ";" << f1 << ";cos(" << d1 << ");" << std::cos(d1) << ";" << Fpn::cos(f1) << ";" << endl;
		}
		catch(std::string e)
		{
			std::cout << e;
		}
    }
	else if (argc == 3){
        try
		{
            //char* -> double && double -> string -> Fpn
            double d1 = (double)strtod(argv[1],NULL);
            double d2 = (double)strtod(argv[2],NULL);
            Fpn f1(std::to_string((double)d1),100);
            Fpn f2(std::to_string((double)d2),100);

			cout << d1 << ";" << d2 << ";" << f1 << ";" << f2 << ";(" << d1 << "+" << d2 << ");" << (d1+d2) << ";" << (f1+f2) << ";" << endl;
			cout << d1 << ";" << d2 << ";" << f1 << ";" << f2 << ";(" << d1 << "-" << d2 << ");" << (d1-d2) << ";" << (f1-f2) << ";" << endl;
			cout << d1 << ";" << d2 << ";" << f1 << ";" << f2 << ";(" << d1 << "*" << d2 << ");" << (d1*d2) << ";" << (f1*f2) << ";" << endl;
			cout << d1 << ";" << d2 << ";" << f1 << ";" << f2 << ";(" << d1 << "/" << d2 << ");" << (d1/d2) << ";" << (f1/f2) << ";" << endl;
			cout << d1 << ";" << d2 << ";" << f1 << ";" << f2 << ";(" << d1 << "==" << d2 << ");" << (d1==d2) << ";" << (f1==f2) << ";" << endl;
			cout << d1 << ";" << d2 << ";" << f1 << ";" << f2 << ";(" << d1 << "!=" << d2 << ");" << (d1!=d2) << ";" << (f1!=f2) << ";" << endl;
			cout << d1 << ";" << d2 << ";" << f1 << ";" << f2 << ";(" << d1 << "<" << d2 << ");" << (d1<d2) << ";" << (f1<f2) << ";" << endl;
			cout << d1 << ";" << d2 << ";" << f1 << ";" << f2 << ";(" << d1 << "<=" << d2 << ");" << (d1<=d2) << ";" << (f1<=f2) << ";" << endl;
			cout << d1 << ";" << d2 << ";" << f1 << ";" << f2 << ";(" << d1 << ">" << d2 << ");" << (d1>d2) << ";" << (f1>f2) << ";" << endl;
			cout << d1 << ";" << d2 << ";" << f1 << ";" << f2 << ";(" << d1 << ">=" << d2 << ");" << (d1>=d2) << ";" << (f1>=f2) << ";" << endl;
		}
		catch(std::string e)
		{
			std::cout << e;
		}
    }
    

	else{
		std::cout << "Incorrect number of parameters!";
    }

    return 0;
}