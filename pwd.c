#include"pwd.h"
#include"header.h"
void pwd(char *q)
{
   char *buffer= (char*)malloc(PATH_MAX);
   //char *home = (char*)malloc(PATH_MAX);
   //printf("%s",q);
   if(q==NULL)
   {
      getcwd(buffer, PATH_MAX);
      for(int i=0;i<strlen(buffer);i++)
      {
         printf("%c",buffer[i]);
      }
   }
   else
   {
      //printf("1\n");
      char *past1 = "~";
       if(strncmp(q,past1,1)==0 && strlen(q)==1)
       {
          //printf("%s",q);
         chdir(getenv("PWD"));
       }
       else
       {
         int t=chdir(q);
          if(t==-1)
          {
             perror("ERROR");
          }
       }
   }
}
