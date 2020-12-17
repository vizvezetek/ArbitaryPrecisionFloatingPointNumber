/**
 * \class Fpn
 * 
 * 
 * \note This is an arbitary precision floating point arithmetic. The actual under development version is available at: https://github.com/vizvezetek/ArbitaryPrecisionFloatingPointNumber
 * 
 * It includes the main operators(+,-,*,/,=,<,>, etc.) in functions, and basic trigonometrical operations.
 * In this case, because of my tests I temporary fixed the floating precision in 100 elements. The reason is to reduce the runtime at the bigger and complicated calculations. 
 * 
 * \author Koncz Péter (kope)
 * 
 * \version 0.9
 * 
 * \date 2020/11/25 22:07
*/

#ifndef FPN_HPP
#define FPN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <tuple> //multiple return values
#include <algorithm> 
#include <sstream>

/** 
 * \def TAYLOR_PREC 
 * \brief the precision of the taylor sum 
 */
#define TAYLOR_PREC 50

/** 
 * \def fixedPrec 
 * \brief the default precision of a number if its not overridden 
 */
#define fixedPrec 100

/** 
 * \def sPI 
 * \brief pi in string with 615 char precision  
 */
#define sPI "3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263"

/** 
 * \def doublesPi 
 * \brief 2*pi in string with 615 char precision 
 */
#define doublesPi "6.283185307179586476925286766559005768394338798750211641949889184615632812572417997256069650684234135964296173026564613294187689219101164463450718816256962234900568205403877042211119289245897909860763928857621951331866892256951296467573566330542403818291297133846920697220908653296426787214520498282547449174013212631176349763041841925658508183430728735785180720022661061097640933042768293903883023218866114540731519183906184372234763865223586210237096148924759925499134703771505449782455876366023898259667346724881313286172042789892790449474381404359721887405541078434352586353504769349636935338810264001136254290526"

/** 
 * \def NsPI 
 * \brief negative pi in string with 615 char precision 
 */
#define NsPI "-3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263"

/** 
 * \def NdoublesPi 
 * \brief -2*pi in string with 615 char precision 
 */
#define NdoublesPi "-6.283185307179586476925286766559005768394338798750211641949889184615632812572417997256069650684234135964296173026564613294187689219101164463450718816256962234900568205403877042211119289245897909860763928857621951331866892256951296467573566330542403818291297133846920697220908653296426787214520498282547449174013212631176349763041841925658508183430728735785180720022661061097640933042768293903883023218866114540731519183906184372234763865223586210237096148924759925499134703771505449782455876366023898259667346724881313286172042789892790449474381404359721887405541078434352586353504769349636935338810264001136254290526"

/** 
 * \def halfsPi 
 * \brief 0.5*pi in string with 615 char precision 
 */
#define halfsPi "1.5707963267948966192313216916397514420985846996875529104874722961539082031431044993140174126710585339910740432566411533235469223047752911158626797040642405587251420513509692605527798223114744774651909822144054878329667230642378241168933915826356009545728242834617301743052271633241066968036301245706368622935033031577940874407604604814146270458576821839462951800056652652744102332606920734759707558047165286351828797959765460930586909663058965525592740372311899813747836759428763624456139690915059745649168366812203283215430106974731976123685953510899304718513852696085881465883761923374092338347025660002840635726315"

/** 
 * \def NhalfsPi 
 * \brief -0.5*pi in string with 615 char precision 
 */
#define NhalfsPi "-1.5707963267948966192313216916397514420985846996875529104874722961539082031431044993140174126710585339910740432566411533235469223047752911158626797040642405587251420513509692605527798223114744774651909822144054878329667230642378241168933915826356009545728242834617301743052271633241066968036301245706368622935033031577940874407604604814146270458576821839462951800056652652744102332606920734759707558047165286351828797959765460930586909663058965525592740372311899813747836759428763624456139690915059745649168366812203283215430106974731976123685953510899304718513852696085881465883761923374092338347025660002840635726315"

/** 
 * \def sEuler 
 * \brief e in string with 1000 char precision 
 */
