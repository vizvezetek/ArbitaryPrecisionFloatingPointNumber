/**
 * \class Fpn
 * 
 * \file Fpn.cpp
 * 
 * \note This is an arbitary precision floating point arithmetic. The actual under development version is available at: https://github.com/vizvezetek/ArbitaryPrecisionFloatingPointNumber
 * 
 * It includes the main operators(+,-,*,/,=,<,>, etc.) in functions, and basic trigonometrical operations.
 * In this case, because of my tests I temporary fixed the floating precision in 100 elements. The reason is to reduce the runtime at the bigger and complicated calculations. 
 * 
 * \author Koncz Péter (kope)
 * 
 * \version 6.9
 * 
 * \date 2020/11/25 22:07
*/


#include "Fpn.hpp"

//*******************************************************************************************************************************
//public functions
//*******************************************************************************************************************************

//initialization list constructor
// Fpn::Fpn(char sign_, const string number_, int fractPrecision_ ): sign (sign_), number(number_), fractPrecision(fractPrecision_){}

Fpn::Fpn(): sign('+'), number("0.0"), intPart("0"), fractPart("0"){}

Fpn::Fpn(const Fpn& f): sign(f.sign), number(f.number), intPart(f.intPart), fractPart(f.fractPart){}
Fpn::Fpn(Fpn& f): sign(f.getSign()), number(f.getNumber()), intPart(f.getIntPart()), fractPart(f.getFractPart()){}

// [+-]?([0-9]*[.])?[0-9]+
Fpn::Fpn(const std::string number_){
 

    if(number_[0]=='+'){
        sign = '+';
        number = number_.substr( 1, (int)number_.size() );
    }
    else if (number_[0]=='-'){
        sign = '-';
        number = number_.substr(1, (int)number_.size() );
    }
    else{
        sign = '+';
        number = number_;
    }

    bool floatingpoint = false;
    for (int i = 0; i< number.size(); i++){

        if (number[i] == '.' || number[i] == ','){
            number[i] = '.';
            // intPrecision = i;
            // fractPrecision = number.size()-i-1;
            fractPrecision = fixedPrec; //ezt így nem szabadna...
            floatingpoint = true;
            continue; //because of the floating point
        }
        
        if (!floatingpoint){
            intPart+=number[i];
        }
        else{
            fractPart+=number[i];
        }
    }
    fractPart = removeZerosTheEndOfTheString(fractPart);

    // fractPrecision = 100;
}

Fpn::Fpn(const std::string number_, const int fractPrecision_){
 
    fractPrecision = fractPrecision_;

    if(number_[0]=='+'){
        sign = '+';
        number = number_.substr( 1, (int)number_.size() );
    }
    else if (number_[0]=='-'){
        sign = '-';
        number = number_.substr(1, (int)number_.size() );
    }
    else{
        sign = '+';
        number = number_;
    }

    bool floatingpoint = false;
    for (int i = 0; i< number.size(); i++){

        if (number[i] == '.' || number[i] == ','){
            number[i] = '.';
            // intPrecision = i;
            // fractPrecision = number.size()-i-1;
            floatingpoint = true;
            continue; //because of the floating point
        }
        
        if (!floatingpoint){
            intPart+=number[i];
        }
        else if ( fractPart.size() <= fractPrecision ){
            fractPart+=number[i];
        }
    }
    fractPart = removeZerosTheEndOfTheString(fractPart);
}


//getters

const char Fpn::getSign(){
    return sign;
}

const std::string Fpn::getNumber(){
    return intPart + '.' + fractPart;
}

const std::string Fpn::getIntPart(){
    return intPart;
}

const std::string Fpn::getFractPart(){
    return fractPart;
}

const int Fpn::getIntPrecision(){
    return intPart.size();
}

const int Fpn::getFractPrecision(){
    //the minimum precision is 100 digits
    return (fractPrecision < 100 ) ? 100 : fractPrecision;
}

std::string Fpn::toString(){
    return sign + intPart + '.' + removeZerosTheEndOfTheString(fractPart);
}

std::ostream& operator<<(std::ostream &strm, const Fpn &a) {
//   return strm << a.sign << a.intPart << '.' <<a.fractPart;
  return strm << a.sign << a.intPart << '.' << a.fractPart;

}

//setters

void Fpn::setSign(const char sign_){
    sign = sign_;
}

