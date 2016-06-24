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
#include <stdio.h>  /* Needed for fscanf ( ), fprintf ( ), fopen ( ), etc. */
#include <stdlib.h> /* Needed for exit ( ) */
#include <string.h>

//Structs
typedef struct songlength
{
	int minutes;
	int seconds;
} Songlength;
typedef struct node
{
	char artist[30];
	char song[30];
	char album[30];
	char genre[30];
	int timesPlayed;
	int rating;
	Songlength runTime;
	struct node *pNext;
	struct node *pPrev;
} Node;
typedef struct list
{
	Node *pHead;
} List;

//fuction prototypes
void readInfo(List *pList, FILE *infile, char *newSong, char *newAlbum, char *newArtist, char *newGenre, int newTimesMin, int newTimesSec, int newTimesPlayed, int newRating);
Node *makeNode(char *newSong, char *newAlbum, char *newArtist, char *newGenre, int newTimesMin, int newTimesSec, int newTimesPlayed, int newRating);
void initList(List *pList);
void printList(List musicRecords);
int searchDelete(List *pList, char *searchItem);
void insertAtFront(List *pList, char *newSong, char *newAlbum, char *newArtist, char *newGenre, int *newTimesMin, int *newTimesSec, int *newTimesPlayed, int *newRating);
int sortList(List *pList, int userSelection);
int changeRate(List *pList, char *songRate);
void editInfo(List *pList, char userChoice, char *editSong, char *editAlbum, char *editArtist, char *editGenre, int editTimeMin, int editTimeSec, int editTimePlayed);
void storeMusic(FILE *outfile, List musicRecords);

//One Dance
//Views
//Drake
//Hip - Hop
//3:57
//12
//2
//
//Flocka
//Pretty Jodye
//ASAP Rocky
//Rap
//4:01
//37
//4
//
//Fifth Symphony
//Unknown
//Beethoven
//Classical
//7:09
//2
//1