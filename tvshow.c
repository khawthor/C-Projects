//Kenneth Hawthorne 
//A menu with options to store TV Shows using arrays and structures


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 50
#define _CRT_SECURE_NO_DEPRECATE


typedef struct
{
	char tvshow_name[SIZE];
	char air_day[SIZE];
	char time[SIZE];
	int season;
	double episode;
	int prod_code;
	double viewers;

}tvshow;

//this function displays the menu options for user and ask them what they would like to do 
void Menu(int total_entries);

//this function ask the user what they would like to do 
char Choice();

//this function displays the data in my structure
void Display(tvshow info[], int num_entries);

//this function saves the data to a file
void Save(tvshow info[], int num_entries);

//this function allows the user to add a tv show entry
void Add_Show(tvshow info[], int *num_entries);

//this function allows the user to delete one of their entries
void Delete_Show(tvshow info[], int *num_entries);

//this function will allow the user to edit any of the information in a entry
void Edit(tvshow info[], int *num_entries);

//this function clears all the records in the database
void Clear_All(int *num_entries);




int main()
{
	//variable declarations
	int entries = 5;
	char user_choice = '\0';

	//below is the hard coded records
	tvshow data[SIZE] = {
		"Family Guy", "Sunday", "10:30 p.m.", 12, 5, 1205, 10100000,
		"American Dad", "Sunday", "9:30 p.m.", 10, 5, 1005, 5000000,
		"Sons of Anarchy", "Tuesday", "10:00 p.m.", 10, 6, 610, 200000,
		"Arrow", "Wednesday", "8:00 p.m.", 2, 6, 206, 10000,
		"Anger Management", "Thursday", "9:00 p.m.", 2, 41, 241, 800,
	};




	printf("\n*************************WELCOME TO THE TV SHOW DATABASE************************\n");

	printf("\nYou will be able to store and manage information about your favorite tv shows!!!");


	//this loop allows for the user to use the menu until they decide to quit 
	while (user_choice != 'q')
	{
		//function call to menu
		Menu(entries);

		//assigning user_choice variable to whatever letter the choice function returns 
		user_choice = Choice();

		//below are they if statements that control the function call for all the menu options
		if (user_choice == 'p')
		{
			Display(data, entries);
		}
		else if (user_choice == 's')
		{
			Save(data, entries);
		}
		else if (user_choice == 'a')
		{
			Add_Show(data, &entries);
		}
		else if (user_choice == 'e')
		{
			Edit(data, entries);
		}
		else if (user_choice == 'd')
		{
			Delete_Show(data, &entries);
		}
		else if (user_choice == 'c')
		{
			Clear_All(&entries);
		}
		else if (user_choice == 'q')
		{

		}
		else
		{
			printf("\n\n**********************UNRECOGNIZED ENTRY**********************\n");
		}

	}

	printf("\n\n******************Thank You for using the TV SHOW DATABASE!*********************\n\n\n");

	return 0;
}

//this function displays the menu options for user and ask them what they would like to do 
void Menu(int total_entries)
{


	printf("\n--------------------------------------------------------------------------------");

	printf("\n**********************************MAIN MENU*************************************\n");

	printf("\nP....Display all records (on the screen/monitor)\n");

	printf("\nS....Create a current report (save it to a file)\n");

	printf("\nA....Add a new show\n");

	printf("\nE....Edit one of the shows information\n");

	printf("\nD....Delete an item from the database\n");

	printf("\nC....Clear all records\n");

	printf("\nQ...Quit\n");

	printf("\nThere are currently %d entries\n", total_entries);


}



//this function ask the user what they would like to do 
char Choice()
{
	char ltr = '\0';

	printf("\n-------------------------------------------------------------------------------\n");

	printf("\nPlease enter the corresponding letter for what you would like to do: ");

	scanf(" %c", &ltr);

	ltr = tolower(ltr);

	return ltr;
}