void Fpn::setNumber(const std::string number_){
    number = number_;
}

void Fpn::setIntPart(const std::string intPart_){
    if (intPart_.size()==0){
        intPart = "0";
    }
    else{
        intPart = intPart_;
    }
}

void Fpn::setFractPart(const std::string fractPart_){
    //cut the fract part at the precision
    if (fractPart_.size() >= fractPrecision && fractPrecision < 100){
        fractPart = fractPart_.substr(0, 100);
    }
    else if (fractPart_.size() >= fractPrecision && fractPrecision > 100){
        fractPart = fractPart_.substr(0, fractPrecision);
    }
    else{
        fractPart = removeZerosTheEndOfTheString(fractPart_);
    }
}

void Fpn::setFractPrecision(const int fractPrecision_){
    if (fractPrecision_ <= 100){
        fractPrecision = 100;
    }
    else{
        fractPrecision = fractPrecision_;
    }
}


//operators

Fpn& Fpn::operator = ( const Fpn& obj){
    if (this != &obj){
        sign = obj.sign;
        number = obj.sign + obj.intPart + "." +obj.fractPart;
        intPart = (obj.intPart.size()==0) ? "0" : obj.intPart;
        fractPart = obj.fractPart;
        fractPrecision = obj.fractPrecision;
    }
    return *this;
}

bool Fpn::operator == (const Fpn& obj2) const{

    return (sign == obj2.sign  && intPart == obj2.intPart && fractPart == obj2.fractPart) ? true : false ;
}

bool operator != (Fpn &obj1, Fpn &obj2){
    return !(obj1==obj2);
}

bool operator < (Fpn &obj1, Fpn &obj2){

    if (obj1 == obj2){
        return false;
    }
    
    //sign
    if (obj1.getSign() == '+' && obj2.getSign() == '-'){
        return false;
    }
    else if (obj1.getSign() == '-' && obj2.getSign() == '+'){
        return true;
    }

    else if (obj1.getSign() == '+' && obj2.getSign() == '+'){

        //int part equal
        if (obj1.getIntPart().length() == obj2.getIntPart().length() && obj1.getIntPart() < obj2.getIntPart()){
            return true;
        }
        else if (obj1.getIntPart().length() == obj2.getIntPart().length() && obj1.getIntPart() > obj2.getIntPart()){
            return false;
        }
        // int part size diff
        if (obj1.getIntPart().length() < obj2.getIntPart().length() ){
            return true;
        }
        else if (obj1.getIntPart().length() > obj2.getIntPart().length() ){
            return false;
        }
        // int equal but fract not
        if (obj1.getIntPart() == obj2.getIntPart() && obj1.getFractPart() < obj2.getFractPart() ){
            return true;
        }
        else if (obj1.getIntPart() == obj2.getIntPart() && obj1.getFractPart() > obj2.getFractPart() ){
            return false;
        }
        
    }
    else if (obj1.getSign() == '-' && obj2.getSign() == '-'){
        //int part equal
        if (obj1.getIntPart().length() == obj2.getIntPart().length() && obj1.getIntPart() < obj2.getIntPart()){
            return false;
        }
        else if (obj1.getIntPart().length() == obj2.getIntPart().length() && obj1.getIntPart() > obj2.getIntPart()){
            return true;
        }
        // int part size diff
        if (obj1.getIntPart().length() < obj2.getIntPart().length() ){
            return false;
        }
        else if (obj1.getIntPart().length() > obj2.getIntPart().length() ){
            return true;
        }
        // int equal but fract not
        if (obj1.getIntPart() == obj2.getIntPart() && obj1.getFractPart() < obj2.getFractPart() ){
            return false;
        }
        else if (obj1.getIntPart() == obj2.getIntPart() && obj1.getFractPart() > obj2.getFractPart() ){
            return true;
        }
    }

    //fract part
    return true;
}

