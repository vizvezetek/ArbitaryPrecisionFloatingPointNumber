
#include "Fpn.hpp"

//*******************************************************************************************************************************
//public functions
//*******************************************************************************************************************************

//initialization list constructor
Fpn::Fpn(char sign_, const string number_, int intPrecision_, int fractPrecision_ ): sign (sign_), number(number_), intPrecision(intPrecision_), fractPrecision(fractPrecision_){}

Fpn::Fpn(): sign('+'), number("0.0"), intPart("0"), fractPart("0"){}

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
}


//getters

char Fpn::getSign(){
    return sign;
}

string Fpn::getNumber(){
    return intPart + '.' + fractPart;
}

string Fpn::getIntPart(){
    return intPart;
}

string Fpn::getFractPart(){
    return fractPart;
}

int Fpn::getIntPrecision(){
    return intPart.size();
}

int Fpn::getFractPrecision(){
    return fractPart.size();
}

string Fpn::toString(){
    return sign + intPart + '.' + fractPart;
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
    fractPart = fractPart_;
}

void Fpn::setIntPrecision(const int intPrecision_){ // plus zeros, when the size is ok.
    intPrecision = intPrecision_;
}

void Fpn::setFractPrecision(const int fractPrecision_){
    fractPrecision = fractPrecision_;
}


//operators

Fpn Fpn::operator = (Fpn const &obj){
    return obj;
}

bool operator == (Fpn &obj1, Fpn &obj2){

    return true ;
}

Fpn Fpn::operator + (Fpn const &obj ) {

    Fpn temp(this->toString());

    return addFpns(obj, temp) ; 
}

Fpn Fpn::operator  - (Fpn &f2) { 
    Fpn f1(this->toString());
    char s1 = f1.getSign();
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

Fpn Fpn::operator * (Fpn &f2){
    Fpn f1(this->toString());

    string temp = multiplyIntAsString( f1.getIntPart()+f1.getFractPart() , f2.getIntPart()+f2.getFractPart() );

    //set the floating point to the right position

    temp.insert(temp.end()-(f1.getFractPart().size() + f2.getFractPart().size() ) , '.');
    Fpn out(temp);

    //set the sign
    if ( (f1.getSign() == '-' && f2.getSign() == '-') || (f1.getSign() == '+' && f2.getSign() == '+') ){
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

string Fpn::divideIntsAsString(string number, string divisor, int precision){ 
    
    string out; 

    // int precdiff = (int)f2.getFractPrecision() - (int)f1.getFractPrecision();
    // tempstr.append(precdiff,'0');

    //append zeros, because of the precision
    int numPrec = number.substr(number.find("."), number.size() ).size();
    int divPrec = divisor.substr(divisor.find("."), divisor.size() ).size();

    if (numPrec>divPrec) {
        divisor.append(numPrec-divPrec, '0');
    }
    else {
        number.append(divPrec-numPrec, '0');
    }

    string tempNum = number;
    string tempDiv = divisor;
    int actPrec = 0;

    tempNum.erase(tempNum.find("."),1);
    tempDiv.erase(tempDiv.find("."),1);


    string quotient, remainder;
    tie(quotient, remainder) = modIntsAsString(tempNum, tempDiv);

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

    int counter = 0;
    if (isSmallerInt(num1, num2)){
        counter = 0;
        // num1 = num1;
    }
    else{
        while(isSmallerInt(num2, num1)){

            // num1 = removeZerosTheBeginOfTheString(num1);
            num1 = diffIntsAsString(num1, num2);
            num1 = removeZerosTheBeginOfTheString(num1);

            counter ++;
        }
    }
    

    return make_tuple( to_string(counter), num1 );  
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


// string Fpn::divideIntsAsString_abc(string number, string divisor){ 
//     // As result can be very large store it in string 
//     string ans; 
    
//     // Find prefix of number that is larger 
//     // than divisor. 
//     int idx = 0; 
//     int temp = number[idx] - '0'; 
//     while (temp < divisor) 
//        temp = temp * 10 + (number[++idx] - '0'); 
      
//     // Repeatedly divide divisor with temp. After  
//     // every division, update temp to include one  
//     // more digit. 
//     while (number.size() > idx) 
//     { 
//         // Store result in answer i.e. temp / divisor 
//         ans += (temp / divisor) + '0'; 
          
//         // Take next digit of number 
//         temp = (temp % divisor) * 10 + number[++idx] - '0'; 
//     } 
      
//     // If divisor is greater than number 
//     if (ans.length() == 0) 
//         return "0"; 
      
//     // else return ans 
//     return ans; 
// } 