//this function displays the data in my structure
void Display(tvshow info[], int num_entries)
{
	int i;
	int database_entry = 1;

	//tells user they can't display anything because there are no entries 
	if (num_entries == 0)
	{
		printf("\n***************There are no entries in the database to display.*****************\n");
		return;
	}

	for (i = 0; i < num_entries; i++)
	{
		printf("\n\n------------------------Database Entry %d ------------------------\n", database_entry);
		printf("\nThe TV show is %s.\n", info[i].tvshow_name);
		printf("\nIt comes on every %s.\n", info[i].air_day);
		printf("\nAt %s\n", info[i].time);
		printf("\nIt is currently in season %d.\n", info[i].season);
		printf("\nThe episode that I watched was episode %.0f.\n", info[i].episode);
		if (info[i].viewers < 1000)
		{
			printf("\nThe episode was viewed by %.0f people.\n", info[i].viewers);
		}
		else if (info[i].viewers < 1000000)
		{
			printf("\nThe episode was viewed by %.0f thousand people.\n", info[i].viewers*.001);
		}
		else
		{
			printf("\nThe episode was viewed by %.1f million people.\n", info[i].viewers*.000001);
		}
		printf("\nIt's production code is %d\n", info[i].prod_code);
		database_entry++;
	}
}

//this function saves the data to a file
void Save(tvshow info[], int num_entries)
{
	int i;
	int database_entry = 1;
	FILE*infile;
	infile = fopen("TV Show Database.txt", "w");


	for (i = 0; i < num_entries; i++)
	{
		fprintf(infile, "\n------------------------Database Entry %d ------------------------\n", database_entry);
		fprintf(infile, "\nThe TV show is %s.\n", info[i].tvshow_name);
		fprintf(infile, "\nIt comes on every %s.\n", info[i].air_day);
		fprintf(infile, "\nAt %s\n", info[i].time);
		fprintf(infile, "\nIt is currently in its %d season.\n", info[i].season);
		fprintf(infile, "\nThe episode that I watched was episode %.0f.\n", info[i].episode);
		if (info[i].viewers < 1000)
		{
			fprintf(infile, "\nThe episode was viewed by %.0f people.\n", info[i].viewers);
		}
		else if (info[i].viewers < 1000000)
		{
			fprintf(infile, "\nThe episode was viewed by %.0f thousand people.\n", info[i].viewers*.001);
		}
		else
		{
			fprintf(infile, "\nThe episode was viewed by %.1f million people.\n", info[i].viewers*.000001);
		}
		fprintf(infile, "\nIt's production code is %d.\n", info[i].prod_code);
		database_entry++;
	}


	//this if statements print only in the file if num entries equals 0
	if (num_entries == 0)
	{
		fprintf(infile, "There are no tv shows in the database.\n");
	}

	printf("\n\n*************************A current report was saved.****************************\n");

	fclose(infile);


}

//this function allows the user to add a tv show entry
void Add_Show(tvshow info[], int *num_entries)
{
	char again = '\0';

	//this loop allows the user to and another show after adding one 
	do
	{
		printf("\n\n*******************************************************************************\n");

		printf("\nPlease enter the name of the tv show you want to add: ");
		scanf(" %[^\n]s", info[*num_entries].tvshow_name);

		printf("\nPlease enter the the day of the week show comes on tv: ");
		scanf("%s", info[*num_entries].air_day);

		printf("\nPlease enter the the time the show comes on tv and whether its a.m./p.m.:\n");
		scanf(" %[^\n]s", info[*num_entries].time);

		printf("\nPlease enter the season number: ");
		scanf("%d", &info[*num_entries].season);

		printf("\nPlease enter the episode number: ");
		scanf("%lf", &info[*num_entries].episode);

		printf("\nPlease enter the amount of viewers the episode received: ");
		scanf("%lf", &info[*num_entries].viewers);

		printf("\nPlease enter the production code for episode %.0f: ", info[*num_entries].episode);

		scanf("%d", &info[*num_entries].prod_code);

		*num_entries += 1;

		//this loop is so if the user puts anything else besides a y or n it will tell them its unrecognized and have them re-enter
		do
		{
			//prompt the user as to whether they would like to add another show  
			printf("\nWould you like to add another entry Y/N?: ");
			scanf(" %c", &again);
			again = tolower(again);
			if (again != 'n' && again != 'y')
			{
				printf("\n**********************UNRECOGNIZED ENTRY PLEASE ENTER Y/N***********************");
			}
		} while (again != 'n' && again != 'y');


	} while (again == 'y');
}


