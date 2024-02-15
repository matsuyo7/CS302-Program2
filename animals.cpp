//Molina Nhoung
//CS302
//2/9/24
//
//Program 2
//This file will implement the functions in the animal inheritence hierarchy. The
//functions will take in data from the client, copy, and store them into their
//respected classes. When one data needs to be stored in a clas above,
//the current class will push up the data to its parent class.

#include "animals.h"
//ANIMALS
//default constructor
Animal::Animal(): species(nullptr)
{
	age = 0;
}

//initialization list
Animal::Animal(char * your_species, const int & an_age)
{
	species = new char[strlen(your_species) + 1];
	strcpy(species, your_species);
	age = 0;
}

//copy constructor
Animal::Animal(const Animal & to_copy)
{
	species = new char[strlen(to_copy.species) + 1];
	strcpy(species, to_copy.species);
	age = to_copy.age;
}

//assignment operator
Animal & Animal::operator=(const Animal & src)
{
	if (this == &src)
	{
		if (species)
			delete [] species;
		species = new char[strlen(src.species) + 1];
		strcpy(species, src.species);
		age = src.age;
	}
	return *this;
}

//destructor
Animal::~Animal()
{
	if (species)
		delete [] species;
	species = nullptr;
	age = 0;
}

//display the species
int Animal::display() const
{
	if (!species || age < 0)
		return 0;
	cout << "\nSpecies: " << species
	<< "\nAge: " << age;
	return 1;
}

//add the species from the user
int Animal::insert(char * add_species, const int & an_age)
{
	if (!add_species || an_age < 0)
		return 0;
	if (species)
		delete [] species;
	species = new char[strlen(add_species) + 1];
	strcpy(species, add_species);
	age = an_age;
	return 1;
}

//input the species and the age
istream & operator >> (istream & in, Animal & an2)
{
	if (an2.species)
		delete [] an2.species;
	char temp[SIZE];
	int add_age = 0;
	do
	{
		cout << "\nWhat is the species: ";
		try
		{
			cin.get(temp, SIZE, '\n');
			cin.clear();
			cin.ignore(100, '\n');
			if (strlen(temp) == 0)
				throw temp;
		}
		catch (const char * msg)
		{
			cerr << "\nNothing entered, try again" << endl;
		}
	} while (strlen(temp) == 0);
	an2.species = new char[strlen(temp) + 1];
	strcpy(an2.species, temp);
	cout << "\nWhat is the age: ";
	cin >> add_age;
	while (cin.fail())
	{
		cerr << "\nEntered a character, enter an integer" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\nWhat is the age: ";
		cin >> add_age;
	}
	cin.clear();
	cin.ignore(100, '\n');
	an2.age = add_age;
	return in;
}

//display the species and age
ostream & operator << (ostream & out, const Animal & an2)
{
	out << "\nAnimal: " << an2.species
	<< "\nAge: " << an2.age;
	return out;
}

//PETS
//default constructor
Pet::Pet()
{
}

//initialization list
Pet::Pet(char * your_species, const int & an_age, const string & a_breed, const string & a_temp): Animal(your_species, an_age)
{
}

//destructor
Pet::~Pet()
{
}

//input the species and the age
istream & operator >> (istream & in, Pet & an2)
{
}

//display the species and age
ostream & operator << (ostream & out, const Pet & an2)
{
}
