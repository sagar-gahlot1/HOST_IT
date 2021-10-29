//socket.h


int pid,n;
int child_pid[20];
int num_pid=0;
   
int parent_process=1;
int open_socket(long length, char *buffer)
{




struct sockaddr_in server_addr,client_addr;
    socklen_t sin_len = sizeof(client_addr);
    int fd_server,fd_client;
    char buf[2048];
    int on=1;
    
 

    fd_server = socket(AF_INET,SOCK_STREAM,0);
    if (fd_server<0){
        perror("socket");
        exit(1);
    }

 

    setsockopt(fd_server, SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr=INADDR_ANY;
    server_addr.sin_port=htons(8280);
    if (bind(fd_server,(struct sockaddr *) &server_addr, sizeof(server_addr)) == -1){
        perror("bind");
        close(fd_server);
        exit(1);
    }

 

    if (listen(fd_server,10)== -1){
        perror("listen");
        close(fd_server);
        exit(1);
    }
    
    while(1) {
        fd_client = accept(fd_server, (struct sockaddr *) (struct socketaddr *) &client_addr, &sin_len);
        if (fd_client == -1) {

 

            perror("connection failed....\n");
            continue;

 

        }
        printf("Got client connection......\n");
        parent_process=getppid();

 

        if ( !(child_pid[num_pid++]=fork())) {

            close(fd_server);
            memset(buf, 0, 2048);
            read(fd_client, buf, 2047);
            printf("%s\n", buf);
            
 
            write(fd_client, buffer, length- 1);
            close(fd_client);
            printf("closing...\n");
            printf("Parent process= %d",getppid());            
      	    invalid:
              printf("\n--> Wants to exit Press 0: ");
                      scanf("%d",&n);
                 if(n==0){
            printf("exiting..");
            printf("\n");
             for(int k=0;k<num_pid;k++){
                 waitpid(child_pid[k],&n,0);
                 //kill(getppid(),SIGTERM);
             kill(child_pid[k],SIGTERM);
             }
    		exit(1);
            }else{printf("Invalid choice.... Web Server is still running."); goto invalid;}
	     
                
             break;
	     
	    
        }

    }
    return 0;
   
}
