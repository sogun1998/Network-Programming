#include"user.h"
#include"businessLayer.h"
int main()
{
    
    int c=1;
    
    char username[30];
    account *user=NULL;
    account *nowUser=NULL;
    readFile("account.txt",&user);
    //printf("%s",user->username);
    
    while (c==1||c==2||c==3||c==4)
    {
        c = menu();
        switch (c)
        {
            case 1: accountRegister(&user);
                    showAccountNode(user);
                    writeFile("account.txt",&user);
            break;
            case 2: 
                
                nowUser = makeAccountNode();
                accountLogin(&user,&nowUser);
                 writeFile("account.txt",&user);
            break;
            case 3:
                printf("_Username:");
                scanf("%[^\n]%*c",username);
                if(nowUser==NULL||!(isExit(user,username))){
                    printf("Can't find account");
                }else{
                    if(search(user,username))
                    {
                        printf("Account is active");
                    }
                    else(printf("Active is block"));
                }
            break;
            case 4: 
                printf("_Username:");
                scanf("%[^\n]%*c",username);
                if(nowUser==NULL||strcmp(nowUser->username,username)!=0){
                    printf("Account is not sign in");
                }
                else if(!(isExit(user,username))){
                    printf("Cannot find account");
                }
                else {
                    printf("Good bye %s",nowUser->username);
                    nowUser = NULL;
                }
            break;
        }
        
    }
    return 0;
}