bool Fpn::operator < (const Fpn& obj2) const{

    // Fpn obj1(number);
    // Fpn obj2(obj);

    if (sign == obj2.sign  && intPart == obj2.intPart && fractPart == obj2.fractPart){
        return false;
    }
    
    //sign
    if (sign == '+' && obj2.sign == '-'){
        return false;
    }
    else if (sign == '-' && obj2.sign == '+'){
        return true;
    }

    else if (sign == '+' && obj2.sign == '+'){

        //int part equal
        if (intPart.length() == obj2.intPart.length() && intPart < obj2.intPart){
            return true;
        }
        else if (intPart.length() == obj2.intPart.length() && intPart > obj2.intPart){
            return false;
        }
        // int part size diff
        if (intPart.length() < obj2.intPart.length() ){
            return true;
        }
        else if (intPart.length() > obj2.intPart.length() ){
            return false;
        }
        // int equal but fract not
        if (intPart == obj2.intPart && fractPart < obj2.fractPart ){
            return true;
        }
        else if (intPart == obj2.intPart && fractPart > obj2.fractPart ){
            return false;
        }
        
    }
    else if (sign == '-' && obj2.sign == '-'){
        //int part equal
        if (intPart.length() == obj2.intPart.length() && intPart < obj2.intPart){
            return false;
        }
        else if (intPart.length() == obj2.intPart.length() && intPart > obj2.intPart){
            return true;
        }
        // int part size diff
        if (intPart.length() < obj2.intPart.length() ){
            return false;
        }
        else if (intPart.length() > obj2.intPart.length() ){
            return true;
        }
        // int equal but fract not
        if (intPart == obj2.intPart && fractPart < obj2.fractPart ){
            return false;
        }
        else if (intPart == obj2.intPart && fractPart > obj2.fractPart ){
            return true;
        }
    }
    // fract part
    return true;
}

bool operator > (Fpn &obj1, Fpn &obj2){
    return obj2 < obj1;
}

bool Fpn::operator > (const Fpn& obj2) const{
    return obj2 < *this; 
}

bool operator <= (Fpn &obj1, Fpn &obj2){
    return obj1==obj2 || obj1<obj2;
}

bool Fpn::operator <= (const Fpn& obj2) const{
    return *this==obj2 || *this<obj2;
}

bool operator >= (Fpn &obj1, Fpn &obj2){
    return obj1==obj2 || obj1>obj2;
}

bool Fpn::operator >= (const Fpn& obj2) const{
    return *this==obj2 || *this>obj2;
}

Fpn Fpn::operator + (const Fpn& obj) {

    Fpn temp(this->toString());

    return addFpns(temp, obj) ; 
}

Fpn Fpn::operator - (const Fpn& obj) { 
    Fpn f1(this->toString());
    Fpn f2(obj);
    char s1 = sign;
    char s2 = f2.getSign();

    // --- => -++
    if (s1=='-' && s2=='-'){
        f2.setSign('+');
        return addFpns(f1, f2);
    }
    // --+ => -+-
    else if (s1=='-' && s2=='+'){
        f2.setSign('-');
        return addFpns(f1, f2);
    }
    // +-- => +++
    else if (s1=='+' && s2=='-'){
        f2.setSign('+');
        return addFpns(f1, f2);
    }
    // +-+ => ++-
    // if (s1=='+' && s2=='+'){  //because of the warning handling. 
    else {
        f2.setSign('-');
        return addFpns(f1, f2);
    }
}

Fpn Fpn::operator * (const Fpn& f2){
    Fpn f1(this->toString());

    int f1zeros = 0;
    int f2zeros = 0;

    std::string temp = "";

    if (f1.getIntPart() == "0"){
        f1zeros ++;
        //count f1 appendable zeros to the begin of the temp string. If it wouldn't calc, then the string(at the point insert) going to be out of the string range.
        for(int i = 0 ; f1.getFractPart()[i] == '0'; i++) {f1zeros++;}
        temp.append(f1zeros, '0');
    }
    if (f2.intPart == "0"){
        f2zeros ++;
        //count f2 appendable zeros to the begin of the temp string. If it wouldn't calc, then the string(at the point insert) going to be out of the string range.
        for(int i = 0 ; f2.fractPart[i] == '0'; i++) {f2zeros++;}
        temp.append(f2zeros, '0');
    }

    temp.append( multiplyIntAsString( f1.getIntPart()+f1.getFractPart() , f2.intPart+f2.fractPart ));
    

    //set the floating point to the right position

    temp.insert(temp.end()-(f1.getFractPart().size() + f2.fractPart.size() ) , '.');
    Fpn out(temp);

    //set the sign
    if ( (f1.getSign() == '-' && f2.sign == '-') || (f1.getSign() == '+' && f2.sign == '+') ){
        out.setSign('+');
    }
    else {
        out.setSign('-');
    }

    if (out.getIntPart().size() == 0){
        out.setIntPart("0");
    }

    // fract precision cut
    if (out.getFractPart().size() > out.getFractPrecision() && out.getFractPart().size() > 100){
        out.setFractPart( out.getFractPart().substr( 0, out.getFractPrecision() ) );
    }

    //remove zeros the begin of the int part. Example 00.123 -> 0.123
    out.setIntPart( removeZerosTheBeginOfTheString( out.getIntPart() ) ) ;

    return out;
}

