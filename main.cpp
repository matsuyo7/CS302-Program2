//Molina Nhoung
//CS302
//2/9/24
//
//Program 2
//This program will keep track of different animals and the roles that they can take, being a pet
//having a designated job, or being in a competition. Each role has its own data being collected
//from the user. Pets will have data on the age, species. Work will have the type of work the animal
//does, and competition will have the type of competiton and amount of years trained.

#include "animals.h"

int main()
{
	//Variables
	Animal an_animal;
	int option {0};
	/*
	char a_species[SIZE];
	int some_age {0};

	cout << "\nWhat's the species: ";
	cin.get(a_species, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "\nWhat's their age (year): ";
	cin >> some_age;
	cin.ignore(100, '\n');
//	an_animal.insert(a_species, some_age);
//	an_animal.display();*/
	do
	{
		option = menu();
		if (option == 1)
		{
			cin >> an_animal;
			cout << an_animal;
		}
		else if (option == 2)
		{
		}
		else if (option == 3)
		{
		}
	} while (option != 4);

	cout << endl;

	return 0;
}


int menu()
{
	int option = 0;
	cout << "\n*****ANIMAL STORAGE****"
	"\nWhat type of animal:"
	"\n\t1. Pet"
	"\n\t2. Worker"
	"\n\t3. Competition"
	"\n\t4. Exit";
	do
	{
		cout << "\nPick an option: ";
		cin >> option;
		cin.ignore(100, '\n');
		if (option < 1 || option > 4)
			cout << "Try again";
	} while (option < 1 || option > 4);
	return option;
}

int animal_menu()
{
	int option {0};
	cout << "\n***MENU***"
	"\n\t1. Insert"
	"\n\t2. Find"
	"\n\t3. Remove one"
	"\n\t4. Remove all"
	"\n\t5. Exit";
	do
	{
		cout << "\nPick an option: ";
		cin >> option;
		cin.ignore(100, '\n');
		if (option < 1 || option > 5)
			cout << "Try again";
	} while (option < 1 || option > 5);
	return option;
}
