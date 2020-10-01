
#include "Fpn.hpp"

//*******************************************************************************************************************************
//public functions
//*******************************************************************************************************************************

//initialization list constructor
Fpn::Fpn(char sign_, const string number_, int intPrecision_, int fractPrecision_ ): sign (sign_), number(number_), intPrecision(intPrecision_), fractPrecision(fractPrecision_){}

Fpn::Fpn(): sign('+'), number("0.0"), intPart("0"), fractPart("0"){}

Fpn::Fpn(const Fpn& f): sign(f.sign), number(f.number), intPart(f.intPart), fractPart(f.fractPart){}
Fpn::Fpn(Fpn& f): sign(f.getSign()), number(f.getNumber()), intPart(f.getIntPart()), fractPart(f.getFractPart()){}

// //newFpnFromString(const char* s);
Fpn::Fpn(const string number_){
 

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
            intPrecision = i;
            fractPrecision = number.size()-i-1;
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

Fpn::Fpn(const string number_, const int fractPrecision_){
 
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
            intPrecision = i;
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

const string Fpn::getNumber(){
    return intPart + '.' + fractPart;
}

const string Fpn::getIntPart(){
    return intPart;
}

const string Fpn::getFractPart(){
    return fractPart;
}

const int Fpn::getIntPrecision(){
    return intPart.size();
}

const int Fpn::getFractPrecision(){
    return fractPrecision;
}

string Fpn::toString(){
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

void Fpn::setNumber(const string number_){
    number = number_;
}

void Fpn::setIntPart(const string intPart_){
    intPart = intPart_;
}

void Fpn::setFractPart(const string fractPart_){
    fractPart = removeZerosTheEndOfTheString(fractPart_);
}

void Fpn::setIntPrecision(const int intPrecision_){ // plus zeros, when the size is ok.
    intPrecision = intPrecision_;
}

void Fpn::setFractPrecision(const int fractPrecision_){
    fractPrecision = fractPrecision_;
}


//operators

// Fpn Fpn::operator = (Fpn const &obj){
//     return obj;
// }

Fpn& Fpn::operator = ( const Fpn& obj){
    if (this != &obj){
        sign = obj.sign;
        number = obj.number;
        intPart = obj.intPart;
        fractPart = obj.fractPart;
        fractPrecision = obj.fractPrecision;
    }
    return *this;
}

// bool operator == (Fpn& obj1, Fpn& obj2){

//     return (obj1.getSign() == obj2.getSign() && obj1.getIntPart() == obj2.getIntPart() && obj1.getFractPart() == obj2.getFractPart()) ? true : false ;
// }

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
    // Fpn obj1(number);
    // Fpn obj2(obj);
    // return obj2 < obj1;
    return obj2 < *this; 
}

bool operator <= (Fpn &obj1, Fpn &obj2){
    return obj1==obj2 || obj1<obj2;
}

bool Fpn::operator <= (const Fpn& obj2) const{
    // Fpn obj1(number);
    // Fpn obj2(obj);
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

    return addFpns(obj, temp) ; 
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

    string temp = multiplyIntAsString( f1.getIntPart()+f1.getFractPart() , f2.intPart+f2.fractPart );

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

    return out;
}

Fpn Fpn::operator / (const Fpn& f2){
    Fpn f1(this->toString());
    Fpn f3(f2.number);
    // cout << "f1\t" << f1.toString() <<endl;
    // cout << "f2\t" << f3.toString() <<endl;

    // cout << "eredmeny \t" << divideIntsAsString(f1.toString(), f3.toString(), 100) << endl;


    // Fpn out( "5.0" );
    // Fpn out( divideIntsAsString( "123.0", "25.0" , f1.getFractPrecision() ) ); // ==4,92

    // Fpn out( divideIntsAsString( this->toString(), f2.number , f1.getFractPrecision()>f2.fractPrecision ? f1.getFractPrecision() : f2.fractPrecision ) );
    Fpn out( divideIntsAsString( f1.toString(), f3.toString() , f1.getFractPrecision()>f3.getFractPrecision() ? f1.getFractPrecision() : f3.getFractPrecision() ) );

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
    // Fpn out( "5.0" );
    // Fpn out( divideIntsAsString( "123.0", "25.0" , f1.getFractPrecision() ) );
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
    Fpn res(x.toString()); 
    Fpn sign("1.0",100);
    Fpn fact = sign;
    Fpn pow = x; 

    // cout << res << sign << fact << pow <<endl;

    for (int i = 1; i < TAYLOR_PREC; i++) 
    { 
        std::string s = std::to_string((float)i);
        Fpn fpni(s);
        sign = sign * Fpn("-1.0",100); 
        fact = fact * ( Fpn("2.0", 100) * fpni + Fpn("1.0", 100) ) *  (Fpn("2.0", 100) * fpni ); 
        pow = pow * x * x; 
        res = res + (sign * pow / fact ); 
    } 
  
    return res;  
} 

Fpn Fpn::cos(Fpn x) 
{ 
    Fpn res("1.0"); 
    Fpn sign("1.0"), fact("1.0"),  pow("1.0"); 
    for (int i = 1; i < TAYLOR_PREC; i++) 
    { 
        std::string s = std::to_string((float)i);
        Fpn fpni(s);
        sign = sign * Fpn("-1.0",100); 
        fact = fact * (Fpn("2.0", 100) * fpni - Fpn("1.0", 100)) *  (Fpn("2.0", 100) * fpni); 
        pow = pow * x * x; 
        res = res + (sign * pow / fact ); 
    } 
  
    return res;  
} 


//*******************************************************************************************************************************
//private functions
//*******************************************************************************************************************************


Fpn Fpn::addFpns(Fpn f1, Fpn f2){
    Fpn out("0.0");

    // floating point precision setting. Append zeros for the shorter number.

    if (f1.getFractPrecision() > f2.getFractPrecision() ){
        string tempstr = f2.getFractPart();
        int precdiff = (int)f1.getFractPrecision() - (int)f2.getFractPrecision();

        tempstr.append(precdiff,'0');
        f2.setFractPart(tempstr);
    }
    else if (f1.getFractPrecision() < f2.getFractPrecision() ){
        string tempstr = f1.getFractPart();
        int precdiff = (int)f2.getFractPrecision() - (int)f1.getFractPrecision();

        tempstr.append(precdiff,'0');
        f1.setFractPart(tempstr);
    }


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

        string carry = "!";

        //1. fract part.
        string tempstr = addIntAsString(f1.getFractPart(), f2.getFractPart());

        if (tempstr.size() > f1.getFractPart().size()){
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
        //simple minus

        //set sign
        if (Fpn::isSmallerFloat(f1,f2) ){
            out.setSign(f2.getSign());
        }
        else if (Fpn::isSmallerFloat(f2,f1) ){
            out.setSign(f1.getSign());
        }
        else { //equals
            if (f1.getSign() == f2.getSign()){
                out.setSign(f1.getSign());
            }
            else{
                out.setSign('+'); // if the numbers are fully equals, but the signs are different, then the sign is +, example: (-2.0)+2.0 =0 or 2.0+(-2.0)=0.0
            }
        }
        
        //do the -

        out.setFractPart(extractFpns(f1, f2).getFractPart());
        out.setIntPart(extractFpns(f1, f2).getIntPart());

    }
    
    //remove the 0's from the being of the string : 000123.456 -> 123.456 
    // if (out.getIntPart().at(0) == '0'){
    //     string temp = out.getIntPart();
    //     int i;
    //     for (i = 0; temp[i]=='0'; i++){
    //     }
    //     out.setIntPart( temp.substr(i, temp.size() ) );
    //     temp.clear();
    // }
    out.setIntPart( removeZerosTheBeginOfTheString( out.getIntPart() ) );
    out.setFractPart (removeZerosTheEndOfTheString(out.getFractPart()));
    return out;
}

Fpn Fpn::extractFpns(Fpn f1, Fpn f2){
    string temp1 = f1.getIntPart() + f1.getFractPart();
    string temp2 = f2.getIntPart() + f2.getFractPart();

    string temp3 = diffIntsAsString(temp1, temp2);

    temp3.insert(temp3.end()-f1.getFractPart().size(), '.');

    return Fpn (temp3);
}

bool Fpn::isSmallerFloat(Fpn f1, Fpn f2){

    if ( Fpn::isSmallerInt( f1.getIntPart(), f2.getIntPart() ) ){
        return true;
    }
    else if ( Fpn::isSmallerInt( f2.getIntPart(), f1.getIntPart() ) ){
        return false;
    }
    else { //equals
        if ( Fpn::isSmallerInt( f1.getFractPart(), f2.getFractPart() ) ){
            return true;
        }
        else if ( Fpn::isSmallerInt( f2.getFractPart(), f1.getFractPart() ) ){
            return false;
        }
        else{
            return false;
        }
    }
}

bool Fpn::isSmallerInt(string str1, string str2) { 
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


string Fpn::addIntAsString(string str1, string str2){
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
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

string Fpn::diffIntsAsString(string str1, string str2) { 
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (Fpn::isSmallerInt(str1, str2)) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
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

string Fpn::multiplyIntAsString(string num1, string num2){ 
    int n1 = num1.size(); 
    int n2 = num2.size(); 
    if (n1 == 0 || n2 == 0) 
    return "0"; 
   
    // will keep the result number in vector 
    // in reverse order 
    vector<int> result(n1 + n2, 0); 
   
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
    string s = ""; 
       
    while (i >= 0) 
        s += std::to_string(result[i--]); 
   
    return s; 
}

// string Fpn::divideIntsAsString_(string number, string divisor, int precision){ 
    
//     string out; 

//     // int precdiff = (int)f2.getFractPrecision() - (int)f1.getFractPrecision();
//     // tempstr.append(precdiff,'0');

//     int pointPos1 = number.find(".");
//     int pointPos2 = divisor.find(".");
//     int pointDiff = abs(pointPos1-pointPos2);
//     if (pointPos1>pointPos2){
//         // pont áthelyezése divisor-ben pointpos1 dik helyre
//         divisor.erase(divisor.find("."),1);

//         //kibővítés nullákkal a string miatt
//         if (number.size()>divisor.size()) {
//             divisor.append(number.size()-divisor.size(), '0');
//             precision += number.size()-divisor.size();
//         }
//         else {
//             number.append(divisor.size()-number.size(), '0');
//             precision += divisor.size()-number.size();
//         }

//         divisor.insert(pointPos1, ".");
//         number = removeZerosTheEndOfTheString(number);
//         number = removeZerosTheBeginOfTheString(number);
//         divisor = removeZerosTheEndOfTheString(divisor);
//         divisor = removeZerosTheBeginOfTheString(divisor);
//         divisor = (divisor.back() == '.') ? divisor.append("0") : divisor;
//         number = (number.back() == '.') ? number.append("0") : number;
//     }

//     cout << number << "\t" << divisor << endl;


//     //append zeros, because of the precision
//     int numPrec = number.substr(number.find("."), number.size() ).size();
//     int divPrec = divisor.substr(divisor.find("."), divisor.size() ).size();

//     if (numPrec>divPrec) {
//         divisor.append(numPrec-divPrec, '0');
//     }
//     else {
//         number.append(divPrec-numPrec, '0');
//     }

//     cout << number << "\t" << divisor << endl;


//     string tempNum = number;
//     string tempDiv = divisor;

//     tempNum.erase(tempNum.find("."),1);
//     tempDiv.erase(tempDiv.find("."),1);

//     string quotient, remainder;
//     tie(quotient, remainder) = modIntsAsString(tempNum, tempDiv);

//     out = quotient + "."; 
//     int actPrec = 1;
//     tempNum = remainder+'0';

//     while( actPrec<precision ){
//         tie(quotient, remainder) = modIntsAsString(tempNum, tempDiv);

//         out += quotient; 
//         actPrec++;
//         tempNum = remainder+'0';
//     }

//     cout << out << endl;
        
//     ///asd
//     if (pointPos1>pointPos2){
//         int outPointPos = out.find(".");
//         out.erase(outPointPos,1);
//         out.insert(pointPos2+pointDiff, ".");

//         out = Fpn::removeZerosTheBeginOfTheString(out);
//     }
    
//     return out; 
// } 


string Fpn::divideIntsAsString(string number, string divisor, int precision){ 
    
    string out; 

    // int precdiff = (int)f2.getFractPrecision() - (int)f1.getFractPrecision();
    // tempstr.append(precdiff,'0');

    //append zeros, because of the precision
    int numPrec = number.substr(number.find("."), number.size() ).size();
    int divPrec = divisor.substr(divisor.find("."), divisor.size() ).size();

    // cout << "01\t" << number << "\t" << divisor << endl;

    if (numPrec>divPrec) {
        divisor.append(numPrec-divPrec, '0');
    }
    else {
        number.append(divPrec-numPrec, '0');
    }

    // cout << "02\t" << number << "\t" << divisor << endl;


    string tempNum = number;
    string tempDiv = divisor;
    int actPrec = 0;

    tempNum.erase(tempNum.find("."),1);
    tempDiv.erase(tempDiv.find("."),1);

    // cout << "03\t" << tempNum << "\t" << tempDiv << endl;

    string quotient, remainder;
    tie(quotient, remainder) = modIntsAsString(tempNum, tempDiv);

    tuple <string, string> geek;  
    geek = modIntsAsString(tempNum, tempDiv); 

    // cout << "03\t" << tempNum << "\t" << tempDiv << endl;
    // cout << "04\t" << quotient << "\t" << remainder << endl;
    // cout << "05\t" << get<0>(geek) << "\t" << get<1>(geek) << endl;



    out = quotient + "."; 
    actPrec++;
    tempNum = remainder+'0';

    while( actPrec<precision ){
        tie(quotient, remainder) = modIntsAsString(tempNum, tempDiv);

        out += quotient; 
        actPrec++;
        tempNum = remainder+'0';
    }
        
    
    
    return out; 
} 

tuple<string, string>  Fpn::modIntsAsString(string num1, string num2 ){


    string out = "";

    // int counter = 0;
    string counter = "0";
    if (isSmallerInt(num1, num2)){
        counter = "0";
        // num1 = num1;
    }
    else{
        while(isSmallerInt(num2, num1) || num1==num2 ){

            // num1 = removeZerosTheBeginOfTheString(num1);
            num1 = diffIntsAsString(num1, num2);
            num1 = removeZerosTheBeginOfTheString(num1);

            // counter ++;
            counter = addIntAsString(counter, "1");
        }
    }
    

    // return make_tuple( to_string(counter), num1 );  
    return make_tuple( counter, num1 );  
}

string Fpn::removeZerosTheBeginOfTheString(string s){
    if (s.at(0) == '0'){
        string temp = s;
        int i;
        for (i = 0; temp[i]=='0'; i++){}

        s = temp.substr(i, temp.size() ) ;
        temp.clear();
    }
    return s;
}

string Fpn::removeZerosTheEndOfTheString(string s){
    //if the last char is '0'
    if (s.at(s.length()-1) == '0'){
        int i = s.length()-1;
        for ( ; s[i]=='0'; i--){}
        s.erase(i+1, s.length());

        //if the string is empty because of zeros
        if (s.length()==0 ){
            s.insert(0, "0");
        }
    }
    return s;
}