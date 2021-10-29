//Read_htm.h

long str_len=0;
char * Read_htm()
{
    
    char c;
    char *inputString;
    char filename[20];
    long len=100;
     inputString=malloc(990000);
    printf("please enter the filename to be created (with extension) 30 characters max.\n");
    fgets(filename,20,stdin);
    scanf("%s",filename);
    char *file_Des="";
    file_Des=malloc(30);
    /* File pointer to hold reference to our file */
    strcat(file_Des,"temp/");
    strcat(file_Des,filename);
    FILE * fPtr;


    /* 
     * Open file in w (write) mode. 
     * "data/file1.txt" is complete path to create file
     */
    

    fPtr = fopen(file_Des, "wb+");

    

//     /* Input contents from user to store in file */
//     //char inputString[1000], c;
         long int index = 0;

        printf("Enter your code below ( type ~ and press enter to end input)\n");
        while((c = getchar()) != '~')
        { 
            inputString[index++] = c;
        }
        inputString[index] = '\0';
        
        printf("Your code  \n %s", inputString);
        printf("\n");

     /* Write data to file */
    fprintf(fPtr,"%s",inputString);

//     /* Success message */
     printf("File created and saved successfully. :) \n");
    

    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    fclose(fPtr);
    str_len=strlen(inputString);
    return inputString;
}

long fetch_len()
{
return str_len;
}
