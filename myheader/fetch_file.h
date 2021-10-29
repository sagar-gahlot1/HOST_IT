//fetch_file.h


char* fetch_file()
{



char naming[]="HTTP/1.1 200 OK\r\n"
          "Content-Type: text/html; charset=UTF-8\r\n\r\n"
          "<!DOCTYPE html>\r\n";

// CSS READ

char * buff_css=0;
long length_css=0;
FILE * fi = fopen ("store/style.css", "rb");

if (fi)
{
  fseek (fi, 0, SEEK_END);
  length_css = ftell (fi);
  fseek (fi, 0, SEEK_SET);
  buff_css = malloc (length_css);
  if (buff_css)
  {
    fread (buff_css, 1, length_css, fi);
  }
  fclose (fi);
}

char *buff_scp=0;
buff_scp = malloc (100000);

char *com_buff;
com_buff=malloc(90000000);

// CSS ADDED

strcat(com_buff,naming);
strcat(com_buff,"<style>");
strcat(com_buff,buff_css);
strcat(com_buff,"</style>");
free(buff_css);

// SCRIPT READ
long length_scp;
FILE * fs = fopen ("store/script.js", "rb");

if (fs)
{
  fseek (fs, 0, SEEK_END);
  length_scp = ftell (fs);
  fseek (fs, 0, SEEK_SET);
 
  if (buff_scp)
  {
    fread (buff_scp, 1, length_scp+7, fs);
  }
  strcat(buff_scp,"</script>\n");
  fclose (fs);
}



// HTML ADDED 

char * buffer=0;
long length;
FILE * f = fopen ("store/index.htm", "rb");

if (f)
{
  fseek (f, 0, SEEK_END);
  length = ftell (f);
  fseek (f, 0, SEEK_SET);
  buffer = malloc (length);
  if (buffer)
  {
    fread (buffer, 1, length, f);
  }
  fclose (f);
}



char *temp=NULL;
temp=malloc(length+50);
strcat(temp,buffer);


int flag_for_new=0;
while(*temp!='\0')
{
if( (temp[0]=='<') && (temp[1]=='b' || temp[1]=='B') && (temp[2]=='o' || temp[2]=='O') && (temp[3]=='d' || temp[3]=='D') && (temp[4]=='y' ||  temp[4]=='Y')){
flag_for_new=1;
break;
}
temp++;
}



int count=6;
char *temp2=NULL;



temp2=malloc(length+50);


if(flag_for_new==1){strcat(temp2,temp);temp2=temp2+6;}else{strcpy(temp2,"");strcat(temp2,"<body>");strcat(temp2,buffer);strcat(temp2,"</body>");}


while(*temp!='\0')
{
  if((temp[0]=='<') && (temp[1]=='s' || temp[1]=='S')  && (temp[2]=='c' || temp[2]=='C') && (temp[3]=='r' || temp[3]=='R')  && (temp[4]=='i' || temp[4]=='I') ){ 
break;
}
count++;
temp++;
}


if(flag_for_new==1){


count=count-6;
int flag=0;
char *mainbuf1=NULL;
mainbuf1=malloc(count);

while(flag!=count){
mainbuf1[flag]=temp2[flag];
flag++;
}
mainbuf1[flag]='\0';


strcat(mainbuf1,"</body>");
strcat(com_buff,mainbuf1);
  

}

else{

strcat(com_buff,temp2);
free(temp2);
}

/// script ADDED



strcat(com_buff,"<script>");
strcat(com_buff,buff_scp);


free(buff_scp);
long length_all=strlen(com_buff);
return com_buff;

}


long fetch_length(char *buffer1)
{
return strlen(buffer1);
}