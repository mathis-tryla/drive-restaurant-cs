/******************************************************************/
/*                           INCLUDE                              */
/******************************************************************/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/sendfile.h>
#include <pthread.h>


/******************************************************************/
/*                           CONSTANTES                           */
/******************************************************************/
#define MAX_BUFF	512
#define MAX_CLIENT 3

/******************************************************************/
/*                           TYPEDEF                              */
/******************************************************************/
typedef char message_t[MAX_BUFF];
typedef char action_t[MAX_BUFF];
typedef void * (*pf_t)(void *);

/******************************************************************/
/*                        MACRO-FONCTIONS                         */
/******************************************************************/
#define CHECK(sts, msg) if ((sts)==-1) {perror(msg); exit(-1);}
#define CHECK_T(sts, msg) if ((sts)!=0) {perror(msg); exit(-1);}

/******************************************************************/
/*                           FONCTIONS                            */
/******************************************************************/
void serveur(void);
int sessionSrv(char *, int);
void client(void);

int sessionClt(void);


