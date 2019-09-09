#ifndef USER_H
#define USER_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct account
{
    char username[30];
    char pasword[30];
    int isActive;
    struct account *next; 
} account;

account *makeAccountNode();
void addAccountnode(account **list,account **node);
void showAccountNode(account *list);
int isExit(account *list, char *name);
void insertAccountNode();
int isUser(account *list, char *username, char *password,account **nowUser);
void blockUser(account **list,char *username);
int search(account *list, char *username);
#endif