#define sEuler "2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274274663919320030599218174135966290435729003342952605956307381323286279434907632338298807531952510190115738341879307021540891499348841675092447614606680822648001684774118537423454424371075390777449920695517027618386062613313845830007520449338265602976067371132007093287091274437470472306969772093101416928368190255151086574637721112523897844250569536967707854499699679468644549059879316368892300987931277361782154249992295763514822082698951936680331825288693984964651058209392398294887933203625094431173012381970684161403970198376793206832823764648042953118023287825098194558153017567173613320698112509961818815930416903515988885193458072738667385894228792284998920868058257492796104841984443634632449684875602336248270419786232090021609902353043699418491463140934317381436405462531520961836908887070167683964243781405927145635490613031072085103837505101157477041718986106873969655212671546889570350354"


// using namespace std;    


class Fpn{

private:

    // data members ****************************************

    /// the sign of the number positive (+) or negative (-)
    char sign;      
    
    /// the number in string format. ex: "123.4567"
    std::string number;      
    
    /// the integer part of the number. ex: "123"
    std::string intPart;      
    
    /// the faction part of the number. ex: "4567"
    std::string fractPart;      
    
    /// the precision of the integer part. ex: "3"
    // int intPrecision;      
    
    int fractPrecision; /**< precision of the fraction part. Default 100. If it's set in the construct, then not 100. */


    // private functions ************************************

    /** 
     * \brief This is adding to integer value as a string. Example 23 + 34 = 57
     * \param string s1, integer in string format
     * \param string s2, integer in string format
     * \return the calculated string value
     * source: https://www.geeksforgeeks.org/sum-two-large-numbers/
     * date: 2020. 03.
    */
    std::string addIntAsString(std::string s1, std::string s2);

    /** 
     * \brief Get difference between two integer strings. Ex: 43-11 = 32
     * \param string str1, integer in string format
     * \param string str2, integer in string format
     * \return the calculated string value 
     * source: https://www.geeksforgeeks.org/difference-of-two-large-numbers
     * date: 2020.03
    */
    std::string diffIntsAsString(std::string str1, std::string str2);

    /** 
     * \brief Multiply two integer strings. Example: 11*11=121
     * \param string num1, integer in string format
     * \param string num2, integer in string format
     * \return the multiplied value as String 
     * source: https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
     * date: 2020.03
    */
    std::string multiplyIntAsString(std::string num1, std::string num2);

    /** 
     * \brief Divide ints as string
     * \param string number, integer in string format
     * \param string divisor, integer in string format
     * \param int precision, int
     * \throw the divisor can't be a zero
     * \return the calculcated values
    */
    std::string divideIntsAsString(std::string number, std::string divisor, int precision/** Precision of the result if it not finite */);

    
    /**
     * \brief This is a % (mod) function implementation by extraxtions.
     * \param num1 , integer in string format
     * \param num2 , integer in string format
     * \return a tuple<string,string>. First is how many times is it in, the second is the remainder.
    */
    std::tuple<std::string, std::string> modIntsAsString(std::string num1, std::string num2 );
    
    /** 
     * \brief if str1 < str2 returns true
     * \param string str1, integer in string format
     * \param string str2, integer in string format
     * \return true if str1 is bigger then str2
    */
    bool isSmallerInt(std::string str1, std::string str2);

    /** 
     * \brief if str1 < str2 returns true
     * \param Fpn f1
     * \param Fpn f2
     * \return true if str1 < str2
     * source: https://www.geeksforgeeks.org/difference-of-two-large-numbers/
     * date: 2020. 03.
    */
    bool isSmallerFloat(Fpn f1, Fpn f2);

    /** 
     * \brief Extraction method of the - operator. 
     * \param Fpn f1
     * \param Fpn f2
     * \return extracted Fpn result
    */
    Fpn extractFpns(Fpn f1, Fpn f2);

    /** 
     * \brief Add method of the + operator. 
     * \param Fpn f1
     * \param Fpn f2
     * \return added Fpn result
    */
    Fpn addFpns(Fpn f1, Fpn f2);

    /** 
     * \brief Taylor series sum for sine function. 
     * \param Fpn x
     * \return calculated Fpn result of sin(x)
    */
    static Fpn sinTaylorSum(Fpn x);

