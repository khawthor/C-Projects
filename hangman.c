//Kenneth Hawthorne

//This is a hangman game

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 7
#define GUESSES 6

//A function that displays the instructions on how to play the game.
void Instructions();

//A function that determines if the second array matches the first array.
int compare(char array1[], char array2[]);

//A function that tells the user if they won or lost
void game(int win, char array[]);

//A function that returns the index of the letter that the user has guessed or something else if the letter is not in the word.
int index_f(char guess, char answer[]);

//A function that displays the contents of a character array.
void display_chracter(char array[]);

//A function that prompts the usr for a guess
char guess_f();

//1 additional functions of your own choice.


//A function that determines if the player would like to play again.
int replay();

int main()
{
	char guess;				//user guess
	int again = 0;				//used to see if the user wants to keep playing
	int index = 0;
	int i = 0;
	int size = 0;
	int win=-1;				//tells wether the user won the game or not
	int lives = 0;				//how many body parrayts before the user is hanged
	char answer[SIZE];		//stores the answer in an array
	char progress[SIZE];	//shows the progress of the guesses in an array
	char guesses[SIZE];		//stores user guesses in an array
	FILE *words;			//declarraying file pointer
	words = fopen("words.txt", "r");

	
	Instructions();
	
	while (again == 0)
	{
		fscanf(words, "%s", answer);
		strcpy(progress, answer);					//changes letters to dashes
		for (i = 0; i < strlen(progress); i++)		//
		{							
		progress[i] = '_';
		}
		guesses[0] = '\0';
		win = -1;
		lives = 0;//possible problem

		while (lives < GUESSES && win == -1)
		{
			display_chracter(progress);
			printf("there letters guessed so far are %s", guesses);
			guess = guess_f();
			size = strlen(guesses);
			guesses[size] = guess;
			guesses[size + 1] = '\0';
			index = index_f(guess, answer);
			if (index == -1)
			{
				printf("your letter is NOT in the word!");
				lives++;
				printf("\n\nYou have %d more guesses\n", (6-lives));
			}
			else
			{
				printf("your letter is in the word!");
				progress[index] = guess;
			}
			win = compare(progress, answer);
		}

		game(win, answer);
		again = replay();
	}

	fclose(words);
	return 0;
}

//welcomes the user then displays the instructions on how to play the game.
void Instructions()
{
	printf("WELCOME TO HANGMAN!\n\n\n");
	printf("Please read the following instructions before you play.\n\n");
	printf("-You will be presented with a word to be guessed\n");
	printf("-Guess letters one at a time\n");
	printf("-You can have up to six incorrect guesses\n");
	printf("-The game will be OVER when you have guessed\n");
	printf("	all the letters in the word\n");
	printf("	or when you have guessed incorrectly SIX times.\n\n");
	printf("HAVE FUN!\n\n");

}

//A function that displays the contents of a character array.
void display_chracter(char array[])
{
	int i;
	int length = 0;
	length = strlen(array);
	printf("\n");
	for (i = 0; i < length; i++)
	{
		printf(" %c", array[i]);
	}
	printf("\n");
}

//A function that prompts the usr for a guess
char guess_f()
{
	char guess;

	printf("\nEnter a letter: ");
	scanf(" %c", &guess);
	guess = tolower(guess);

	return guess;
}

//A function that returns the index of the letter that the user has guessed or something else if the letter is not in the word.
int index_f(char guess, char answer[])
{
	int i;

	for (i = 0; answer[i] != '\0'; i++)
	{
		if (guess == answer[i])
		{
			return i;
		}

	}
	return -1;

}

//A function that determines if the second array matches the first array.
int compare(char array1[], char array2[])
{
	int i;
	i = strcmp(array1, array2);

	switch (i)
	{
	case 0:
		return 0;
		break;
	default:
		return -1;
		break;
	}
}

//A function that tells the user if they won or lost
void game(int win, char array[])
{
	switch (win)
	{
	case 0:
		printf("you won!!!!\n");
		break;
	default:
		printf("you did not win\n");
		printf("the word was %s", array);
		break;
	}
}

//A function that determines if the player would like to play again.
int replay()
{
	char play;
	printf("Would you like to play again? y/n ");
	scanf(" %c", &play);

	switch (play)
	{
	case 'Y':
	case 'y':
		return 0;
		break;
	case 'N':
	case 'n':
		return 1;
		break;
	default:
		printf("Please enter y or n only");
		return 1;
		break;


	}
}