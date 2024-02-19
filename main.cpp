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
	Animal an_animal;
	Pet a_pet, pet_two;
	Work working_an, work_two;
	Competition comp_an, comp_two;
	DLL<Pet> pet_list;
	DLL<Work> work_list;
	DLL<Competition> comp_list;
	char option {' '};
	char inner_option {' '};

	//loop through the menu until the user wants to stop
	do
	{
		option = menu();
		switch(option)
		{
			//if the user chooses to pet
			case '1':
			{
				//loop until the user wants to stop
				do
				{
					cout << "\n***PET***";
					inner_option = animal_menu();
					switch(inner_option)
					{
						//user chooses to add a pet into the list
						case '1':
						{
							try
							{
								cin >> a_pet;
								pet_list.insert(a_pet);
							}
							catch (const char * msg)
							{
								cerr << "Insertion failed: Entered nothing" << endl;
							}
							/*catch (int notint)
							{
								cerr << "Insertion failed: Added a character instead of number" << endl;
							}*/
							break;
						}
						//display the entire list
						case '2':
						{
							if(!pet_list.display())
								cout << "\nEMPTY" << endl;
							cout << endl;
							break;
						}
						//find and remove a pet
						case '3':
						{
							cout << "\nEnter info to find.";
							cin >> pet_two;
							if (pet_list.remove(pet_two))
								cout << "\nREMOVED" << endl;
							else
								cout << "\nCould not find" << endl;
							break;
						}
						//remove the entire list
						case '4':
						{
							if (pet_list.remove_all())
								cout << "\nRemoved list" << endl;
							else
								cout << "\nCould not remove" << endl;
							break;
						}
						//exit out of the pet menu
						case '5':
						{
							break;
						}
						//every other invalid option
						default:
						{
							cout << "\nInvalid choice, try again";
							break;
						}
					}
				} while (inner_option != '5');
				break;
			}
			//if the user chooses working animal
			case '2':
			{
				//loop until the user wants to stop
				do
				{
					cout << "\n***WORKING ANIMAL***";
					inner_option = animal_menu();
					switch(inner_option)
					{
						//user chooses to add a working animal into the list
						case '1':
						{
							try
							{
								cin >> working_an;
								work_list.insert(working_an);
							}
							catch (const char * empty)
							{
								cerr << "Insertion failed: Entered nothing" << endl;
							}
						/*	catch (const string msg)
							{
								cerr << "Insertion failed: Entered nothing" << endl;
							}*/
							break;
						}
						//display the entire list
						case '2':
						{
							if(!work_list.display())
								cout << "\nEMPTY" << endl;
							cout << endl;
							break;
						}
						//find and remove a working animal
						case '3':
						{
							cout << "\nEnter info to find.";
							cin >> work_two;
							if (work_list.remove(work_two))
								cout << "\nREMOVED" << endl;
							else
								cout << "\nCould not find" << endl;
							break;
						}
						//remove the entire list
						case '4':
						{
							if (work_list.remove_all())
								cout << "\nRemoved list" << endl;
							else
								cout << "\nCould not remove" << endl;
							break;
						}
						//exit out of the work menu
						case '5':
						{
							break;
						}
						//every other invalid option
						default:
						{
							cout << "\nInvalid choice, try again";
							break;
						}
					}
				} while (inner_option != '5');
				break;
			}
			//if the user chooses a competing animal
			case '3':
			{
				//loop until the user wants to stop
				do
				{
					cout << "\n***COMPETING ANIMAL***";
					inner_option = animal_menu();
					switch(inner_option)
					{
						//user chooses to add a competing animal into the list
						case '1':
						{
							try
							{
								cin >> comp_an;
								comp_list.insert(comp_an);
							}
							catch (const char * msg)
							{
								cerr << "Insertion failed: Entered nothing" << endl;
							}
							break;
						}
						//display the entire list
						case '2':
						{
							if(!comp_list.display())
								cout << "\nEMPTY" << endl;
							cout << endl;
							break;
						}
						//find and remove a competing animal
						case '3':
						{
							cout << "\nEnter info to find.";
							cin >> comp_two;
							if (comp_list.remove(comp_two))
								cout << "\nREMOVED" << endl;
							else
								cout << "\nCould not find" << endl;
							break;
						}
						//remove the entire list
						case '4':
						{
							if (comp_list.remove_all())
								cout << "\nRemoved list" << endl;
							else
								cout << "\nCould not remove" << endl;
							break;
						}
						//exit out of the competition menu
						case '5':
						{
							break;
						}
						//every other invalid option
						default:
						{
							cout << "\nInvalid choice, try again";
							break;
						}
					}
				} while (inner_option != '5');
				break;
			}
			//the user chooses to exit
			case '4':
			{
				cout << "\n***EXITING***" << endl;
				break;
			}
			//every other invalid choice
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
	"\n\t1. Pet"
	"\n\t2. Worker"
	"\n\t3. Competition"
	"\n\t4. Exit";
	cout << "\nPick an option (1-4): ";
	cin >> option;
	cin.clear();
	cin.ignore(100, '\n');
	return option;
}

char animal_menu()
{
	char option {0};
	cout << "\n***MENU***"
	"\n\t1. Insert"
	"\n\t2. Display all by age"
	"\n\t3. Remove one"
	"\n\t4. Remove all"
	"\n\t5. Exit";
	cout << "\nPick an option (1-5): ";
	cin >> option;
	cin.ignore(100, '\n');
	return option;
}
