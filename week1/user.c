#include"user.h"
account *makeAccountNode()
{
    account *temp = (account*)malloc(sizeof(account));
    temp->next=NULL;
    return temp;
}
void addAccountnode(account **list,account **node)
{
    
    if(*list==NULL)
    {
        
        *list = *node;
        
    }
    else {
        addAccountnode(&(*list)->next,node);
    }
}
void showAccountNode(account *list)
{
    
    if(list!=NULL)
    {
        printf("\n%s - %s - %d\n", list->username,list->pasword,list->isActive);
        showAccountNode(list->next);
    }
}
int isExit(account *list, char *name)
{
    account *tmp;
    tmp = list;
    while(tmp!=NULL){
        if(strcmp(tmp->username,name)==0){
            
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
int isUser(account *list, char *username, char *password, account **nowUser)
{
    account *tmp;
    tmp = list;
    while(tmp!=NULL){
        if((strcmp(tmp->username,username)==0)){
            if(strcmp(tmp->pasword,password)==0){
                strcpy((*nowUser)->username,username);
                strcpy((*nowUser)->pasword,password);
                return 1;
                
            }else return 2;
        }
        tmp = tmp->next;
    }
    return 0;
}
void blockUser(account **list,char *username)
{
    account *tmp;
    tmp = *list;
    while(tmp!=NULL){
        if(strcmp(tmp->username,username)==0){
            tmp->isActive=0;
            
        }
        tmp = tmp->next;
    }
    
}
int search(account *list, char *username)
{
    account *tmp;
    tmp = list;
    while(tmp!=NULL){
        if(strcmp(tmp->username,username)==0){
            return tmp->isActive;
            
        }
        tmp = tmp->next;
    }
    return -1;
}