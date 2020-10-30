// C++ program to create target string, starting from
// random string using Genetic Algorithm

// #include <bits/stdc++.h>
#include <cmath>
#include <ctime>
#include "Fpn.hpp"
using namespace std;

// Number of individuals in each generation
#define POPULATION_SIZE 10



// Valid Genes
// const string GENES = "1234567890++.";
const string GENES = "1200000000++.";

// Target string to be generated
const string TARGET = "-1.0";

Fpn Fpn_drop_wawe (Fpn x1, Fpn x2) { //  (0,0) glob_min: -1

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

// Function to generate random numbers in given range
int random_num(int start, int end)
{
	int range = (end-start)+1;
	int random_int = start+(rand()%range);
	return random_int;
}

// Create random genes for mutation
char mutated_genes()
{
	int len = GENES.size();
	int r = random_num(0, len-1);
	return GENES[r];
}

string getRandInRangeWithPrec(int maxIntSize, int len){
    string ret = "";

    bool wasPoint = false; // generated floating point yet

    //sign + or -
    ret += GENES[random_num(10, 11)];
    // cout << GENES[10] << GENES[12] << random_num(10, 12) <<endl;

    //int part
    for(int i = 0; i< maxIntSize; i++){
        ret += GENES[random_num(0, 9)]; //numbers 0-9
    }

    // .
    ret += '.';

    //fraction part
    //int part
    for(int i = 0; i< len-((int)ret.size()); i++){
        ret += GENES[random_num(0, 9)]; //numbers 0-9
    }

    return ret;
}

// create chromosome or string of genes
string create_gnome()
{
    // example: +34.12(...)-26.54(...)
    return getRandInRangeWithPrec(1, 20) + getRandInRangeWithPrec(1, 20);
    // return "+0.000000000+0.000000000";
}

// Class representing individual in population
class Individual
{
public:
	string chromosome;
	Fpn fitness;
	Individual(string chromosome);
	Individual mate(Individual parent2);
	Fpn cal_fitness();
};

Individual::Individual(string chromosome)
{
	this->chromosome = chromosome;
	fitness = cal_fitness();
};

// Perform mating and produce new offspring
Individual Individual::mate(Individual par2)
{
	// chromosome for offspring
	string child_chromosome = "";

	int len = chromosome.size();
	for(int i = 0;i<len;i++)
	{
		// random probability
		float p = random_num(0, 100)/100;

		// if prob is less than 0.45, insert gene
		// from parent 1
		if(p < 0.45)
			child_chromosome += chromosome[i];

		// if prob is between 0.45 and 0.90, insert
		// gene from parent 2
		else if(p < 0.90)
			child_chromosome += par2.chromosome[i];

		// otherwise insert random gene(mutate),
		// for maintaining diversity
		else
			child_chromosome += mutated_genes();
	}

	// create new Individual(offspring) using
	// generated chromosome for offspring
	return Individual(child_chromosome);
};


string clearFpnStr(string s){
    bool sign = false;
    bool point = false;

    if ((s[0] == '-' || s[0] == '+') && !sign ){sign == true;}
    for(int i = 0; i< s.size(); i++){

        if (s[i] == '.' && !point){ point = true;}

        else if ( (s[i] == '.' && point) ){
            s[i] = '0';
        }
        else if ( (((s[i] == '-' || s[i] == '+') || sign) && i !=0 ) ){
            s[i] = '0';
        }
    }
    return s;
}

// Calculate fittness score, it is the number of
// characters in string which differ from target
// string.
Fpn Individual::cal_fitness()
{
    // float f1 = stof( clearFpnStr( chromosome.substr(0,10) ) );
    // float f2 = stof( clearFpnStr( chromosome.substr(52,10) ) );

	Fpn x1(clearFpnStr( chromosome.substr(0,5 ) ) );
	Fpn x2(clearFpnStr( chromosome.substr(12,5) ) );

	Fpn temp = Fpn_sphere(x1,x2);

	Fpn ret( temp.getSign() + temp.getNumber().substr(0,20) );

	cout << x1 << "\t" << x2 << "\t" << ret << endl;

	return ret;
};

// float Individual::cal_fitness()
// {
//     float f1 = stof( clearFpnStr( chromosome.substr(0,10) ) );
//     float f2 = stof( clearFpnStr( chromosome.substr(52,10) ) );
//     float ret = f_drop_wawe(f1,f2);

// 	return ret;
// };

// Overloading < operator
bool operator<(const Individual &ind1, const Individual &ind2)
{
	return ind1.fitness < ind2.fitness;
}

// Driver code
int main()
{
	srand((unsigned)(time(0)));

    // string s1 = getRandInRangeWithPrec(3, 100);
    // string s2 = getRandInRangeWithPrec(3, 100);
    // cout << "s1: " << s1 << "s2: " << s2 << endl;
    // cout << FPN_drop_wawe(Fpn(getRandInRangeWithPrec(3, 100)), Fpn(getRandInRangeWithPrec(3, 100))) <<endl;
    // cout << (Fpn(".34")<Fpn(".94")) << endl;
    // return 1;

	// current generation
	int generation = 0;

	vector<Individual> population;
	bool found = false;

	// create initial population
	for(int i = 0;i<POPULATION_SIZE;i++)
	{
		string gnome = create_gnome();
		population.push_back(Individual(gnome));
	}

	while(! found)
	{
		// sort the population in increasing order of fitness score
		sort(population.begin(), population.end());

		// if the individual having lowest fitness score ie.
		// 0 then we know that we have reached to the target
		// and break the loop
		if(population[0].fitness <= Fpn("0.0"))
		{
			found = true;
			break;
		}

		// Otherwise generate new offsprings for new generation
		vector<Individual> new_generation;

		// Perform Elitism, that mean 10% of fittest population
		// goes to the next generation
		int s = (10*POPULATION_SIZE)/100;
		for(int i = 0;i<s;i++)
			new_generation.push_back(population[i]);

		// From 50% of fittest population, Individuals
		// will mate to produce offspring
		s = (90*POPULATION_SIZE)/100;
		for(int i = 0;i<s;i++)
		{
			int len = population.size();
			int r = random_num(0, 50);
			Individual parent1 = population[r];
			r = random_num(0, 50);
			Individual parent2 = population[r];
			Individual offspring = parent1.mate(parent2);
			new_generation.push_back(offspring);
		}
		population = new_generation;
		cout<< "Generation: " << generation << "\t";
		// cout<< "String: "<< population[0].chromosome <<"\t";
		cout<< "x1: "<< clearFpnStr( population[0].chromosome.substr(0,12)) <<" x2: "<< clearFpnStr( population[0].chromosome.substr(12,12) ) <<"\t";
		cout<< "Fitness: "<< population[0].fitness << "\n";

		generation++;
	}
	cout<< "Generation: " << generation << "\t";
	// cout<< "String: "<< population[0].chromosome <<"\t";
    cout<< "x1: "<< clearFpnStr( population[0].chromosome.substr(0,12)) <<" x2: "<< clearFpnStr( population[0].chromosome.substr(12,12) ) <<"\t";
	cout<< "Fitness: "<< population[0].fitness << "\n";
}