//this function allows the user to delete one of their entries
void Delete_Show(tvshow info[], int *num_entries)
{
	int i = 0;
	char again = '\0';
	char user_input = '\0';
	int find_entry = -1;
	int wrong = 0;

	//tells user they can't delete anything because there are no entries 
	if (*num_entries == 0)
	{
		printf("\n***************There are no entries in the database to delete.******************\n");
		return;
	}

	//the purpose of this loop is so that if the user clears all the data and then tries to delete something it will not allow them	
	//also to only allow the user to delete an entry if user input is y and the again is y
	if (*num_entries != 0)
	{
		do
		{
			wrong = 1;
			printf("\nPlease enter the production code for the entry would like to delete: ");
			scanf("%d", &find_entry);


			for (i = 0; i < *num_entries; i++)
			{
				if (find_entry == info[i].prod_code)
				{
					printf("\n\n------------------------Database Entry FOUND------------------------\n");

					printf("\nShow name: %s\n", info[i].tvshow_name);

					printf("\nAir Date: %s\n", info[i].air_day);

					printf("\nTime %s\n", info[i].time);

					printf("\nSeason %d\n", info[i].season);

					printf("\nEpisode %.0f\n", info[i].episode);

					printf("\nViewers %.1f million\n", info[i].viewers);

					//this loop will keep lopping until the user enters in a yes or no 
					do
					{
						//gives this user a warning and ask them if they are sure they want to delete the entry 
						printf("\n***************************WARNING  WARNING***************************\n");
						printf("\nAre your sure you want to delete the above entry and all its data YES=Y or NO=N?: ");
						scanf(" %c", &user_input);
						user_input = tolower(user_input);

						if (user_input != 'n' && user_input != 'y')
						{
							printf("\n**********************UNRECOGNIZED ENTRY PLEASE ENTER Y/N***********************\n");
						}

					} while (user_input != 'n' && user_input != 'y');


					if (user_input == 'y')
					{
						info[i] = info[*num_entries - 1];
						printf("\n******************The entry has been deleted.*********************\n");
						*num_entries -= 1;
						wrong = 0;
					}
					else if (user_input == 'n')
					{
						return;
					}
				}

			}
			//this if statement ask the user if they want to delete another entry after they have successfully deleted one 
			if (wrong == 0)
			{
				printf("\nWould you like to delete another entry Y/N?");
				scanf(" %c", &again);
				again = tolower(again);
			}

			//this if statement also ask the user if they would like to try another production code if their entry was not found in the database 
			else if (wrong == 1)
			{
				printf("\n******************The entry was not found.*********************\n");
				printf("\nWould you like to try another production code Y/N?");
				scanf(" %c", &again);
				again = tolower(again);
			}

		} while (again == 'y');

	}
}