Fpn Fpn::operator / (const Fpn& f2){
    Fpn f1(this->toString());
    Fpn f3(f2.number);

    Fpn out( divideIntsAsString( f1.getNumber(), f3.getNumber() , f1.getFractPrecision()>f3.getFractPrecision() ? f1.getFractPrecision() : f3.getFractPrecision() ) );

    // example 234.567 / 89.01 
    
    // set the sign 
    if ( (f1.getSign() == '-' && f3.getSign() == '-') || (f1.getSign() == '+' && f3.getSign() == '+') ){
        out.setSign('+');
    }
    else {
        out.setSign('-');
    }

    return out;
}

Fpn Fpn::operator / (Fpn &f2){
    Fpn f1(this->toString());

    Fpn out( divideIntsAsString( this->getNumber(), f2.getNumber() , f1.getFractPrecision()>f2.getFractPrecision() ? f1.getFractPrecision() : f2.getFractPrecision() ) );

    // example 234.567 / 89.01 
    
    // set the sign 
    if ( (f1.getSign() == '-' && f2.getSign() == '-') || (f1.getSign() == '+' && f2.getSign() == '+') ){
        out.setSign('+');
    }
    else {
        out.setSign('-');
    }

    return out;
}

//FPN.math

Fpn Fpn::abs(Fpn obj){
    if (obj.getSign() == '-'){
        obj.setSign('+');
        return obj;
    }
    return obj;
}

Fpn Fpn::round(Fpn obj){
    if ( obj.getFractPart()[0] >= '5'){
        Fpn one = Fpn("1.0");
        obj.setFractPart("0");
        if (obj.sign == '-'){
            obj = obj - one;
        }
        else if (obj.sign == '+'){
            obj = obj + one;
        }
        return obj;
    }
    if (obj.getFractPart()[0] <= '4'){
        obj.setFractPart("0");
        return obj;
    }
}

Fpn Fpn::fact(Fpn obj){
    Fpn zero("0.0");
    Fpn one("+1.0");
    // return (&obj == &zero) ? &one : (&obj * &Fpn::fact( (&obj - &one) ));
    // return (obj == Fpn("0.0")) ? Fpn("1.0") : (Fpn::fact( (obj - one) ) * obj );
    if (obj == zero){
        return Fpn("1.0");
    }
    else{
        Fpn retval("1.0");
        while (! (obj == Fpn("+1.0"))){
            retval = retval * obj;
            obj = obj + Fpn("-1");
        }
        return retval;
    }
}


Fpn Fpn::sin(Fpn x) 
{ 
    Fpn res(x); 

    //convert the number X to an equal value with the 2pi period
    if (res > Fpn("0.0") && res>Fpn(doublesPi) ){
        while (res > Fpn(doublesPi) ){
            res = res -Fpn(doublesPi);
        }
    }
    else if (res < Fpn("0.0") ){
        while (res < Fpn(doublesPi) ){
            res = res + Fpn(doublesPi);
        }
    }
    else if (res == Fpn("0.0")){
        return Fpn("0.0");
    }

    return sinTaylorSum(res);

} 

Fpn Fpn::sinTaylorSum(Fpn x) 
{ 
    Fpn res(x.toString()); 
    Fpn sign("1.0",100);
    Fpn tempcalc = sign;
    Fpn fact = sign;
    Fpn pow = x; 

    // cout << x << res << sign << fact << pow <<endl;

    // sin(0)=sin(pi)=sin(2pi)... =0
    if (x.toString() == "0.0"){
        res.setIntPart("0");
        res.setFractPart("0");
        return res;
    }

    
    for (int i = 1; i < TAYLOR_PREC; i++) 
    { 
        std::string s = std::to_string((float)i);
        Fpn fpni(s);

        sign = sign = sign * Fpn("-1.0",100); 
        fact = fact * (( Fpn("2.0", 100) * fpni + Fpn("1.0", 100) ) * (Fpn("2.0", 100) * fpni )); 

        pow = pow * (x * x); 

        res = ((sign *  pow) / fact) +res ; 

        res.setFractPart( res.getFractPart().substr( 0, fixedPrec ) );
    } 

    return res;  
} 

