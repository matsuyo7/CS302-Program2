//Molina Nhoung
//CS302
//2/7/24
//
//Program 2
//This file program will be storing information about the animals and their "occupation", either being a pet
//, in a competition, or used for jobs. This file will have the skeleton for the program, implementing classes,
//nodes, and list so that the other files can implement these files.

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int SIZE {200};

//personality types
//inline vector<string> personality_types = {"Outgoing", "Aggresive", "Confident", "Adaptable", "Insecure", "Independent"};

class Animal
{
	public:
		Animal();								//default constructor
		Animal(char * your_species, const int & an_age);			//initialization list
		Animal(const Animal & to_copy);						//copy constructor
		Animal & operator=(const Animal & src);					//assignment operator
		~Animal();								//destructor
		int display() const;							//display the species
		int insert(char * add_species, const int & an_age);			//add the species from the user
		friend istream & operator >> (istream & in, Animal & an2);		//input the species and the age
		friend ostream & operator << (ostream & out, const Animal & an2);	//display the species and age
		bool operator == (const Animal & an2) const;				//find a matching age and species, return true if found
		bool operator <= (const Animal & an2) const;				//compare the two ages, if it's greater than current age, return true
		bool operator > (const Animal & an2) const;				//compare the two ages, if current age is greater, return true


	private:
		int age;
		char * species;
};

class Pet: public Animal
{
	public:
		Pet();												//default constructor
		Pet(char * your_species, const int & an_age, const string & a_breed, const vector<string> & a_temp);	//initialization list
		~Pet();												//destructor
		friend istream & operator >> (istream & in, Pet & an2);		//input the breed and temper
		friend ostream & operator << (ostream & out, const Pet & an2);	//display the breed and temper
		bool operator == (const Pet & an2) const;				//find a matching breed and temper, return true if found
		Pet & operator += (const Pet & an2);				//append a string
		string operator + (const Pet & an2);			//add a temper from a vector

	private:
		string breed;
		vector<string> temper;
//		string temper;
};

class Work: public Animal
{
	public:
		Work();											//default constructor
		Work(char * your_species, const int & an_age, int & a_period, char * a_job);	//initialization list
		Work(const Work & to_copy);								//copy constructor
		Work & operator=(const Work & src);							//assignment operator
		~Work();										//destructor
		friend istream & operator >> (istream & in, Work & an2);		//input the years worked and job title
		friend ostream & operator << (ostream & out, const Work & an2);	//display the years worked and job title
		bool operator == (const Work & an2) const;				//find a matching years worked and job title, return true if found

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
		friend istream & operator >> (istream & in, Competition & an2);		//input the comp and awards
		friend ostream & operator << (ostream & out, const Competition & an2);	//display the comp and awards
		bool operator == (const Competition & an2) const;				//find a matching comp and awards, return true if found
	
	private:
		string comp;
		int awards;
};


//prototypes
char menu();
char animal_menu();
