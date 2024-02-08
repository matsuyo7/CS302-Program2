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
using namespace std;

class Animal
{
	public:
		Animal();					//default constructor
		Animal(char * species);				//initialization list
		Animal(const Animal & to_copy);			//copy constructor
		Animal & operator=(const Animal & src);		//assignment operator
		~Animal();					//destructor
		int compare(char * to_compare);			//compare species and return if the same
		int display() const;				//display the species
		int insert(char * to_add);			//add the species from the user

	private:
		char * species;
};

class Pet: public Animal
{
	public:
		Pet();						//default constructor
		Pet(char * your_species, int & your_age);	//initialization list
		~Pet();						//destructor
		int display() const;				//display age
		int insert(int & add_age);			//insert the age

	private:
		int age;
};

class Work: public Animal
{
	public:
		Work();						//default constructor
		Work(char * your_species, char * your_work);	//initialization list
		Work(const Work & to_copy);			//copy constructor
		Work & operator=(const Work & src);		//assignment operator
		~Work();					//destructor
		int display() const;				//display the type of work
		int insert(char * add_job);			//insert the job

	private:
		char * job;
};

class Competition: public Animal
{
	public:
		Competition();							//default constructor
		Competition(char * your_species, const string & a_comp);	//initialization list
		~Competition();							//destructor
		int display() const;						//display the competition
		int insert(const string & add_comp);				//insert a comp the animal participated in
	
	private:
		string comp;
};