Fpn Fpn::cos(Fpn x) 
{ 
    Fpn res(x.toString()); 

   //convert the number X to an equal value with the 2pi period
    if (res > Fpn("0.0") && res>Fpn(doublesPi) ){
        while (res > Fpn(doublesPi) ){
            res = res -Fpn(doublesPi);
        }
    }
    else if (res < Fpn("0.0") ){
        while (res < Fpn(doublesPi) ){
            res = res + Fpn(doublesPi);
        }
    }
    else if (res == Fpn("0.0")){
        return Fpn("1.0");
    }

    // fract precision cut
    if (res.getFractPart().size() > res.getFractPrecision() && res.getFractPart().size() > 100){
        res.setFractPart( res.getFractPart().substr( 0, res.getFractPrecision() ) );
    }

    return cosTaylorSum(res);

} 

Fpn Fpn::cosTaylorSum(Fpn x) 
{ 
    return sin(x+Fpn(halfsPi)); 
} 

//public
Fpn Fpn::sqrt(Fpn n) 
{ 
    bool isModified = false;
    Fpn modDivider("10.0");

    if (n.getIntPart()=="0" && n.getFractPart()=="0" ){  //sqrt(0) = 0
        return Fpn("0.0");
    }
    else if (n == Fpn("1.0")){  //sqrt(1) = 1
        return n;
    }
    else if (n < Fpn("0.0")){   //sqrt(NEGATIVE) is a fucking math error
        throw "FLOATING POINT EXCEPTION";
    }
    else if (n.getIntPart()=="0" && n.getFractPart()!="0" ){    //example: sqrt(0.36) == 1/sqrt(1/36.0) 
                                                                //example: sqrt(0.36) == sqrt(0.36*100)/10
        isModified = true;
        std::string temp = n.getFractPart();
        int i;
        for (i = 0; temp[i]=='0'; i++); //count zeros the begin of the fract part
        i = (i%2 ==0 )? i : i+1;    //legyen páros (ennek boldogságos matematikai okai vannak)

        // modifiy modmultiplier
        temp.clear();
        temp = "100";
        temp.append(i, '0');
        temp.append(".0");

        n = n*Fpn(temp);

        // modifiy divider
        temp.clear();
        temp = "10";
        //
        i = i/2; //úgyis páros, szóval egész a végeredmény
        temp.append(i, '0');
        temp.append(".0");
        modDivider = Fpn(temp);
        // cout << "/" << temp << endl;

        // n = Fpn("1.0")/n;

    }


    Fpn i("1.0"); 

    while (true) { 
  
        if (i * i == n) { 
            // return i; 
            return isModified ? (i/modDivider) : i; 
            // return isModified ? (Fpn("1.0")/i) : i; 
        } 
        else if (i * i > n) { 
            Fpn temp =  i-Fpn("1.0"); 
            Fpn res = sSquare(n, temp , i); 
            // return res;
            return isModified ? (res/modDivider) : res ;
            // return isModified ? (Fpn("1.0")/res) : res ;
        } 
        i = i + Fpn ("1.0"); 
    } 
} 

//*******************************************************************************************************************************
//private functions
//*******************************************************************************************************************************

Fpn Fpn::sSquare(Fpn n, Fpn i, Fpn j) 
{   
    Fpn EPS("0.00000000000000000000000000000000000000001");

    Fpn mid = (i + j) / Fpn("2.0",fixedPrec); 
    Fpn mul = mid * mid; 
  
    if ((mul == n) || (abs(mul - n) < EPS)) 
        return mid; 
    else if (mul < n) 
        return sSquare(n, mid, j); 
    else
        return sSquare(n, i, mid); 
} 

