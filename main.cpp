//Molina Nhoung
//CS302
//2/9/24
//
//Program 2
//This program will keep track of different animals and the roles that they can take, being a pet
//having a designated job, or being in a competition. Each role has its own data being collected
//from the user. Pets will have data on the age, species. Work will have the type of work the animal
//does, and competition will have the type of competiton and amount of years trained.

#include "DLL.h"

int main()
{
	//Variables
	Animal an_animal, animal_two;
	Pet a_pet;
	Work working_an;
	Competition comp_an;
//	node<Pet> * one_pet;
	char option {' '};
	char inner_option {' '};
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
	//loop through the menu until the user wants to stop
	do
	{
		option = menu();
		switch(option)
		{
			//if (option == 1)
			//if the user chooses to pet
			case '1':
			{
				do
				{
					inner_option = animal_menu();
					switch(inner_option)
					{
						case '1':
						{
							//				cin >> an_animal;
							//				cout << an_animal;
							cin >> a_pet;
							//one_pet = new node(a_pet);
						//	one_pet->display();
							//cout << a_pet;
							break;
						}
						case '2':
						{
						/*	cin >> animal_two;
							cin >> an_animal;
							if (an_animal == animal_two)
							{
								cout << "\nThey are the same";
								cout << an_animal;
							}
							else
								cout << "\nNot the same";
								*/
							break;
						}
						case '3':
						{
							break;
						}
						case '4':
						{
							break;
						}
						case '5':
						{
							break;
						}
						default:
						{
							cout << "\nInvalid choice, try again";
							break;
						}
					}
				} while (inner_option != '5');
				break;
			}
			//else if (option == 2)
			//if the user chooses working animal
			case '2':
			{
				cin >> working_an;
				cout << working_an;
				break;
			}
			//else if (option == 3)
			//if the user chooses a competing animal
			case '3':
			{
				cin >> comp_an;
				cout << comp_an;
				break;
			}
			case '4':
			{
				cout << "\n***EXITING***" << endl;
				break;
			}
			default:
			{
				cout << "\nInvalid choice, try again";
				break;
			}
		}
	} while (option != '4');

	return 0;
}


char menu()
{
	char option = 0;
	cout << "\n*****ANIMAL STORAGE****"
	"\nWhat type of animal:"
	"\n\t1. Pet"
	"\n\t2. Worker"
	"\n\t3. Competition"
	"\n\t4. Exit";
//	do
//	{
		cout << "\nPick an option: ";
		cin >> option;
		cin.clear();
		cin.ignore(100, '\n');
//		if (option < 1 || option > 4)
//			cout << "Try again";
//	} while (option < 1 || option > 4);
	return option;
}

char animal_menu()
{
	char option {0};
	cout << "\n***MENU***"
	"\n\t1. Insert"
	"\n\t2. Display all"
	"\n\t3. Remove one"
	"\n\t4. Remove all"
	"\n\t5. Exit";
//	do
//	{
		cout << "\nPick an option: ";
		cin >> option;
		cin.ignore(100, '\n');
//		if (option < 1 || option > 5)
//			cout << "Try again";
//	} while (option < 1 || option > 5);
	return option;
}
