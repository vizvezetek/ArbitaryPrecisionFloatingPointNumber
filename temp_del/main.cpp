#include <iostream>
#include <iomanip>
#include <math.h> 
#include <cmath> 

#include "Fpn.hpp"

using namespace std;

float drop_wawe (float x1, float x2) { //  (0,0) glob_min: -1
    return 
        -(
            1 + cos( 12*sqrt( pow(x1,2)+pow(x2,2) ) )
        )
        /
        (
            0.5* ( pow(x1,2)+pow(x2,2) ) +2
        )
    ;
}

Fpn FPN_drop_wawe (Fpn x1, Fpn x2) { //  (0,0) glob_min: -1
    
	Fpn part1 = Fpn("-1.0")*( Fpn("1.0") + Fpn::cos( Fpn("12.0")* Fpn::sqrt( (x1*x1)+(x2*x2) ) ) );
	Fpn part2 = (Fpn("0.5")* ( (x1*x1)+(x2*x2) )  + Fpn("2.0"));
	
	return (part1/part2);
}


int main(int argc, char* argv[]){

	cout << drop_wawe(0.000011920998076675,0.000000000108775197) << endl;
	cout << FPN_drop_wawe( Fpn("0.000011920998076675"),Fpn("0.000000000108775197") ) << endl;

    return 0;
}