Fpn Fpn::addFpns(Fpn f1, Fpn f2){
    Fpn out("0.0");

    if (f1.getSign() == f2.getSign()){ 
        //simple add
        //set sign
        if (f1.getSign()=='+' ){
        out.setSign('+');
        }
        else if (f1.getSign()=='-' ){
            out.setSign('-');
        }

        //f1 + f2

        std::string carry = "!";

        //1. fract part.

        std::string tempFract1 = f1.getFractPart();
        std::string tempFract2 = f2.getFractPart();

        //append zeros

        if (tempFract1.size() > tempFract2.size() ){
            std::string tempstr = tempFract2;
            tempstr.append((int)tempFract1.size() - (int)tempFract2.size(),'0');
            tempFract2 = tempstr;
        }
        else if (tempFract1.size() < tempFract2.size() ){
            std::string tempstr = tempFract1;
            tempstr.append((int)tempFract2.size() - (int)tempFract1.size(),'0');
            tempFract1 = tempstr;
        }

        std::string tempstr = addIntAsString(tempFract1, tempFract2);

        if (tempstr.size() > tempFract1.size()){
            carry = tempstr[0];
            out.setFractPart( tempstr.substr( 1, tempstr.size() ) );

            tempstr.clear();
        }
        else {
            out.setFractPart(tempstr);

            tempstr.clear();
        }

        //2. int part.

        tempstr = addIntAsString(f1.getIntPart(), f2.getIntPart());


        if (carry == "!"){
            out.setIntPart(tempstr);

            tempstr.clear();
            carry.clear();
        }
        else{
            out.setIntPart( addIntAsString( tempstr, carry ) );

            tempstr.clear();
            carry.clear();
        }


    }
    else {

        if (Fpn::isSmallerFloat(f1,f2) ){   // f1<f2
            out.setSign(f2.getSign());

            out.setFractPart(extractFpns(f2, f1).getFractPart());
            out.setIntPart(extractFpns(f2, f1).getIntPart());
        }
        else if (Fpn::isSmallerFloat(f2,f1) ){   // f2<f1
            out.setSign(f1.getSign());

            out.setFractPart(extractFpns(f1, f2).getFractPart());
            out.setIntPart(extractFpns(f1, f2).getIntPart());
        }
        else { // f1==f2, equals, but signs are different
            if (f1.getSign() != f2.getSign()){
                out.setSign('+'); // if the numbers are fully equals, but the signs are different, then the sign is +, example: (-2.0)+2.0 =0 or 2.0+(-2.0)=0.0

                out.setFractPart("0");
                out.setIntPart("0");
            }
        }

    }
    
    //remove the 0's from the being of the string : 000123.456 -> 123.456 

    out.setIntPart( removeZerosTheBeginOfTheString( out.getIntPart() ) );
    out.setFractPart (removeZerosTheEndOfTheString(out.getFractPart()));
    return out;
}

Fpn Fpn::extractFpns(Fpn f1, Fpn f2){
    
    //convert fpn strings to integer extract and insert the floating point to the right place
    //example: 66.51-2222.510 = -2156.0
    //example: 66.510  2222.510
    //example: 66510  2222510
    //example: diffInts ( 2222510, 66510)  = 2156000
    //example: insert(rightPlace, '.') = 2156.0


    std::string temp1 = f1.getIntPart() + f1.getFractPart();
    std::string temp2 = f2.getIntPart() + f2.getFractPart();
    std::string temp3 = ""; 

    if (f1.getFractPart().size() < f2.getFractPart().size()){
        temp1.append(f2.getFractPart().size()-f1.getFractPart().size(), '0');
    }
    else if (f2.getFractPart().size() < f1.getFractPart().size()){
        temp2.append(f1.getFractPart().size()-f2.getFractPart().size(), '0');
    }
    if (f2.getFractPart().size() == f1.getFractPart().size()){
        temp1.append(f2.getFractPart().size()-f1.getFractPart().size(), '0');
        temp2.append(f1.getFractPart().size()-f2.getFractPart().size(), '0');
    }

    int floatPointPos = (f2.getFractPart().size() < f1.getFractPart().size()) ? f1.getFractPart().size() : f2.getFractPart().size();

    if(isSmallerInt(temp1,temp2)){
        temp3 = diffIntsAsString(temp2, temp1);

        temp3.insert(temp3.end()-floatPointPos, '.');
    }
    else if(isSmallerInt(temp2,temp1)){
        temp3 = diffIntsAsString(temp1, temp2);

        temp3.insert(temp3.end()-floatPointPos, '.');
    }
    else if (temp1 == temp2){
        temp3 = temp1;
    }

    if (temp3[0] == '.')  temp3.insert(0,"0");

    return Fpn (temp3);
}

