#include <iostream>
#include <iomanip>
#include <cmath>

#include <string>
#include <vector>
#include <tuple> //multiple return values
#include <algorithm> 

#define TAYLOR_PREC 110
#define EPS 1e-13

using namespace std;


bool isSmallerInt(string str1, string str2) { 
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

string diffIntsAsString(string str1, string str2) { 
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (isSmallerInt(str1, str2)) 
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

string removeZerosTheBeginOfTheString(string s){
    if (s.at(0) == '0'){
        string temp = s;
        int i;
        for (i = 0; temp[i]=='0'; i++){}

        s = temp.substr(i, temp.size() ) ;
        temp.clear();
    }
    return s;
}

tuple<string, string>  modIntsAsString(string num1, string num2 ){


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

string divideIntsAsString(string number, string divisor, int precision){ 
    
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

string divideIntsAsString_abc(string number, int divisor){ 
    // As result can be very large store it in string 
    string ans; 
    
    // Find prefix of number that is larger 
    // than divisor. 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
       temp = temp * 10 + (number[++idx] - '0'); 
      
    // Repeatedly divide divisor with temp. After  
    // every division, update temp to include one  
    // more digit. 
    while (number.size() > idx) 
    { 
        // Store result in answer i.e. temp / divisor 
        ans += (temp / divisor) + '0'; 
          
        // Take next digit of number 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
      
    // If divisor is greater than number 
    if (ans.length() == 0) 
        return "0"; 
      
    // else return ans 
    return ans; 
} 

int main (){
    
    // string result = divideIntsAsString("1001.0","10.01", 100);
    string result = divideIntsAsString_abc("100.0",10);
    // auto result = modIntsAsString("100","10");

    cout << result << endl;

    return 0;
}

