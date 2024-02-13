//Molina Nhoung
//CS302
//2/7/24
//
//Program 2
//This file program will be storing information about the animals and their "occupation", either being a pet
//, in a competition, or used for jobs. This file will have the skeleton for the program, implementing classes,
//nodes, and list so that the other files can implement these files.

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int SIZE {200};

class Animal
{
	public:
		Animal();								//default constructor
		Animal(char * your_species, const int & an_age);			//initialization list
		Animal(const Animal & to_copy);						//copy constructor
		Animal & operator=(const Animal & src);					//assignment operator
		~Animal();								//destructor
		int display() const;							//display the species
		int insert(char * add_species, const int & an_age);		//add the species from the user
		friend istream & operator >> (istream & in, Animal & an2);		//input the species and the age
		friend ostream & operator << (ostream & out, const Animal & an2);	//display the species and age


	private:
		int age;
		char * species;
};

class Pet: public Animal
{
	public:
		Pet();												//default constructor
		Pet(char * your_species, const int & an_age, const string & a_breed, const string & a_temp);	//initialization list
		~Pet();												//destructor
		friend istream & operator >> (istream & in, Pet & an2);		//input the species and the age
		friend ostream & operator << (ostream & out, const Pet & an2);	//display the species and age

	private:
		string temper;
		string breed;
};

class Work: public Animal
{
	public:
		Work();											//default constructor
		Work(char * your_species, const int & an_age, int & a_period, char * a_job);	//initialization list
		Work(const Work & to_copy);								//copy constructor
		Work & operator=(const Work & src);							//assignment operator
		~Work();										//destructor

	private:
		int period;
		char * job;
};

class Competition: public Animal
{
	public:
		Competition();												//default constructor
		Competition(char * your_species, const int & an_age, const string & a_comp, int & an_award);	//initialization list
		~Competition();												//destructor
	
	private:
		string comp;
		int awards;
};


//prototypes
int menu();
int animal_menu();