bool Fpn::isSmallerFloat(Fpn f1, Fpn f2){

    std::string f1fract = f1.getFractPart();
    std::string f2fract = f2.getFractPart();

    if (f1.getFractPart().size() < f2.getFractPart().size()){
        f1fract.append(f2.getFractPart().size()-f1.getFractPart().size(), '0');
    }
    else if (f2.getFractPart().size() < f1.getFractPart().size()){
        f2fract.append(f1.getFractPart().size()-f2.getFractPart().size(), '0');
    }
    if (f2.getFractPart().size() == f1.getFractPart().size()){
        f1fract.append(f2.getFractPart().size()-f1.getFractPart().size(), '0');
        f2fract.append(f1.getFractPart().size()-f2.getFractPart().size(), '0');
    }

    if ( Fpn::isSmallerInt( f1.getIntPart(), f2.getIntPart() ) ){
        return true;
    }
    else if ( Fpn::isSmallerInt( f2.getIntPart(), f1.getIntPart() ) ){
        return false;
    }
    else { //equals
        if ( Fpn::isSmallerInt( f1fract, f2fract ) ){
            return true;
        }
        else if ( Fpn::isSmallerInt( f2fract, f1fract ) ){
            return false;
        }
        else{
            return false;
        }
    }
}

bool Fpn::isSmallerInt(std::string str1, std::string str2) { 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return true; 
    if (n2 < n1) 
        return false; 
  
    for (int i=0; i<n1; i++){
        if (str1[i] < str2[i]) {
            return true; 
        }
        else if (str1[i] > str2[i]) {
            return false; 
        }
    } 

    return false; 
} 

std::string Fpn::addIntAsString(std::string str1, std::string str2){
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    std::string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str;
}