    /** 
     * \brief Taylor series sum for cos function. 
     * \param Fpn x
     * \return calculated Fpn result of cos(x)
    */
    static Fpn cosTaylorSum(Fpn x);

    /** 
     * \brief Helper function for sqrt() 
     * \param Fpn n
     * \param Fpn i
     * \param Fpn j
     * \return Fpn result
    */
    static Fpn sSquare(Fpn n, Fpn i, Fpn j) ;

    /** 
     * \brief this removes zeros from begin of the string. Example 001233 => 1233 
     * \param string s
     * \return string result
    */
    std::string removeZerosTheBeginOfTheString(std::string s);
    
    /** 
     * \brief this removes zeros from end of the string. Example 123300 => 1233 
     * \param string s
     * \return string result
    */
    std::string removeZerosTheEndOfTheString(std::string s);

    /** 
     * \brief ostream operator for std::cout
    */
    friend std::ostream& operator<<(std::ostream&, const Fpn&);
    
    
public:
    //constructors *****************************************

    /** 
     * \brief Simple constructor. It makes an Fpn from the const string number_ and constraints the fract part precision by the const int fractPrecision_) 
     * @param const string number_ in "-3.657" format 
     * @param const int fractPrecision_ 
    */
    Fpn(const std::string number_, const int fractPrecision_);
    
    /** 
     * \brief Simple constructor. 
     * \param const string number_ in "-3.657" format 
    */
    Fpn(const std::string number_);
    
    /** 
     * \brief copyconstructor for const Fpn reference
     * \param const Fpn& obj
    */
    Fpn(const Fpn& obj);
    
    /**
     * \brief copyconstructor for Fpn reference
     * \param Fpn& obj
    */
    Fpn(Fpn& obj);
    
    /**
     * \brief The "zero constructor" gives an object with +0.0 value
     * \param 
    */
    Fpn();

    /// destructor
    ~Fpn(){}

    //getter, setter, toString *****************************
    
    /** 
     * \brief getter for sign ex.: '+'
    */
    const char getSign(); 
    
    /** 
     * \brief getter for number. Example: 2.3456
    */
    const std::string getNumber(); 
    
    /** 
     * \brief getter for integer part. example 2
    */
    const std::string getIntPart(); 
    
    /** 
     * \brief getter for fraction part. example 3456
    */
    const std::string getFractPart(); 
    
    /** 
     * \brief getter for integer precision. example: 1
    */
    const int getIntPrecision(); 
    
    /** 
     * \brief getter for floating point precision. example 2 or 100
    */
    const int getFractPrecision(); 

    /** 
     * \brief setter for sign
     * \param const char sign_)
    */
    void setSign(const char sign_);
    
    /** 
     * \brief setter for whole number part
     * \param const string number_)
    */
    void setNumber(const std::string number_);

    /** 
     * \brief setter for integer part
     * \param const string intPart_
    */
    void setIntPart(const std::string intPart_);

    /** 
     * \brief setter for fraction part
     * \param const string fractPart_
    */
    void setFractPart(const std::string fractPart_);

    /** 
     * \brief setter for floating point precision for the calculations
     * \param const int fractPrecision_
    */
    void setFractPrecision(const int fractPrecision_);

    /** 
     * \brief simple toString method
    */
    std::string toString();


    //operators ********************************************


    /**
     * \brief simple = method by an overloaded operator
    */
    Fpn& operator = (const Fpn& obj);

    /**
     * \brief simple / method by an overloaded operator
     * \param Fpn &obj
    */
    Fpn operator / (Fpn &obj);

    /**
     * \brief simple + method by an overloaded operator
     * \param const Fpn& obj
    */
    Fpn operator + (const Fpn& obj);
    
    /**
     * \brief simple - method by an overloaded operator
     * \param const Fpn& obj
    */
    Fpn operator - (const Fpn& obj);
    
    /**
     * \brief simple * method by an overloaded operator
     * \param const Fpn& f2
    */
    Fpn operator * (const Fpn& f2);

    /**
     * \brief simple / method by an overloaded operator
     * \param const Fpn& f2
    */
    Fpn operator / (const Fpn& f2);

