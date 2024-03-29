//Molina Nhoung
//CS302
//2/19/24
//
//Program 2
//This file will implement the functions in the animal inheritence hierarchy. The
//functions will take in data from the client, copy, and store them into their
//respected classes. When one data needs to be stored in a clas above,
//the current class will push up the data to its parent class.

#include "animals.h"
//ANIMALS
//default constructor sets data members to their nullptr/0
Animal::Animal(): species(nullptr)
{
	age = 0;
}

//initialization list to set data members to what is coming in
Animal::Animal(char * your_species, const int & an_age)
{
	species = new char[strlen(your_species) + 1];
	strcpy(species, your_species);
	age = 0;
}

//copy constructor to copy the class object data members
Animal::Animal(const Animal & to_copy)
{
	species = new char[strlen(to_copy.species) + 1];
	strcpy(species, to_copy.species);
	age = to_copy.age;
}

//assignment operator to assign the members properlly
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

//destructor to deallocate memory
Animal::~Animal()
{
	if (species)
		delete [] species;
	species = nullptr;
	age = 0;
}

//input the species and the age into the incoming class object
istream & operator >> (istream & in, Animal & an2)
{
	//make sure there's nothing already in species
	if (an2.species)
	{
		delete [] an2.species;
		an2.species = nullptr;
	}
	char temp[SIZE];
	int add_age = 0;
	cout << "\nWhat is the species: ";
	in.get(temp, SIZE, '\n');
	in.clear();
	in.ignore(100, '\n');
	//if the user entered nothing
	if (strlen(temp) == 0 || in.fail())
		throw temp;
	an2.species = new char[strlen(temp) + 1];
	strcpy(an2.species, temp);
	cout << "\nWhat is the age: ";
	in >> add_age;
	//if user entered a non integer
	while (in.fail())
	{
		cerr << "Entered a character, enter an integer" << endl;
		in.clear();
		in.ignore(100, '\n');
		cout << "\nWhat is the age: ";
		in >> add_age;
	}
	in.clear();
	in.ignore(100, '\n');
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

//find a matching age and species, return true if found
bool Animal::operator == (const Animal & an2) const
{
	if (strcmp(species, an2.species) == 0 && age == an2.age)
		return true;
	return false;
}

//compare the two ages, if it's greater than current age, return true
bool Animal::operator <= (const Animal & an2) const
{
	if (age <= an2.age)
		return true;
	else
		return false;
}

//compare the two ages, if current age is greater, return true
bool Animal::operator > (const Animal & an2) const
{
	if (age > an2.age)
		return true;
	else
		return false;
}

//PETS
//default constructor
Pet::Pet()
{
}

//initialization list and passes up species and age for Animal to handle
Pet::Pet(char * your_species, const int & an_age, const string & a_breed, const vector<string> & a_temp): Animal(your_species, an_age), breed(a_breed), temper(a_temp)
{
}

//destructor
Pet::~Pet()
{
}

//input the species and the age into incoming pet class object, returns the input
istream & operator >> (istream & in, Pet & an2)
{
	//kickstarts Animal's insertion
	in >> static_cast<Animal &>(an2);
	string add_breed;
	string add_temper;
	//loop until the user enters something
	do
	{
		cout << "\nWhat's the breed: ";
		getline(in, add_breed);
		//check if the user entered anything
		if (add_breed.empty())
			cout << "Entered nothing, try again" << endl;
	} while (add_breed.empty());
	an2.breed.clear();
	an2.breed += add_breed;
	//loop until the user enters something
	do
	{
		cout << "\nAnimal's temperment: ";
		getline(in, add_temper);
		//check if the user enters anything
		if (add_temper.empty())
			cout << "Entered nothing, try again" << endl;
	} while (add_temper.empty());
	an2.temper.clear();
	an2.temper.push_back(add_temper);
	return in;
}

//display the breed and temperment, kickstarts the base class's display and returns the output
ostream & operator << (ostream & out, const Pet & an2)
{
	//kickstarts Animal's output operator
	out << static_cast<const Animal &>(an2);
	out << "\nBreed: " << an2.breed
	<< "\nTemperment: " << an2.temper[0];
	return out;
}

//find a matching breed and temper return true if found
bool Pet::operator == (const Pet & an2) const
{
	if (!Animal::operator==(an2))
		return false;
	if (breed == an2.breed && temper[0] == an2.temper[0])
		return true;
	return false;
}

//append a string, returns this object
Pet & Pet::operator += (const Pet & an2)
{
	breed += an2.breed;
	return *this;
}

//add a temper from a vector, return the resulting string
string Pet::operator + (const Pet & an2)
{
	return breed + an2.breed;
}

//WORKING ANIMAL
//default constructor
Work::Work(): job(nullptr)
{
	period = 0;
}

//initialization list, sends species and age to Animal base class
Work::Work(char * your_species, const int & an_age, int & a_period, char * a_job): Animal(your_species, an_age)
{
	job = new char[strlen(a_job) + 1];
	strcpy(job, a_job);
	period = 0;
}

//copy constructor
Work::Work(const Work & to_copy): Animal(to_copy)
{
	job = new char[strlen(to_copy.job) + 1];
	strcpy(job, to_copy.job);
	period = to_copy.period;
}

//assignment operator
Work & Work::operator=(const Work & src)
{
	if (this == &src)
	{
		if (job)
			delete [] job;
		job = new char[strlen(src.job) + 1];
		strcpy(job, src.job);
		period = src.period;
	}
	return *this;
}

//destructor
Work::~Work()
{
	if (job)
		delete [] job;
	job = nullptr;
	period = 0;
}

//input the job and years worked, kickstart the base class input, return the input
istream & operator >> (istream & in, Work & an2)
{
	//kickstarts the Animal's insert
	in >> static_cast<Animal &>(an2);
	if (an2.job)
	{
		delete [] an2.job;
		an2.job = nullptr;
	}
	char temp[SIZE];
	int add_period = 0;
	cout << "\nWhat's the animal's job: ";
	in.get(temp, SIZE, '\n');
	in.clear();
	in.ignore(100, '\n');
	//check if the user entered anything, throw if empty
	if (strlen(temp) == 0)
		throw temp;
	an2.job = new char[strlen(temp) + 1];
	strcpy(an2.job, temp);
	cout << "\nYears of experience: ";
	in >> add_period;
	//loop through until the user enters an integer and not a char
	while (in.fail())
	{
		cerr << "Entered a character, enter an integer" << endl;
		in.clear();
		in.ignore(100, '\n');
		cout << "\nYears of experience: ";
		in >> add_period;
	}
	in.clear();
	in.ignore(100, '\n');
	an2.period = add_period;
	return in;
}

//display the job and years of experience, kickstarts the base class's display
ostream & operator << (ostream & out, const Work & an2)
{
	//kickstarts Animal's output operator
	out << static_cast<const Animal &>(an2);
	out << "\nJob: " << an2.job
	<< "\nExperience (years): " << an2.period;
	return out;
}

//find a matching years worked and job title, return true if found
bool Work::operator == (const Work & an2) const
{
	if (!Animal::operator==(an2))
		return false;
	if (strcmp(job, an2.job) == 0 && period == an2.period)
		return true;
	return false;
}

//COMPETING ANIMAL
//default constructor
Competition::Competition()
{
	awards = 0;
}

//initialization list to initialize competiton and awards while sending species and age up to animal
Competition::Competition(char * your_species, const int & an_age, const string & a_comp, int & an_award): Animal(your_species, an_age), comp(a_comp)
{
	awards = 0;
}

//destructor to deallocate memory
Competition::~Competition()
{
	awards = 0;
}

//input the type of competition and number of awards, kickstarts base class's input, returns the input
istream & operator >> (istream & in, Competition & an2)
{
	//kickstarts Animal's insertion
	in >> static_cast<Animal &>(an2);
	string add_comp;
	int add_awards = 0;
	cout << "\nWhat competition: ";
	getline(in, add_comp);
	//check if the user entered anything, throw if empty
	if (add_comp.empty())
		throw "Cannot be empty";
	an2.comp = add_comp;
	cout << "\nNumber of awards: ";
	in >> add_awards;
	//loop through until the user enters an integer and not a char
	while (in.fail())
	{
		cerr << "Entered a character, enter an integer" << endl;
		in.clear();
		in.ignore(100, '\n');
		cout << "\nNumber of awards: ";
		in >> add_awards;
	}
	in.clear();
	in.ignore(100, '\n');
	an2.awards = add_awards;
	return in;
}

//display the competition and awards, kickstarts the base class Animal's display
ostream & operator << (ostream & out, const Competition & an2)
{
	//kickstarts Animal's output operator
	out << static_cast<const Animal &>(an2);
	out << "\nCompetition: " << an2.comp
	<< "\nAwards won: " << an2.awards;
	return out;
}

//find a matching comp and awards, return true if found
bool Competition::operator == (const Competition & an2) const
{
	if (!Animal::operator==(an2))
		return false;
	if (comp == an2.comp && awards == an2.awards)
		return true;
	return false;
}
