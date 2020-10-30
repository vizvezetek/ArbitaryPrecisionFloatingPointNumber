#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>

#include "Fpn.hpp"

using namespace std;

// #define CHARMAP "01"
#define CHARMAP "0123456789"
#define O_SPARTA 0x01
#define RANDBETWEEN(A,B) A + rand()/(RAND_MAX/(B - A))
#define CHANCE(A) rand() < A * RAND_MAX

#define pop_size 2048
#define binarr_size 32
// #define MINX1 -6.0
// #define MAXX1 6.0
// #define STEPX1 0.025
// #define MINX2 -6.0
// #define MAXX2 6.0
// #define STEPX2 0.025

#define GLOBMIN -1.0


static int el_sz;
static int total_sz;
static char options = 0;
// static unsigned int pop_size = 2048;
static unsigned int challengers = 3;
static float elitism = .1;
static float mutation = .25;


// float drop_wave (float x1, float x2) { //  renamed
float test_function (float x1, float x2) { //  (0,0) glob_min: -1
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

float f_sphere (float x1, float x2) { //  (0,0) glob_min: -1
    return (x1*x1)+(x2*x2);
}


//ok
Fpn FPN_drop_wawe (Fpn x1, Fpn x2) { //  (0,0) glob_min: -1
    
	Fpn part1 = Fpn("-1.0")*( Fpn("1.0") + Fpn::cos( Fpn("12.0")* Fpn::sqrt( (x1*x1)+(x2*x2) ) ) );
	Fpn part2 = (Fpn("0.5")* ( (x1*x1)+(x2*x2) )  + Fpn("2.0"));
	
	return (part1/part2);
}

Fpn Fpn_sphere (Fpn x1, Fpn x2) { //  (0,0) glob_min: -1
    return (x1*x1)+(x2*x2);
}

float f_drop_wawe (float x1, float x2) { //  (0,0) glob_min: -1
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

float f_sphere (float x1, float x2) { //  (0,0) glob_min: -1
    return (x1*x1)+(x2*x2);
}



char* floatToCharBinaryArr (float inp)		// float converts to IEEE754 as char* arr
{
	int num = *(int*)(&inp);
	char *binarray = (char *)malloc(32 * sizeof(char*));
    
	for (int i = 0; i < 32; i++) {
		binarray[i] = '0'+ ((num >> i) & 1);
	}
	binarray[32] = '\0';

    return binarray;
}


float binArrToFloat(const char *s)		//char* (IEE754) array convert to float 
{
    float f = 0.0;
	int num = 0;
	for (int i = 0; i < 32; i++) {
		num |= (s[i] - '0')<<i;
	}
	f = *(float*)(&num);
    return f;
}


float getFloatValuesFromBinArray(char* binarr, int num){		//char* (IEE754) array convert to float 
	char* out = (char *)malloc(32 * sizeof(char*));
   
    strncpy(out, binarr+(num*32), 32);
    out[32]='\0';

	return binArrToFloat(out);
}


char* getBinValuesFromBinArray(char* binarr, int num){
	char* out = (char *)malloc(32 * sizeof(char*));
   
    strncpy(out, binarr+(num*32), 32);
    out[32]='\0';

	return out;
}


float getRandInRange(float min, float max, float step)		//returns a random float number in our range with the artifical errors
{
    int sizeOfRange = (int)(fabs(min) + fabs(max)) / (step) +1;    // example: (|-512|+|512|) / 0.2 = 5120 This is the max number of elements in the range.

    int i;
    int randelement = RANDBETWEEN(1, sizeOfRange);

    float randnum = min;
    for(i=0; i<randelement ; i++){
        randnum += step;
    }
    
    return randnum;
}

//ok
static char rndchr(char* map)		//random char from a char collection
{
	return *(map+RANDBETWEEN(0, strlen(map)));
}
//ok
static char randchar()		//random char form CHARMAP, what includes 0 and 1
{
	return rndchr(CHARMAP);
}

//ok
// char* init_pop(){		// initial population
// 	int full_size = pop_size*64;

// 	char* result = (char*)malloc(full_size); // 64 = 2*32, what describes two dimensions as a float
// 	int i,j;
// 	int char_counter = 0;
// 	char* temp = (char*)malloc(32);

// 	for (i=0; i<2048; i++){
		
// 		strcpy (temp,  floatToCharBinaryArr(  getRandInRange(MINX1, MAXX1, STEPX1) ) );
// 		for(j=0; j<32; j++){ //tempX1 append to result
// 			*(result + char_counter ) = temp[j];
// 			char_counter++;
// 			// printf("%c", temp[j]);
// 		}
// 		// printf("\n%s\n", temp );

// 		strcpy (temp,  floatToCharBinaryArr(  getRandInRange(MINX2, MAXX2, STEPX2) ) );
// 		for(j=0; j<32; j++){ //tempX2 append to result
// 			*(result + char_counter ) = temp[j];
// 			char_counter++;
// 		}
// 		// printf("%s\n", temp );


// 	}
// 	free(temp);
// 	return result;
// }

const char * getRandNumberString(int length){
// const string getRandNumberString(int length){
	
	string s = "";

	for (int i = 0; i< length; i++){
		string temp (1, randchar());
		s.append(temp);
	}

	char* out = (char *)malloc(length * sizeof(char*));
   
    strncpy(out, s.c_str() , length);

	return out;
}

char* init_pop(){		// initial population
	int full_size = pop_size*64;

	char* result = (char*)malloc(full_size); // 64 = 2*32, what describes two dimensions as a float
	int i,j;
	int char_counter = 0;
	char* temp = (char*)malloc(32);

	for (i=0; i<2048; i++){
		
		// strcpy (temp,  floatToCharBinaryArr(  getRandInRange(MINX1, MAXX1, STEPX1) ) );
		strcpy (temp,  getRandNumberString(32) );
		for(j=0; j<32; j++){ //tempX1 append to result
			*(result + char_counter ) = temp[j];
			char_counter++;
			// printf("%c", temp[j]);
		}
		// printf("\n%s\n", temp );

		// strcpy (temp,  floatToCharBinaryArr(  getRandInRange(MINX2, MAXX2, STEPX2) ) );
		strcpy (temp, getRandNumberString(32) );
		for(j=0; j<32; j++){ //tempX2 append to result
			*(result + char_counter ) = temp[j];
			char_counter++;
		}
		// printf("%s\n", temp );


	}

	free(temp);
	return result;
}


Fpn getFpnFromCharArr(char * str, int num){
	string temp(str); 

	string str1 = temp.substr(num*32,32);

	str1.insert(1,".");

	return Fpn(str1);
}

static Fpn fitness(char * str)		//fitness function
{
	// |test function - target value| 
	// float x1 = getFloatValuesFromBinArray(str, 0);
	// float x2 = getFloatValuesFromBinArray(str, 1);

	// string temp(str); 

	// string str1 = temp.substr(0,32);
	// string str2 = temp.substr(32,32);

	// str1.insert(1,".");
	// str2.insert(1,".");

	// Fpn x1 (str1);
	// Fpn x2 (str2);

	Fpn x1 = getFpnFromCharArr(str,0);
	Fpn x2 = getFpnFromCharArr(str,1);

	// cout << "x1:" << x1 ;
	// cout << " x2:" << x2 << endl;

	// return test_function( x1, x2) ;
	return Fpn_sphere( x1, x2) ;
	// return (int)(x1+x2) ;
}


static int fit_cmp(const void *el1, const void *el2) 	//fitness compare for the trnmt
{
	Fpn a = fitness((char*)el1);
	Fpn b = fitness((char*)el2);

	// cout << "el1: " << (char*)el1 << " \t el2: " << (char*)el2 << endl;
	// cout << "a: " << a << " \t b: " << b << endl;

	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}


static void mutate(char *p)		//mutation
{
	*(p + RANDBETWEEN(0, el_sz)) = randchar();
}


static char* rnd_el(char *p)
{
	unsigned int top = pop_size;

	if ((options & O_SPARTA) == O_SPARTA) {
		top = pop_size * elitism;
	}

	return p + el_sz * (int)(RANDBETWEEN(0, top));
}


static char* trnmnt(char *p)
{
	size_t i;
	char* winner = rnd_el(p);
	char* challenger;
	Fpn f1 = fitness(winner);
	Fpn f2;

	for (i = challengers; i > 0; i--) {
		challenger = rnd_el(p);
		f2 = fitness(challenger);
		if (f2 < f1) {
			f1 = f2;
			winner = challenger;
		}
	}

	return winner;
}


static void mate(char *p, char *buffer)		// Perform mating
{
	char *a, *b;
	size_t i, pivot;
	size_t skip = (size_t)(elitism * pop_size) * el_sz;
	memcpy(buffer, p, total_sz);

	for (i = skip; i <= total_sz-el_sz; i += el_sz) {
		a = trnmnt(p);
		b = trnmnt(p);
		pivot = RANDBETWEEN(0, el_sz);

		strncpy(buffer + i, a, el_sz);
		strncpy(buffer + i, b, pivot);

		if (CHANCE(mutation)) { 
			mutate(buffer + i); 
		}

		if (i < total_sz - el_sz) {
			i += el_sz;
			strncpy(buffer + i, b, el_sz);
			strncpy(buffer + i, a, pivot);
			if (CHANCE(mutation)) { mutate(buffer + i); }
		}
	}

	memcpy(p, buffer, total_sz);
}


int main()
{
	int i = 0;
	// float bestfit = RAND_MAX;
	Fpn bestfit("100000.0");
	int opt;
	srand((unsigned int)time(NULL));

	el_sz = 2 * binarr_size;
	total_sz = pop_size * el_sz;

	char *p = (char*)malloc(pop_size*64);
	char *b = (char*)malloc(total_sz);
	p = init_pop();
	
	cout << "TEST " << getFpnFromCharArr("11223300000000000000000000",0) <<endl;

    while (1) {
		qsort(p, pop_size, el_sz, fit_cmp);
		i ++;

		if (!(bestfit == fitness(p)) /*&& !isnan( bestfit )*/ ) {
			bestfit = fitness(p);
			// printf("[%03d] Best: (%04f)\t%.*s\t x1: %.20f x2: %.20f f(x):%.20f \n", i, bestfit, (int)el_sz, p, getFloatValuesFromBinArray(p,0), getFloatValuesFromBinArray(p,1), (float)bestfit);
			// printf("[%03d] x1: %.20f x2: %.20f f(x):%.20f \n", i, getFloatValuesFromBinArray(p,0), getFloatValuesFromBinArray(p,1), (float)bestfit);
			// printf("[%03d] x1: %.20f x2: %.20f f(x):%.20f \n", i, getFloatValuesFromBinArray(p,0), getFloatValuesFromBinArray(p,1), (float)bestfit);
			cout << "["<<i<<"]\t x1: " <<  getFpnFromCharArr(p,0)  << " x2: " <<  getFpnFromCharArr(p,1) << " f(x): " << bestfit << endl;
		}

		mate(p, b);
	}

	free(p);
	free(b);



    return 0;
}