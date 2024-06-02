#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

typedef struct ListNode
{
    char en_words[20];
    char zh_words[80];
    struct ListNode *next;
}ListNode;

typedef struct LinkedList
{
    ListNode *head;
}LinkedList;

ListNode *createwords( char *en, char *zh );
LinkedList *createlist();

void addnewword( LinkedList *obj, char *en, char *zh );
void deleteword( LinkedList *obj, char *en, char *zh );
void editword( LinkedList *obj, char *en, char *zh );
void findword( LinkedList *obj, char *en, char *zh );
void printlist_all( LinkedList *obj );
void printlist_en( LinkedList *obj );
void printlist_zh( LinkedList *obj );

void write_to_file(LinkedList* obj);
void read_to_file(LinkedList* obj);
bool passwordpass( char *password );
void readpassword( char *password );
void savepassword( char *password );
char *changepassword();

void MainMenu();
void ShowMenu();
void EditMenu();
void FindMenu();

void MainMenuSelect( LinkedList *obj );
void ShowMenuSelect( LinkedList *obj );
void EditMenuSelect( LinkedList *obj );
void FindMenuSelect( LinkedList *obj );