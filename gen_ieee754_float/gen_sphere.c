/*
 * The original (The MIT Licensed) source of the code: https://github.com/jsvazic/GAHelloWorld/blob/master/c/gahelloworld.c
 * Some functions and methods are from the original file.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


#define CHARMAP "01"
#define Os_ 0x01
#define RANDBETWEEN(A,B) A + rand()/(RAND_MAX/(B - A))
#define CHANCE(A) rand() < A * RAND_MAX

#define population_size 2048
#define binarr_size 32
#define MINX1 -6.0
#define MAXX1 6.0
#define STEPX1 0.025
#define MINX2 -6.0
#define MAXX2 6.0
#define STEPX2 0.025

#define GLOBMIN -1.0


static int elements;
static int total;
static char options = 0;
// static unsigned int population_size = 2048;
static unsigned int challengers = 3;
static float elitism = 0.1;
static float mutation = 0.25;


// float drop_wave (float x1, float x2) { //  renamed
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


static char rndchr(char* map)		//random char from a char collection
{
	return *(map+RANDBETWEEN(0, strlen(map)));
}

static char randchar()		//random char form CHARMAP, what includes 0 and 1
{
	return rndchr(CHARMAP);
}


char* init_pop(){		// initial population
	int full_size = population_size*64;

	char* result = malloc(full_size); // 64 = 2*32, what describes two dimensions as a float
	int i,j;
	int charcounte = 0;
	char* temp = malloc(32);

	for (i=0; i<2048; i++){
		
		strcpy (temp,  floatToCharBinaryArr(  getRandInRange(MINX1, MAXX1, STEPX1) ) );
		for(j=0; j<32; j++){ //tempX1 append to result
			*(result + charcounte ) = temp[j];
			charcounte++;
		}

		strcpy (temp,  floatToCharBinaryArr(  getRandInRange(MINX2, MAXX2, STEPX2) ) );
		for(j=0; j<32; j++){ //tempX2 append to result
			*(result + charcounte ) = temp[j];
			charcounte++;
		}
		// printf("%s\n", temp );


	}
	free(temp);
	return result;
}


static float fitness(char * str)		//fitness function
{
	// |test function - target value| 
	float x1 = getFloatValuesFromBinArray(str, 0);
	float x2 = getFloatValuesFromBinArray(str, 1);

	return f_drop_wawe( x1, x2) ;
	// return f_sphere( x1, x2) ;
}


static int fit_cmp(const void *el1, const void *el2) 	//fitness compare for the trnmt
{
	float a = fitness((char*)el1);
	float b = fitness((char*)el2);

	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}


static void mutate(char *p)		//mutation
{
	*(p + RANDBETWEEN(0, elements)) = randchar();
}


static char* rand_element(char *p)
{
	unsigned int top = population_size;

	if ((options & Os_) == Os_) {
		top = population_size * elitism;
	}

	return p + elements * (int)(RANDBETWEEN(0, top));
}


static char* turnament(char *p)
{
	size_t i;
	char* winner = rand_element(p);
	char* challenger;
	float f1 = fitness(winner);
	float f2;

	for (i = challengers; i > 0; i--) {
		challenger = rand_element(p);
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
	size_t skip = (size_t)(elitism * population_size) * elements;

	memcpy(buffer, p, total);

	for (i = skip; i <= total-elements; i += elements) {
		a = turnament(p);
		b = turnament(p);
		pivot = RANDBETWEEN(0, elements);

		strncpy(buffer + i, a, elements);
		strncpy(buffer + i, b, pivot);

		if (CHANCE(mutation)) { 
			mutate(buffer + i); 
		}

		if (i < total - elements) {
			i += elements;
			strncpy(buffer + i, b, elements);
			strncpy(buffer + i, a, pivot);
			if (CHANCE(mutation)) { mutate(buffer + i); }
		}
	}

	memcpy(p, buffer, total);
}


int main()
{
	int i = 0;
	float bestfit = RAND_MAX;
	int opt;
	srand((unsigned int)time(NULL));

	elements = 2 * binarr_size;
	total = population_size * elements;

	char *p = malloc(population_size*64);
	char *b = malloc(total);
	p = init_pop();
	

    while (1) {
		qsort(p, population_size, elements, fit_cmp);
		i ++;

		if (bestfit != fitness(p) && !isnan( bestfit ) ) {
			bestfit = fitness(p);
			// printf("[%03d] Best: (%04f)\t%.*s\t x1: %.20f x2: %.20f f(x):%.20f \n", i, bestfit, (int)elements, p, getFloatValuesFromBinArray(p,0), getFloatValuesFromBinArray(p,1), (float)bestfit);
			printf("[%03d] x1: %.20f x2: %.20f f(x):%.20f \n", i, getFloatValuesFromBinArray(p,0), getFloatValuesFromBinArray(p,1), (float)bestfit);
		}

		mate(p, b);
	}

	free(p);
	free(b);



    return 0;
}