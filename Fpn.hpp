#ifndef FPN_HPP
#define FPN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <tuple> //multiple return values
#include <algorithm> 

using namespace std;

class Fpn{

private:

    // data members ****************************************
    char sign;
    string number;
    string intPart;
    string fractPart;
    int intPrecision;
    int fractPrecision;

    // private functions ************************************
    string addIntAsString(string s1, string s2);
    string diffIntsAsString(string str1, string str2);
    string multiplyIntAsString(string num1, string num2);
    string divideIntsAsString(string number, string divisor, int precision);

    tuple<string, string>  modIntsAsString(string num1, string num2 );

    // string divideIntsAsString_abc(string number, string divisor);
    
    bool isSmallerInt(string str1, string str2);
    bool isSmallerFloat(Fpn f1, Fpn f2);
    Fpn extractFpns(Fpn f1, Fpn f2);
    Fpn addFpns(Fpn f1, Fpn f2);

    string removeZerosTheBeginOfTheString(string s);
    
    
    
public:
    //constructors *****************************************
    Fpn(char sign_, const string number_, int intPrecision_, int fractPrecision_ );
    Fpn(const string number); 
    Fpn();

    //destructor *******************************************
    ~Fpn(){}

    //getter, setter, toString *****************************
    char getSign();
    string getNumber();
    string getIntPart();
    string getFractPart();
    int getIntPrecision();
    int getFractPrecision();

    void setSign(const char sign_);
    void setNumber(const string number_);
    void setIntPart(const string intPart_);
    void setFractPart(const string fractPart_);
    void setIntPrecision(const int intPrecision_);
    void setFractPrecision(const int fractPrecision_);

    string toString();

    //operators ********************************************
    Fpn operator = (Fpn const &obj);

    Fpn operator + (Fpn const &obj);
    Fpn operator - (Fpn &obj);
    Fpn operator * (Fpn &obj);
    Fpn operator / (Fpn &obj);

    // Fpn sqrt (Fpn &obj);
    // Fpn pow (Fpn &obj);
    // Fpn sin (Fpn &obj);
    // Fpn cos (Fpn &obj);

    // Fpn abs (Fpn &obj);
    // Fpn round (Fpn &obj);
    // Fpn fact (Fpn &obj);


    friend bool operator == (Fpn &obj1, Fpn &obj2);
    friend bool operator != (Fpn &obj1, Fpn &obj2);
    friend bool operator < (Fpn &obj1, Fpn &obj2);
    friend bool operator > (Fpn &obj1, Fpn &obj2);
    friend bool operator <= (Fpn &obj1, Fpn &obj2);
    friend bool operator >= (Fpn &obj1, Fpn &obj2);



};


#endif // FPN_HPP