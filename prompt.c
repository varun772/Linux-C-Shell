#include"header.h"
#include"pwd.h"
void prompt()
{
        char host[10000];
        gethostname(host,sizeof(host));
        printf("<%s@%s:",getenv("USER"),host);
        char *buffer= (char*)malloc(PATH_MAX);
        getcwd(buffer, PATH_MAX);
        int homecount=0;
        char *varun = getenv("PWD");
        //printf("%s\n",buffer);
        //printf("1\n");
        //printf("%s\n",varun);
        for(int i=0;i<strlen(varun);i++)
        {
                if(buffer[i]==varun[i])
                {
                        continue;
                }
                else
                {
                        homecount++;
                }
        }
        //printf("%d\n",homecount);
        if(homecount==0)
        {
                printf("~");
                for(int i=strlen(varun);i<strlen(buffer);i++)
                {
                        printf("%c",buffer[i]);
                }
        }
        else
        {
                for(int i=0;i<strlen(buffer);i++)
                {
                        printf("%c",buffer[i]);
                }   
        }
        printf(">");
        //printf("%s",buffer);
        //printf("%s",varun);
}
