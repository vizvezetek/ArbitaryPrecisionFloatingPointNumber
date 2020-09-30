#ifndef FPN_HPP
#define FPN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <tuple> //multiple return values
#include <algorithm> 

#define TAYLOR_PREC 10
#define EPS 1e-13

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
    string removeZerosTheEndOfTheString(string s);

    friend std::ostream& operator<<(std::ostream&, const Fpn&);
    
    
public:
    //constructors *****************************************
    Fpn(char sign_, const string number_, int intPrecision_, int fractPrecision_ );
    Fpn(const string number_);
    Fpn(const string number_, const int fractPrecision_);
    Fpn(const Fpn& obj);
    Fpn(Fpn& obj);
    Fpn();

    //destructor *******************************************
    ~Fpn(){}

    //getter, setter, toString *****************************
    const char getSign();
    const string getNumber();
    const string getIntPart();
    const string getFractPart();
    const int getIntPrecision();
    const int getFractPrecision();

    void setSign(const char sign_);
    void setNumber(const string number_);
    void setIntPart(const string intPart_);
    void setFractPart(const string fractPart_);
    void setIntPrecision(const int intPrecision_);
    void setFractPrecision(const int fractPrecision_);

    string toString();


    //operators ********************************************
    // Fpn operator = (Fpn const &obj);
    Fpn& operator = (const Fpn& obj);

    // Fpn operator + (Fpn const &obj);
    // Fpn operator - (Fpn &obj);
    // Fpn operator * (Fpn &obj);
    // Fpn operator / (Fpn &obj);

    Fpn operator + (const Fpn& obj);
    Fpn operator - (const Fpn& obj);
    Fpn operator * (const Fpn& f2);
    Fpn operator / (const Fpn& f2);

    //FPN.math functions
    Fpn sqrt (Fpn &obj);
    Fpn pow (Fpn &obj);
    static Fpn sin (Fpn x);
    Fpn cos (Fpn &obj);

    static Fpn abs(Fpn obj);
    static Fpn round(Fpn obj);
    static Fpn fact(Fpn obj);


    // friend bool operator == (Fpn& obj1, Fpn& obj2);
    friend bool operator != (Fpn &obj1, Fpn &obj2);
    friend bool operator < (Fpn &obj1, Fpn &obj2);
    friend bool operator > (Fpn &obj1, Fpn &obj2);
    friend bool operator <= (Fpn &obj1, Fpn &obj2);
    friend bool operator >= (Fpn &obj1, Fpn &obj2);

    bool operator == (const Fpn& obj2) const;
    bool operator != (const Fpn& obj2) const;
    bool operator < (const Fpn& obj2) const;
    bool operator > (const Fpn& obj2) const;
    bool operator <= (const Fpn& obj2) const;
    bool operator >= (const Fpn& obj2) const;




};


#endif // FPN_HPP