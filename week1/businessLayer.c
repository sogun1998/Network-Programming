#include"businessLayer.h"
int menu()
{
    printf("\n1. Register\n2. Sign in\n3. Search \n4. Sign out\n");
    char s[10];
    scanf("%[^\n]%*c", s);
    int c = (int)atoi(s);
    return c;
}
int readFile(char *file,account **_account){
    FILE *f;
    f = fopen(file, "r");
    if (f==NULL) {perror("LOI"); return 1;}
    while (1)
    {
        char line[100];
        if (fscanf(f,"%[^\n]%*c", line) == EOF) break;

        account * temp = makeAccountNode();
        sscanf(line, "%s %s %d", temp->username, temp->pasword, &temp->isActive);
        //printf("%s %s %d",temp->username, temp->pasword, temp->isActive );
        addAccountnode(_account, &temp);
    }
    fclose(f);
    //showNoop(*user);
    return 1;
}
int writeFile(char *file,account **_account)
{
    FILE *f;
    f = fopen(file, "w");
    putAccount(f, *_account);
    fclose(f);
}
void putAccount(FILE *f,account *list)
{
    if (list!=NULL)
    {
        
        fprintf(f,"%s %s %d\n", list->username, list->pasword, list->isActive);
        putAccount(f,list->next);
    }
}
void accountRegister(account **user)
{
    char name[20],password[20];
    account *tmp = makeAccountNode();
    do{
        printf("_Username:");
        scanf("%[^\n]%*c",name);
        if(isExit((*user),name)){
            printf("\nAccount exited");
        }
    } while(isExit((*user),name));
    
    do {
        printf("_Password:");
        scanf("%[^\n]%*c",password);
    } while(strlen(password)<6);
    strcpy(tmp->username,name);
    strcpy(tmp->pasword,password);
    tmp->isActive = 1;
    addAccountnode(user,&tmp);
    printf("Succcessful registration");
}
void accountLogin(account **list,account **nowUser)
{
    int error=0;
    char username[30];
    char password[30];
    int check;
    printf("_Username:");
    scanf("%[^\n]%*c",username);
    do
    {
        if (error == 3) 
        {   
            blockUser(list,username);
            return;
        }
        
       

        do {
            printf("\n_Password:");
            scanf("%[^\n]%*c",password);
        } while(strlen(password)<6);
        check = isUser(*list, username, password,nowUser);
        //printf("check u %d",check);
        if (check == 1)
        {
             printf("\nHello %s",(*nowUser)->username);
             return ;
        }
        //if (isUser(tree, username, password, nowUser)) return -2;
        else if(check==2)
        {
            printf("\nPassword is incorrect");
            error++;
        }
        else
        {
            printf("\n Cannot find account");
            return ;
        }
        
    } while (1);
    
}