//this function will allow the user to edit any of the information in a entry
void Edit(tvshow info[], int num_entries)
{
	//variable declarations 
	int i;
	char user_ltr = '\0';
	int find_entry;
	int wrong = 1;
	char edit_again = 'y';
	char wrong_again = 'y';

	//tells user they can't edit anything because there are no entries 
	if (num_entries == 0)
	{
		printf("\n*****************There are no entries in the database to edit.******************\n");

		return;
	}

	//the purpose of this loop is so that if the user clears all the data and then tries to edit something it will not allow them to 
	//also so that the code will only run if wrong again stays equal to y and wrong stays equal to 1 
	while (num_entries != 0 && wrong == 1 && wrong_again == 'y')
	{

		//prompt user for what episode they would like to edit 
		printf("\nPlease enter the production code for the entry would like to edit: ");

		scanf("%d", &find_entry);


		//this loop runs if the user entry is equal to the production code in one of the shows in the database
		for (i = 0; i < num_entries; i++)
		{

			//displays the current data in the tv show entry they chose
			if (find_entry == info[i].prod_code)
			{
				wrong = 0;
				printf("\n****************************The entry was found****************************\n\n");

				printf("\nWhich category would you like to edit.");

				printf("\n\n------------------------Database Entry FOUND------------------------\n");

				printf("\nN.....Show name: %s\n", info[i].tvshow_name);

				printf("\nD.....Air Date: %s\n", info[i].air_day);

				printf("\nT.....Time %s\n", info[i].time);

				printf("\nS.....Season %d\n", info[i].season);

				printf("\nE.....Episode %.0f\n", info[i].episode);

				if (info[i].viewers < 1000)
				{
					printf("\nV.....Viewers %.0f \n", info[i].viewers);
				}
				else if (info[i].viewers < 1000000)
				{
					printf("\nV.....Viewers %.0f million\n", info[i].viewers*.001);
				}
				else
				{
					printf("\nV.....Viewers %.1f million\n", info[i].viewers*.000001);

				}


				//this do loop will give the user the choice to edit another item in the selected show they chose to edit
				do
				{
					printf("\nPlease enter the corresponding letter to the category you want to edit:");

					scanf(" %c", &user_ltr);

					user_ltr = tolower(user_ltr);

					//the below if statements are for the user to change the contents in the category they decided to edit
					if (user_ltr == 'n')
					{
						printf("\nPlease enter the name of the tv show: ");
						scanf(" %[^\n]s", info[i].tvshow_name);
						printf("\n******************The name has been changed.******************\n");
					}
					else if (user_ltr == 'd')
					{
						printf("\nPlease enter the air date: ");
						scanf("%s", info[i].air_day);
						printf("\n******************The air date has been changed.******************\n");
					}
					else if (user_ltr == 't')
					{
						printf("\nPlease enter the the time the show comes on tv and whether it's a.m./p.m.:\n");
						scanf(" %[^\n]s", info[i].time);
						printf("\n******************The time has been changed.******************\n");
					}
					else if (user_ltr == 's')
					{
						printf("\nPlease enter the season number: ");
						scanf("%d", &info[i].season);
						printf("\n******************The season has been changed.******************\n");
					}
					else if (user_ltr == 'e')
					{
						printf("\nPlease enter the epsidoe number: ");
						scanf("%lf", &info[i].episode);
						printf("\n******************The episode has been changed.******************\n");
					}
					else if (user_ltr == 'v')
					{
						printf("\nPlease enter the amount of viewers the episode received:");
						scanf("%lf", &info[i].viewers);
						printf("\n******************The viewers has been changed******************\n");
					}
					else
					{
						printf("\n**********************UNRECOGNIZED ENTRY PLEASE ENTER Y/N***********************\n");
					}

					//this loop is so if the user puts anything else besides a y or n it will tell them its unrecognized and have them re-enter
					do
					{
						//prompt the user as to whether they would like to edit anything else 
						printf("\nWould you like to edit anything else in this TV show (Y/N)?:\n");
						scanf(" %c", &edit_again);
						edit_again = tolower(edit_again);
						if (edit_again != 'n' && edit_again != 'y')
						{
							printf("\n**********************UNRECOGNIZED ENTRY PLEASE ENTER Y/N***********************\n");
						}
					} while (edit_again != 'n' && edit_again != 'y');

				} while (edit_again == 'y');

			}//ends if statement 

		}//ends for loop

		//the purpose of this loop is so that if the user put in anything else besides a y or n if will keep lopping until they enter a valid entry
		do
		{
			if (wrong != 0)
			{
				printf("\n*******************Your entry was not found in the database.********************\n");
				printf("Would you like to try another production code Y/N?: ");
				scanf(" %c", &wrong_again);

				if (wrong_again != 'n' && wrong_again != 'y')
				{
					printf("\n**********************UNRECOGNIZED ENTRY PLEASE ENTER Y/N***********************\n");
				}
			}
		} while (wrong_again != 'n' && wrong_again != 'y');

	}//ends while loop



}


//this function clears all the records in the database
void Clear_All(int *num_entries)
{
	char sure = '\0';

	//tells user they can't clear the database because it empty 
	if (*num_entries == 0)
	{
		printf("\n****************There are no entries in the database to clear.******************\n");

		return;
	}

	//this loop is so if the user puts anything else besides a y or n it will tell them its unrecognized and have them re-enter
	do
	{
		//prompt user to see if they are sure they want to clear database
		printf("\nAre you sure you want to clear all of the entries in the database:");
		scanf(" %c", &sure);
		sure = tolower(sure);
		if (sure != 'n' && sure != 'y')
		{
			printf("\n**********************UNRECOGNIZED ENTRY PLEASE ENTER Y/N***********************");
		}
	} while (sure != 'n' && sure != 'y');

	if (sure == 'y')
	{
		*num_entries = 0;
		printf("\n*************************All records have been deleted.*************************\n");
	}
}
