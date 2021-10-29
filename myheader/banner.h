//banner.h

void yellow()
{
    printf("\033[1;33m");
}

 

void reset()
{
    printf("\033[0m");
}
void green()
{
    printf("\033[1;32m");
}

 

void mainOption()
{
    yellow();
    printf("\t#######################################\n");
    printf("\t##                                   ##\n");
    printf("\t##");
    green();
    printf("         Host it Web server        ");
    yellow();
    
    printf("##\n");
    printf("\t##                                   ##\n");
    printf("\t##");
    reset();
    printf(" 1. Wants to write a html code     ");
    yellow();
    printf("##\n");
    printf("\t##");
    reset();
    printf(" 2. host it from existing file     ");
    yellow();
    printf("##\n");
    printf("\t##");
    reset();
    printf(" 3. Quit                           ");
    yellow();
    printf("##\n");
    printf("\t##                                   ##\n");
    printf("\t#######################################\n");
    reset();
}

 

void subOption2()
{
  DIR *d;
    struct dirent *dir;
    d = opendir("store/.");
    

    yellow();
    printf("\t######################################################\n");
    printf("\t##                                                  ##\n");
    printf("\t##");
    green();
    printf("\t      Host it from existing file            ");
    yellow();
    
    printf("##\n");
    printf("\t##                                                  ##\n");
    printf("\t##");
    reset();
    printf("\t      Including below files for hosting     ");
    yellow();
    printf("##\n");
    
   
     if (d)
    {
            int c=0;
        while ((dir = readdir(d)) != NULL)
        {     
                  char *dir_str;
                    dir_str=malloc(10);
                    strcpy(dir_str,dir->d_name);
                if(strcmp(dir_str,".")!=0 && strcmp(dir_str,".." )!=0 && strcmp(dir_str,"dump" )!=0){
                    
            printf("\t##\t\t%20s\t\t    ##\n", dir_str);
                }
                free(dir_str);
                
        }
        closedir(d);
    }

    
    
    
    printf("\t##                                                  ##\n");
    printf("\t######################################################\n");
    reset();
}