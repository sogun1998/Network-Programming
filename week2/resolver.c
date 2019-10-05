#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char const *argv[]) {
  char parameter[100];

  if (argc != 2) {
    printf("Syntax is incorrect!\n");
    return 0;
  }

  strcpy(parameter, argv[1]);

  if (isalpha(parameter[0])) {       
        struct hostent *hostTent;
        
        printf("Hostname: %s\n", parameter);
        hostTent = gethostbyname(parameter);

         if (hostTent == NULL) {
        printf("Not found information\n");
        return 0;
        }
        printf("Offcial IP: %s \n", inet_ntoa(*((struct in_addr *)hostTent->h_addr)));
         char **pAlias;
        int i;
        for (pAlias = hostTent->h_aliases; *pAlias != NULL; pAlias++) {
        printf("Alias IP #%d: %s\n", ++i, inet_ntoa(*((struct in_addr *)pAlias)));
        }     
  } else {
        struct hostent *hostTent;
        struct in_addr addr;
        int i = 0;

        printf("IP address: %s\n", parameter);
        addr.s_addr = inet_addr(parameter);
        if (addr.s_addr == INADDR_NONE) {
            printf("Not found information\n");
            return 0;
        } else hostTent = gethostbyaddr((char *) &addr, 4, AF_INET);

        if (hostTent == NULL) {
        printf("Not found information\n");
        return 0;}

        printf("Offcial name: %s \n", hostTent->h_name);

         char **pAlias;

        for (pAlias = hostTent->h_aliases; *pAlias != NULL; pAlias++) {
        printf("Alternate name #%d: %s\n", ++i, inet_ntoa(*((struct in_addr *)pAlias)));
        }     
  }

 
  return 0;
}