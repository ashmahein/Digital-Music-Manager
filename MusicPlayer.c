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

/*************************************************************
* Function: *makeNode ()                                    *
* Date Created: 06/15/16                                    *
* Date Last Modified: 06/15/16                              *
* Description: Makes nodes containg song info.              *
* Input parameters:new song, album, artist, genre, length,  *
*                  time played, rating.                     *
* Returns: A new node.                                      *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
Node *makeNode(char *newSong, char *newAlbum, char *newArtist, char *newGenre, int newTimesMin, int newTimesSec, int newTimesPlayed, int newRating)
{
	Node * pMem = NULL;

	//allocates space for a node from the stack.
	pMem = (Node *)malloc(sizeof(Node));

	//Set pPrev and pCur equal to NULL;
	pMem->pNext = NULL;
	pMem->pPrev = NULL;
	
	//Copies new item into pMem.
	strcpy(pMem->song, newSong);
	//Copies new item into pMem.
	strcpy(pMem->album, newAlbum);
	//Copies new item into pMem.
	strcpy(pMem->artist, newArtist);
	//Copies new item into pMem.
	strcpy(pMem->genre, newGenre);
	//Sets runtime to new time.
	pMem->runTime.minutes = newTimesMin;
	//Sets runtime to new time.
	pMem->runTime.seconds = newTimesSec;
	//Sets times played to new times played..
	pMem->timesPlayed = newTimesPlayed;
	//Sets rating to new rating.
	pMem->rating = newRating;

	return pMem;
}

/*************************************************************
* Function: initList ()                                     *
* Date Created: 06/15/16                                    *
* Date Last Modified: 06/15/16                              *
* Description: Initializes the list                         *
* Input parameters:The List.                                *
* Returns: NONE                                             *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
void initList(List *pList)
{
	//Initializes the list.
	pList->pHead = NULL;
}

/*************************************************************
* Function: insertAtFront ()                                *
* Date Created: 06/16/16                                    *
* Date Last Modified: 06/16/16                              *
* Description: Inserts new node to the front of the list.   *
* Input parameters:new song, album, artist, genre, length,  *
*                  time played, rating, and list.           *
* Returns: NONE                                             *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
void insertAtFront(List *pList, char *newSong, char *newAlbum, char *newArtist, char *newGenre, int *newTimesMin, int *newTimesSec, int *newTimesPlayed, int *newRating)
{
	//makes a new node with the given search fields.
	Node * pMem = makeNode(newSong, newAlbum, newArtist, newGenre, newTimesMin, newTimesSec, newTimesPlayed, newRating);
	//Adds new node to the list.
	if (pList->pHead == NULL)
	{

	}
	else
	{
		//adds the new node to the next one by connecting pNext and the pPrev pointers.
		pMem->pNext = pList->pHead;
		pList->pHead->pPrev = pMem;
	}
	//Sets the new node to the beginning of the list.
	pList->pHead = pMem;
}

/*************************************************************
* Function: sortList ()                                     *
* Date Created: 06/15/16                                    *
* Date Last Modified: 06/15/16                              *
* Description: Sorts the list according to genre.           *
* Input parameters:List                                     *
* Returns: Success.                                         *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
int sortList(List *pList, int userSelection)
{
	Node *pCur = NULL;
	int success = 0, length = 0, passes = 0;
	//Goes through the list counting up the total number of nodes.
	List copy = *pList;
	while (copy.pHead != NULL)
	{
		length++;
		copy.pHead = copy.pHead->pNext;
	}
	if (userSelection == 1)
	{
		//Begins to sort the function.
		for (passes = 1; passes <= length - 1; ++passes)
		{
			//Will continue to sort the function as long as everything hasn't been sorted.
			pCur = pList->pHead;
			while ((pCur != NULL) && (pCur->pNext != NULL))
			{
				//Compares the first two items.
				if (strcmp(pCur->artist, pCur->pNext->artist) > 0)
				{
					if (pCur->pPrev != NULL) //We are not at the front of the list. AKA something is in front of the node youre looking at.
					{
						pCur->pPrev->pNext = pCur->pNext; //Switches the nodes if we're not at the front of the list.
					}
					else
					{
						pList->pHead = pCur->pNext; //We are at the front of the list so it makes the switch.
					}
					pCur->pNext->pPrev = pCur->pPrev; //Connects the pPrev of one item to the pPrev of another.
					pCur->pPrev = pCur->pNext; //Connects the pCur of one item to the pCur of another.
					if (pCur->pNext->pNext != NULL) //As long we're not at the end of the list this will execute.
					{
						pCur->pNext->pNext->pPrev = pCur; //We'll set the very next nodes pointer to pCur.
					}
					pCur->pNext = pCur->pNext->pNext;
					pCur->pPrev->pNext = pCur;
				}
				pCur = pCur->pNext;//Moves through the list.
			}
		}
	}

	else if (userSelection == 2)
	{
		//Begins to sort the function.
		for (passes = 1; passes <= length - 1; ++passes)
		{
			//Will continue to sort the function as long as everything hasn't been sorted.
			pCur = pList->pHead;
			while ((pCur != NULL) && (pCur->pNext != NULL))
			{
				//Compares the first two items.
				if (strcmp(pCur->album, pCur->pNext->album) > 0)
				{
					if (pCur->pPrev != NULL) //We are not at the front of the list. AKA something is in front of the node youre looking at.
					{
						pCur->pPrev->pNext = pCur->pNext; //Switches the nodes if we're not at the front of the list.
					}
					else
					{
						pList->pHead = pCur->pNext; //We are at the front of the list so it makes the switch.
					}
					pCur->pNext->pPrev = pCur->pPrev; //Connects the pPrev of one item to the pPrev of another.
					pCur->pPrev = pCur->pNext; //Connects the pCur of one item to the pCur of another.
					if (pCur->pNext->pNext != NULL) //As long we're not at the end of the list this will execute.
					{
						pCur->pNext->pNext->pPrev = pCur; //We'll set the very next nodes pointer to pCur.
					}
					pCur->pNext = pCur->pNext->pNext;
					pCur->pPrev->pNext = pCur;
				}
				pCur = pCur->pNext;//Moves through the list.
			}
		}
	}

	else if (userSelection == 3)
	{
		//Begins to sort the function.
		for (passes = 1; passes <= length - 1; ++passes)
		{
			//Will continue to sort the function as long as everything hasn't been sorted.
			pCur = pList->pHead;
			while ((pCur != NULL) && (pCur->pNext != NULL))
			{
				//Compares the first two items.
				if (strcmp(pCur->genre, pCur->pNext->genre) > 0)
				{
					if (pCur->pPrev != NULL) //We are not at the front of the list. AKA something is in front of the node youre looking at.
					{
						pCur->pPrev->pNext = pCur->pNext; //Switches the nodes if we're not at the front of the list.
					}
					else
					{
						pList->pHead = pCur->pNext; //We are at the front of the list so it makes the switch.
					}
					pCur->pNext->pPrev = pCur->pPrev; //Connects the pPrev of one item to the pPrev of another.
					pCur->pPrev = pCur->pNext; //Connects the pCur of one item to the pCur of another.
					if (pCur->pNext->pNext != NULL) //As long we're not at the end of the list this will execute.
					{
						pCur->pNext->pNext->pPrev = pCur; //We'll set the very next nodes pointer to pCur.
					}
					pCur->pNext = pCur->pNext->pNext;
					pCur->pPrev->pNext = pCur;
				}
				pCur = pCur->pNext;//Moves through the list.
			}
		}
	}

	else if (userSelection == 4)
	{
		//Begins to sort the function.
		for (passes = 1; passes <= length - 1; ++passes)
		{
			//Will continue to sort the function as long as everything hasn't been sorted.
			pCur = pList->pHead;
			while ((pCur != NULL) && (pCur->pNext != NULL))
			{
				//Compares the first two items.
				if (pCur->rating > pCur->pNext->rating)
				{
					if (pCur->pPrev != NULL) //We are not at the front of the list. AKA something is in front of the node youre looking at.
					{
						pCur->pPrev->pNext = pCur->pNext; //Switches the nodes if we're not at the front of the list.
					}
					else
					{
						pList->pHead = pCur->pNext; //We are at the front of the list so it makes the switch.
					}
					pCur->pNext->pPrev = pCur->pPrev; //Connects the pPrev of one item to the pPrev of another.
					pCur->pPrev = pCur->pNext; //Connects the pCur of one item to the pCur of another.
					if (pCur->pNext->pNext != NULL) //As long we're not at the end of the list this will execute.
					{
						pCur->pNext->pNext->pPrev = pCur; //We'll set the very next nodes pointer to pCur.
					}
					pCur->pNext = pCur->pNext->pNext;
					pCur->pPrev->pNext = pCur;
				}
				pCur = pCur->pNext;//Moves through the list.
			}
		}
	}
	success = 1;
	return success;
}

/*************************************************************
* Function: printList ()                                    *
* Date Created: 06/16/16                                    *
* Date Last Modified: 06/17/16                              *
* Description: Prints most current music list.              *
* Input parameters: list.                                   *
* Returns: NONE                                             *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
void printList(List musicRecords)
{
	while (musicRecords.pHead != NULL)
	{
		printf("Song: %s", musicRecords.pHead->song);
		printf("Artist: %s", musicRecords.pHead->artist);
		printf("Album: %s", musicRecords.pHead->album);
		printf("Genre: %s", musicRecords.pHead->genre);
		printf("Length: %d: %d\n", musicRecords.pHead->runTime.minutes, musicRecords.pHead->runTime.seconds);
		printf("Times Played: %d\n", musicRecords.pHead->timesPlayed);
		printf("Rating: %d\n", musicRecords.pHead->rating);
		musicRecords.pHead = musicRecords.pHead->pNext;
	}
	printf("End of list.\n");
}

/*************************************************************
* Function: readInfo ()                                     *
* Date Created: 06/16/16                                    *
* Date Last Modified: 06/17/16                              *
* Description: Reads the music file.                        *
* Input parameters:new song, album, artist, genre, length,  *
*                  time played, rating, and list.           *
* Returns: NONE                                             *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
void readInfo(List *pList, FILE *infile, char *newSong, char *newAlbum, char *newArtist, char *newGenre, int newTimesMin, int newTimesSec, int newTimesPlayed, int newRating)
{
	char semicolon = '\0', getNewline = '\0';
	//Reads information about songs from the file.
	while (!feof(infile))
	{
		fgets(newSong, 30, infile);

		fgets(newAlbum, 30, infile);

		fgets(newArtist, 30, infile);

		fgets(newGenre, 30, infile);

		fscanf(infile, "%d", &newTimesMin);

		semicolon = fgetc(infile);

		fscanf(infile, "%d", &newTimesSec);

		getNewline = fgetc(infile);

		fscanf(infile, "%d", &newTimesPlayed);

		getNewline = fgetc(infile);

		fscanf(infile, "%d", &newRating);

		getNewline = fgetc(infile);
		getNewline = fgetc(infile);

		//takes information and then inserts it into make a node function and then places it in the list of nodes.
		insertAtFront(pList, newSong, newAlbum, newArtist, newGenre, newTimesMin, newTimesSec, newTimesPlayed, newRating);
	}
}

/*************************************************************
* Function: searchDelete ()                                 *
* Date Created: 06/17/16                                    *
* Date Last Modified: 06/17/16                              *
* Description: Finds the item you want to delete and then   *
*              deletes it.                                  *
* Input parameters:List and the search item.                *
* Returns: Success.                                         *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
int searchDelete(List *pList, char *searchList)
{
	Node *pCur = NULL;
	int success = 0;
	//sets pCur to the head of this list.
	pCur = pList->pHead;
	//While the item hasn't been found the search continues.
	while ((pCur != NULL) && (strcmp(searchList, pCur->song) != 0))
	{
		pList->pHead->pPrev = pCur;
		pCur = pCur->pNext;
	}
	//When the item has been found the following item executes. (Used Andy's code here).
	if (pCur != NULL)
	{
		success = 1;
		//If deleting from the middle of the list.
		if (pList->pHead->pPrev != NULL)
		{
			pList->pHead->pPrev->pNext = pCur->pNext;
		}
		//If deleting from the front of the list.
		else
		{
			pList->pHead = pCur->pNext;
		}
		//Free's the pointer and node.
		free(pCur->artist);
		pCur = NULL;
	}
	return success;
}

/*************************************************************
* Function: changeRate ()                                   *
* Date Created: 06/18/16                                    *
* Date Last Modified: 06/18/16                              *
* Description: Change the rate of the song you choose.      *
* Input parameters:List and new song rating to change.      *
* Returns: Success.                                         *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
int changeRate(List *pList, char *songRate)
{
	Node *pCur = NULL;
	int success = 0, newUserRate = 0;
	//Sets pCur to the front of the list.
	pCur = pList->pHead;
	//While the song that is being searched for isn't found, the following loop will continue to execute.
	while ((pCur != NULL) && strcmp(songRate, pCur->song) != 0)
	{
		pList->pHead->pPrev = pCur;
		pCur = pCur->pNext;
	}
	//NEED TO ENTER IN THE SONGS NAME EXACTLY AS IT'S STORED.
	if (pCur != NULL) 
	{
		printf("Found on the list.\n");
		success = 1;
		//Asks user for new rate.
		printf("Please enter a new rating: ");
		scanf("%d", &newUserRate);
		//changes the rate of the song.
		pCur->rating = newUserRate;
	}
	return success;
}

/*************************************************************
* Function: editInfo ()                                     *
* Date Created: 06/16/16                                    *
* Date Last Modified: 06/18/16                              *
* Description: Edits the info of a song the user has        *
*              searched by song name, album, genre, or      *
*              artist. Chooses the first field that it finds*
*              one the list. Best to search by song name if *
*              there are similar album names in the list.   *
* Input parameters:edit song, album, artist, genre, length, *
*                  time played, rating, and list.           *
* Returns: NONE                                             *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
void editInfo(List *pList, char userChoice, char *editSong, char *editAlbum, char *editArtist, char *editGenre, int editTimeMin, int editTimeSec, int editTimePlayed)
{
	//Variable declaration.
	Node *pCur = NULL;
	char newUserSong[30], newUserAlbum[30], newUserArtist[30], newUserGenre[30], continuing = '\0', changeMore = '\0';
	int newUserMin = 0, newUserSec = 0, newTimesPlayed = 0, changing = 0;

	if (userChoice == '1')
	{
		//Sets pCur to the head of the list.
		pCur = pList->pHead;
		//While the song your going to edit hasn't been found it will continue to search.
		while ((pCur != NULL) && strcmp(editSong, pCur->song) != 0)
		{
			pList->pHead->pPrev = pCur;
			pCur = pCur->pNext;
		}

		if (pCur == NULL)
		{
			printf("Song was not found.\n");
			printf("Make sure you enter in the song name EXACTLY like it's saved in the list.\n");
		}

		//If song is found in the list.
		if (pCur != NULL)
		{
			printf("Found on the list.\n");
			//Asks user to enter in new field.
			printf("Please enter a new song name: ");
			fgets(newUserSong, 30, stdin);

			strcpy(pCur->song, newUserSong);
		}
		//Asks user if they would like to change time or anything else.
		while ((changing == 0) && (pCur != NULL))
		{
			printf("Would you like to change anything else <y/n>.\n");
			scanf(" %c", &continuing);
			if (continuing == 'y')
			{
				printf("Would you like to change song length or times played?\n");
				printf("Please enter 's' to change song length or 't' to change times played.\n");
				scanf(" %c", &changeMore);
				{
					if (changeMore == 's')
					{
						printf("Please enter song length seperate minutes and seconds with space (i.e 3 15): ");
						scanf("%d %d", &newUserMin, &newUserSec);
						pCur->runTime.minutes = newUserMin;
						pCur->runTime.seconds = newUserSec;
						printf("Are you done making changes? Please enter 1 for yes or 0 for no.\n");
						scanf("%d", &changing);
					}
					else
					{
						printf("Please enter the amount of times played: ");
						scanf("%d", &newTimesPlayed);
						pCur->timesPlayed = newTimesPlayed;
						printf("Are you done making changes? Please enter 1 for yes or 0 for no.\n");
						scanf("%d", &changing);
					}
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (userChoice == '2')
	{
		pCur = pList->pHead;

		while ((pCur != NULL) && strcmp(editAlbum, pCur->album) != 0)
		{
			pList->pHead->pPrev = pCur;
			pCur = pCur->pNext;
		}

		if (pCur == NULL)
		{
			printf("Song was not found.\n");
			printf("Make sure you enter in the song name EXACTLY like it's saved in the list.\n");
		}

		if (pCur != NULL)
		{
			printf("Found on the list.\n");

			printf("Please enter a new album name: ");
			fgets(newUserAlbum, 30, stdin);

			strcpy(pCur->album, newUserAlbum);
		}
		while ((changing == 0) && (pCur != NULL))
		{
			printf("Would you like to change anything else <y/n>.\n");
			scanf(" %c", &continuing);
			if (continuing == 'y')
			{
				printf("Would you like to change song length or times played?\n");
				printf("Please enter 's' to change song length or 't' to change times played.\n");
				scanf(" %c", &changeMore);
				{
					if (changeMore == 's')
					{
						printf("Please enter song length seperate minutes and seconds with space (i.e 3 15): ");
						scanf("%d %d", &newUserMin, &newUserSec);
						pCur->runTime.minutes = newUserMin;
						pCur->runTime.seconds = newUserSec;
						printf("Are you done making changes? Please enter 1 for yes or 0 for no.\n");
						scanf("%d", &changing);
					}
					else
					{
						printf("Please enter the amount of times played: ");
						scanf("%d", &newTimesPlayed);
						pCur->timesPlayed = newTimesPlayed;
						printf("Are you done making changes? Please enter 1 for yes or 0 for no.\n");
						scanf("%d", &changing);
					}
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (userChoice == '3')
	{
		pCur = pList->pHead;
		while ((pCur != NULL) && strcmp(editArtist, pCur->artist) != 0)
		{
			pList->pHead->pPrev = pCur;
			pCur = pCur->pNext;
		}

		if (pCur == NULL)
		{
			printf("Song was not found.\n");
			printf("Make sure you enter in the song name EXACTLY like it's saved in the list.\n");
		}

		if (pCur != NULL)
		{
			printf("Found on the list.\n");

			printf("Please enter a new artist name: ");
			fgets(newUserArtist, 30, stdin);

			strcpy(pCur->album, newUserArtist);
		}
		while ((changing == 0) && (pCur != NULL))
		{
			printf("Would you like to change anything else <y/n>.\n");
			scanf(" %c", &continuing);
			if (continuing == 'y')
			{
				printf("Would you like to change song length or times played?\n");
				printf("Please enter 's' to change song length or 't' to change times played.\n");
				scanf(" %c", &changeMore);
				{
					if (changeMore == 's')
					{
						printf("Please enter song length seperate minutes and seconds with space (i.e 3 15): ");
						scanf("%d %d", &newUserMin, &newUserSec);
						pCur->runTime.minutes = newUserMin;
						pCur->runTime.seconds = newUserSec;
						printf("Are you done making changes? Please enter 1 for yes or 0 for no.\n");
						scanf("%d", &changing);
					}
					else
					{
						printf("Please enter the amount of times played: ");
						scanf("%d", &newTimesPlayed);
						pCur->timesPlayed = newTimesPlayed;
						printf("Are you done making changes? Please enter 1 for yes or 0 for no.\n");
						scanf("%d", &changing);
					}
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (userChoice == '4')
	{
		pCur = pList->pHead;
		while ((pCur != NULL) && strcmp(editGenre, pCur->genre) != 0)
		{
			pList->pHead->pPrev = pCur;
			pCur = pCur->pNext;
		}

		if (pCur == NULL)
		{
			printf("Song was not found.\n");
			printf("Make sure you enter in the song name EXACTLY like it's saved in the list.\n");
		}

		if (pCur != NULL)
		{
			printf("Found on the list.\n");

			printf("Please enter a new genre name: ");
			fgets(newUserGenre, 30, stdin);

			strcpy(pCur->album, newUserGenre);
		}
		while ((changing == 0) && (pCur != NULL))
		{
			printf("Would you like to change anything else <y/n>.\n");
			scanf(" %c", &continuing);
			if (continuing == 'y')
			{
				printf("Would you like to change song length or times played?\n");
				printf("Please enter 's' to change song length or 't' to change times played.\n");
				scanf(" %c", &changeMore);
				{
					if (changeMore == 's')
					{
						printf("Please enter song length seperate minutes and seconds with space (i.e 3 15): ");
						scanf("%d %d", &newUserMin, &newUserSec);
						pCur->runTime.minutes = newUserMin;
						pCur->runTime.seconds = newUserSec;
						printf("Are you done making changes? Please enter 1 for yes or 0 for no.\n");
						scanf("%d", &changing);
					}
					else
					{
						printf("Please enter the amount of times played: ");
						scanf("%d", &newTimesPlayed);
						pCur->timesPlayed = newTimesPlayed;
						printf("Are you done making changes? Please enter 1 for yes or 0 for no.\n");
						scanf("%d", &changing);
					}
				}
			}
			else
			{
				break;
			}
		}
	}
}

/*************************************************************
* Function: storeMusic ()                                   *
* Date Created: 06/15/16                                    *
* Date Last Modified: 06/15/16                              *
* Description: Reads the music into a file.                 *
* Input parameters: Output file, and list.                  *
* Returns: NONE                                             *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
void storeMusic(FILE *outfile, List musicRecords)
{
	//Stores the music to the file.
	while (musicRecords.pHead != NULL)
	{
		fprintf(outfile, "%s", musicRecords.pHead->song);
		fprintf(outfile, "%s", musicRecords.pHead->artist);
		fprintf(outfile, "%s", musicRecords.pHead->album);
		fprintf(outfile, "%s", musicRecords.pHead->genre);
		fprintf(outfile, "%d: %d\n", musicRecords.pHead->runTime.minutes, musicRecords.pHead->runTime.seconds);
		fprintf(outfile, "%d\n", musicRecords.pHead->timesPlayed);
		fprintf(outfile, "%d\n", musicRecords.pHead->rating);
		fprintf(outfile, "\n");
		musicRecords.pHead = musicRecords.pHead->pNext;
	}
}