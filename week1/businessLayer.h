#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"user.h"
int readFile(char *file,account **_account);
int writeFile(char *file,account **_account);
void accountRegister(account **user);
int menu();
int checkAccount();
void accountLogin(account **list,account **nowUser);
void searchUser(account *list,char user[]);
void putAccount(FILE *f,account *list);