std::string Fpn::diffIntsAsString(std::string str1, std::string str2) { 
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (Fpn::isSmallerInt(str1, str2)) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    std::string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    int carry = 0; 
  
    // Run loop till small string length 
    // and subtract digit of str1 to str2 
    for (int i=0; i<n2; i++) 
    { 
        // Do school mathematics, compute difference of 
        // current digits 
          
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
          
        // If subtraction is less then zero 
        // we add then we add 10 into sub and 
        // take carry as 1 for calculating next step 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of larger number 
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
          
        // if the sub value is -ve, then make it positive 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        str.push_back(sub + '0'); 
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

std::string Fpn::multiplyIntAsString(std::string num1, std::string num2){ 
    int n1 = num1.size(); 
    int n2 = num2.size(); 
    if (n1 == 0 || n2 == 0) 
    return "0"; 
   
    // will keep the result number in vector 
    // in reverse order 
    std::vector<int> result(n1 + n2, 0); 
   
    // Below two indexes are used to find positions 
    // in result.  
    int i_n1 = 0;  
    int i_n2 = 0;  
       
    // Go from right to left in num1 
    for (int i=n1-1; i>=0; i--){ 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
   
        // To shift position to left after every 
        // multiplication of a digit in num2 
        i_n2 = 0;  
           
        // Go from right to left in num2              
        for (int j=n2-1; j>=0; j--){ 
            // Take current digit of second number 
            int n2 = num2[j] - '0'; 
   
            // Multiply with current digit of first number 
            // and add result to previously stored result 
            // at current position.  
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
   
            // Carry for next iteration 
            carry = sum/10; 
   
            // Store result 
            result[i_n1 + i_n2] = sum % 10; 
   
            i_n2++; 
        } 
   
        // store carry in next cell 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
   
        // To shift position to left after every 
        // multiplication of a digit in num1. 
        i_n1++; 
    } 
   
    // ignore '0's from the right 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
   
    // If all were '0's - means either both or 
    // one of num1 or num2 were '0' 
    if (i == -1) 
    return "0"; 
   
    // generate the result string 
    std::string s = ""; 
       
    while (i >= 0) 
        s += std::to_string(result[i--]); 
   
    return s; 
}

std::string Fpn::divideIntsAsString(std::string number, std::string divisor, int precision){  
    
    std::string out; 

    if (number == "0.0"){
        return "0.0";
    }
    if (divisor == "0.0"){
        throw "FLOATING POINT EXCEPTION";
    }

    int pointPos1 = number.find(".");
    int pointPos2 = divisor.find(".");
    int pointDiff = std::abs(pointPos1-pointPos2);
    if (pointPos1>pointPos2 && pointDiff>3){
        // pont áthelyezése divisor-ben pointpos1 dik helyre
        divisor.erase(divisor.find("."),1);

        //kibővítés nullákkal a string miatt
        if (number.size()>divisor.size()) {
            divisor.append(number.size()-divisor.size(), '0');
            precision += number.size()-divisor.size();
        }
        else {
            number.append(divisor.size()-number.size(), '0');
            precision += divisor.size()-number.size();
        }

        divisor.insert(pointPos1, ".");

        number = removeZerosTheEndOfTheString(number);
        number = removeZerosTheBeginOfTheString(number);

        divisor = removeZerosTheEndOfTheString(divisor);
        divisor = removeZerosTheBeginOfTheString(divisor);

        divisor = (divisor.back() == '.') ? divisor.append("0") : divisor; // ha túlnullázta, akkor hozzácsapunk egyet, hogy a pont után legyen egy nulla.
        number = (number.back() == '.') ? number.append("0") : number;
    }


    //append zeros, because of the precision
    int numPrec = number.substr(number.find("."), number.size() ).size();
    int divPrec = divisor.substr(divisor.find("."), divisor.size() ).size();

    if (numPrec>divPrec) {
        divisor.append(numPrec-divPrec, '0');
    }
    else {
        number.append(divPrec-numPrec, '0');
    }


    std::string tempNum = number;
    std::string tempDiv = divisor;

    tempNum.erase(tempNum.find("."),1);
    tempDiv.erase(tempDiv.find("."),1);

    // exampe 188.95/0.12 => 18895/012
    // we should to remove the zeros the begin of the string
    tempNum = removeZerosTheBeginOfTheString(tempNum);
    tempDiv = removeZerosTheBeginOfTheString(tempDiv);

    std::string quotient, remainder;
    tie(quotient, remainder) = modIntsAsString(tempNum, tempDiv);

    out = quotient + "."; 
    int actPrec = 1;

    //ha egész számú a kimenet és nullázódik a tört rész, akkor nem kell a tizedes résszel semmit csinálni
    if (remainder.size() == 0){
        out.append(precision, '0');
        return out;
    } 

    tempNum = remainder+'0';

    while( actPrec<precision ){
        tie(quotient, remainder) = modIntsAsString(tempNum, tempDiv);
        out += quotient; 
        actPrec++;
        
        //ha egész számú a kimenet és nullázódik a tört rész, akkor nem kell a tizedes résszel semmit csinálni
        if (remainder.size() == 0){
            out.append( (precision-actPrec) , '0');
            break;
        } 
        tempNum = remainder+'0';
    }
        
    if (pointPos1>pointPos2 && pointDiff>3){
        int outPointPos = out.find(".");
        
        out.erase(outPointPos,1);
        out.insert(outPointPos+pointDiff, ".");

        out = Fpn::removeZerosTheBeginOfTheString(out);
    }
    
    return out; 
} 

std::tuple<std::string, std::string>  Fpn::modIntsAsString(std::string num1, std::string num2 ){

    std::string out = "";

    std::string counter = "0";
    if (isSmallerInt(num1, num2)){
        counter = "0";
    }
    else{
        while(isSmallerInt(num2, num1) || num1==num2 ){

            num1 = diffIntsAsString(num1, num2);
            num1 = removeZerosTheBeginOfTheString(num1);

            // counter ++;
            counter = addIntAsString(counter, "1");
        }
    } 
    return std::make_tuple( counter, num1 );  
}

std::string Fpn::removeZerosTheBeginOfTheString(std::string s){
    if (s.at(0) == '0'){
        std::string temp = s;
        int i;
        for (i = 0; temp[i]=='0'; i++){}

        s = temp.substr(i, temp.size() ) ;
        temp.clear();
    }
    return s;
}

std::string Fpn::removeZerosTheEndOfTheString(std::string s){
    //if the last char is '0'
    if (s.at(s.length()-1) == '0'){
        int i = s.length()-1;

        char lastChar = '0';
        while(lastChar=='0' && i!=0){
            lastChar = s[i];
            i-=1;
        }

        s.erase(i+1, s.length());

        //if the string is empty because of zeros
        if (s.length()==0 ){
            s.insert(0, "0");
        }
    }
    return s;
}