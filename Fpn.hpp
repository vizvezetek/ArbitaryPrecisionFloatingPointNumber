#ifndef FPN_HPP
#define FPN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <tuple> //multiple return values
#include <algorithm> 

#define TAYLOR_PREC 50
#define sPI "3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263"
// #define EPS 1e-13

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

    static Fpn sSquare(Fpn n, Fpn i, Fpn j) ;

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

    // Fpn operator + (Fpn &obj);
    // Fpn operator - (Fpn obj);
    // Fpn operator * (Fpn &obj);
    Fpn operator / (Fpn &obj);

    Fpn operator + (const Fpn& obj);
    Fpn operator - (const Fpn& obj);
    Fpn operator * (const Fpn& f2);
    Fpn operator / (const Fpn& f2);

    //FPN.math functions
    static Fpn sqrt (Fpn obj);
    Fpn pow (Fpn &obj);
    static Fpn sin (Fpn x);
    static Fpn cos (Fpn x);

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