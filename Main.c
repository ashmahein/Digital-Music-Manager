/*******************************************************************************
* Programmer: Ash Mahein                                                      *
* Class: CptS 122; Lab Section 1                                              *
* Programming Assignment: 2                                                   *
* Date: 06/19/16                                                              *
*                                                                             *
* Description: This program uses is music manager. The user can store, edit,  *
*              display, insert, delete, edit, sort, and rate their music.     *
*                                                                             *
* Relevant Formulas: NONE									                  *
*Collaboration: Andy O'Fallon, Rahul Singhal, Jose Cuevas.                    *
*Websites used: Stackoverflow.com, youtube.com, tuturialspoint.com            *
******************************************************************************/
#include "MusicPlayer.h"
#include "testMusicPlayer.h"

int main(int agrc, char *argv[])
{
	//Variable Declaration.
	int menuOption = 0, listSorted = 0, userSelection = 0;
	FILE *infile = NULL, *outfile = NULL;
	char newSong[30] = "", newAlbum[30] = "", newArtist[30] = "", newGenre[30] = "";
	int newTimesMin = 0, newTimesSec = 0, newTimesPlayed = 0, newRating = 0;
	char userSong[30], userAlbum[30], userArtist[30], userGenre[30], deleteSong[30] , changeSongRate[30];
	char editSong[30], editAlbum[30], editArtist[30], editGenre[30];
	int editTimeMin = 0, editTimeSec = 0, editTimePlayed = 0;
	int userMin = 0, userSec = 0, userPlayed = 0, userRating = 0, ratingSuccess = 0, userEditChoice = 0;
	char userChoice = '\0';
	List pList = {NULL};

	//File opened to read music.
	infile = fopen("DMM.txt", "r");

	//Do-while loop to manage music.
	printf("****Digital Music Manager****\n");
	printf("Please choose an option (1-9):\n");
	do
	{
		printf("1. Load.\n2. Store.\n3. Display.\n4. Insert.\n5. Delete.\n6. Edit.\n7. Sort.\n8. Rate.\n9. Exit.\n");
		scanf("%d", &menuOption);
		if (menuOption == 1)
		{

			readInfo(&pList, infile, &newSong, &newAlbum, &newArtist, &newGenre, newTimesMin, newTimesSec, newTimesPlayed, newRating);
			printf("Your music has been loaded.\n");
		}
		else if (menuOption == 2)
		{
			outfile = fopen("DMM.txt", "w");
			storeMusic(outfile, pList);
			//Store
		}
		else if (menuOption == 3)
		{
			printList(pList); //Display
		}
		else if (menuOption == 4)
		{
			printf("Enter song name: ");
			getc(stdin);
			fgets(userSong, 30, stdin);

			printf("Enter album name: ");
			fgets(userAlbum, 30, stdin);

			printf("Enter artist name: ");
			fgets(userArtist, 30, stdin);

			printf("Enter genre name: ");
			fgets(userGenre, 30, stdin);

			printf("Enter minutes and seconds of your song, seperated by space (i.e: 3 34): ");
			scanf("%d %d", &userMin, &userSec);

			printf("Please enter the time you've played the song: ");
			scanf("%d", &userPlayed);

			printf("Please enter rating: ");
			scanf("%d", &userRating);
			insertAtFront(&pList, userSong, userAlbum, userArtist, userGenre, userMin, userSec, userPlayed, userRating);
			printf("DON'T FORGET TO STORE YOUR MUSIC BEFORE YOU EXIT.\n");
			//Insert
		}
		else if (menuOption == 5)
		{
			printf("Enter song name: ");
			getc(stdin);
			fgets(deleteSong, 30, stdin);
			searchDelete(&pList, deleteSong);
			printf("DON'T FORGET TO STORE YOUR MUSIC BEFORE YOU EXIT.\n");
			//Delete
		}
		else if (menuOption == 6)
		{
			printf("Would you like to edit.");
			printf("1. Song, 2. Album, 3. Artist, 4. Genre\n");
			scanf("%d", &userEditChoice);
			
			if (userEditChoice == 1)
			{
				printf("What song would you like to edit: ");
				getc(stdin);
				fgets(editSong, 30, stdin);

				userChoice = '1';
				editInfo(&pList, userChoice, &editSong, &editAlbum, &editArtist, &editGenre, editTimeMin, editTimeSec, editTimePlayed);
			}
			else if (userEditChoice == 2)
			{
				printf("BEWARE: There can be similar albums. Its best to use song name.\n");
				printf("If you search for albums and there are more. The first album to be found will be changed.\n");
				printf("What album would you like to edit: ");
				getc(stdin);
				fgets(editAlbum, 30, stdin);

				userChoice = '2';
				editInfo(&pList, userChoice, &editSong, &editAlbum, &editArtist, &editGenre, editTimeMin, editTimeSec, editTimePlayed);
			}
			else if (userEditChoice == 3)
			{
				printf("BEWARE: There can be similar artist. Its best to use song name.\n");
				printf("If you search for artist and there are more. The first artist to be found will be changed.\n");
				printf("What artist would you like to edit: ");
				getc(stdin);
				fgets(editArtist, 30, stdin);

				userChoice = '3';
				editInfo(&pList, userChoice, &editSong, &editAlbum, &editArtist, &editGenre, editTimeMin, editTimeSec, editTimePlayed);
			}
			else if (userEditChoice == 4)
			{
				printf("BEWARE: There can be similar genre. Its best to use song name.\n");
				printf("If you search for genre and there are more. The first genre to be found will be changed.\n");
				printf("What genre would you like to edit: ");
				getc(stdin);
				fgets(editGenre, 30, stdin);

				userChoice = '4';
				editInfo(&pList, userChoice, &editSong, &editAlbum, &editArtist, &editGenre, editTimeMin, editTimeSec, editTimePlayed);
			}
			printf("DON'T FORGET TO STORE YOUR MUSIC BEFORE YOU EXIT.\n");
			//Edit
		}
		else if (menuOption == 7)
		{
			printf("How would you like to sort your music?\n");
			printf("1. Artist, 2. Album, 3.Genre, 4.Rating.\n");
			scanf("%d", &userSelection);
			listSorted = sortList(&pList, userSelection);
			printf("DON'T FORGET TO STORE YOUR MUSIC BEFORE YOU EXIT.\n");
			//sort
		}
		else if (menuOption == 8)
		{
			printf("Please enter the name of the song you want to rate: \n");
			getc(stdin);
			fgets(changeSongRate, 30, stdin);
			ratingSuccess = changeRate(&pList, &changeSongRate);
			printList(pList);
			printf("DON'T FORGET TO STORE YOUR MUSIC BEFORE YOU EXIT.\n");
			//Rate
		}
		else if (menuOption == 9)
		{
			printf("Your music has been managed.\n");
			storeMusic(outfile, pList);
			break; //Exit
		}
	} while ((menuOption < 1) || (menuOption > 8) || (menuOption != 9));


	fclose(outfile);
	system("pause");

	return 0;
}