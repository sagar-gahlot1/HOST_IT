//main.c

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <alloca.h>
#include <dirent.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

 

#include"myheader/banner.h"
#include"myheader/fetch_file.h"
#include"myheader/socket.h"
#include"myheader/Read_htm.h"

void yellow();
void reset();
void mainOption();
void subOption2();

char* fetch_file();
long fetch_length(char *);

int open_socket(long,char *);
char* Read_htm();
long fetch_len();

 char naming[]="HTTP/1.1 200 OK\r\n"
          "Content-Type: text/html; charset=UTF-8\r\n\r\n"
          "<!DOCTYPE html>\r\n";
int main()
{
    int choice;
    char fileName[100],ans;



    do
    {      char* readit;
        char* tempo12;
        tempo12=malloc(990000);
       
        mainOption();
        printf("What you want to do? : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
     
            strcat(tempo12,Read_htm());
            readit=malloc(strlen(naming)+fetch_len());
            strcpy(readit,naming);
            strcat(readit,tempo12);
             printf("\nPlease check the Port  http://localhost:8280/ \n");
            open_socket(  fetch_len()+strlen(naming) , readit);
                break;
        
            case 2:
                subOption2();
                
                while ((getchar()) !='\n');
                
                
                printf("Are you sure you want to continue (Y/N): ");
                ans=getchar();
                if(ans=='Y'||ans=='y')
                {
            
			char *temp=fetch_file();
			printf("\n Please check the Port  http://localhost:8280/ \n");
			open_socket(fetch_length(temp),temp);
			free(temp);
                  
                }else{ continue;}

    case 3: 
   exit(0);
        
        }
    
    }while(choice!=3);
   exit(0); 
    return 0;
}