    //FPN.math functions

    /**
     * \brief square functiton
     * \param Fpn obj
     * \throw Sqrt parameter must be equal or greater then zero. 
     * \return calculated Fpn object of sqrt(obj)
    */
    static Fpn sqrt (Fpn obj);
    
    /**
     * \brief power function
     * \param Fpn &obj reference
     * \return calculated Fpn object pow(obj)
    */
    Fpn pow (Fpn &obj);
    
    /**
     * \brief sine function
     * \param Fpn x
     * \return calculated Fpn object of sin(x)
    */
    static Fpn sin (Fpn x);
    
    /**
     * \brief cosine function
     * \param Fpn x
     * \return calculated Fpn object of cos(x)
    */
    static Fpn cos (Fpn x);


    /**
     * \brief abs function 
     * (+) -> (+)
     * (-) -> (+)
     * \param Fpn obj
     * \return abs value of Fpn val
    */
    static Fpn abs(Fpn obj);

    
    /**
     * \brief rounding a number to integer
     * \param Fpn obj
     * \return calculated Fpn object
    */
    static Fpn round(Fpn obj);

    
    /**
     * \brief factorial of param value
     * \param Fpn obj
     * \return calculated Fpn object
    */
    static Fpn fact(Fpn obj);


    
    
    /**
     * \brief boolean != operator. True, if(obj1 != obj2) is true.
     * \param Fpn &obj1
     * \param Fpn &obj2
     * \return the boolean value. True or false.
    */
    friend bool operator != (Fpn &obj1, Fpn &obj2);
    
    /**
     * \brief boolean < operator. True, if(obj1 < obj2) is true.
     * \param Fpn &obj1
     * \param Fpn &obj2
     * \return the boolean value. True or false.
    */
    friend bool operator < (Fpn &obj1, Fpn &obj2);
    
    /**
     * \brief boolean > operator. True, if(obj1 > obj2) is true.
     * \param Fpn &obj1
     * \param Fpn &obj2
     * \return the boolean value. True or false.
    */
    friend bool operator > (Fpn &obj1, Fpn &obj2);
    
    /**
     * \brief boolean <= operator. True, if(obj1 <= obj2) is true.
     * \param Fpn &obj1
     * \param Fpn &obj2
     * \return the boolean value. True or false.
    */
    friend bool operator <= (Fpn &obj1, Fpn &obj2);
    
    /**
     * \brief boolean >= operator. True, if(obj1 >= obj2) is true.
     * \param Fpn &obj1
     * \param Fpn &obj2
     * \return the boolean value. True or false.
    */
    friend bool operator >= (Fpn &obj1, Fpn &obj2);

    /**
     * \brief boolean == operator. True, if(obj1 == obj2) is true.
     * \param this
     * \param Fpn &obj2
     * \return the boolean value. True or false.
    */
    bool operator == (const Fpn& obj2) const;

    /**
     * \brief boolean == operator. True, if(obj1 == obj2) is true.
     * \param this
     * \param Fpn &obj2
     * \return the boolean value. True or false.
    */
    bool operator != (const Fpn& obj2) const;
    
    /**
     * \brief boolean < operator. True, if(obj1 < obj2) is true.
     * \param this
     * \param Fpn &obj2
     * \return the boolean value. True or false.
    */
    bool operator < (const Fpn& obj2) const;
    
    /**
     * \brief boolean > operator. True, if(obj1 > obj2) is true.
     * \param this
     * \param Fpn &obj2
     * \return the boolean value. True or false.
    */
    bool operator > (const Fpn& obj2) const;
    
    /**
     * \brief boolean <= operator. True, if(obj1 <= obj2) is true.
     * \param this
     * \param Fpn &obj2
     * \return the boolean value. True or false.
    */
    bool operator <= (const Fpn& obj2) const;
    
    /**
     * \brief boolean >= operator. True, if(obj1 >= obj2) is true.
     * \param this
     * \param Fpn &obj2
     * \return the boolean value. True or false.
    */
    bool operator >= (const Fpn& obj2) const;

};


#endif // FPN_HPP