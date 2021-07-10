#include"header.h"
void pinfo(char *sou)
{
    char *temp[10000];
    temp[0]=NULL;
    temp[1]=NULL;
    int count =0;
    char *token;
    token = strtok(sou," ");
     while(token!=NULL)
    {
        temp[count]=token;
        count++;
        token = strtok(NULL," ");
    }
    char ps1[] = "pinfo";
    if(strncmp(temp[0],ps1,strlen(temp[0]))==0)
    {
        if(count==1)
        {
            int pid;
            char path[100];
            char status[100];
            char process_status[100];
            //char var1[100];
            pid = getpid();
            //char pathto ="~/a.out";
            sprintf(path,"/proc/%d/status",pid);
            printf("pid -- %d\n",pid);
            FILE *filepointer = fopen(path,"r");
            int temp = 0;
            if(filepointer==NULL)
            {
                printf("file cannot be opened\n");
                return;
            }
            while(temp != 2)
			{
				fgets(status,100,filepointer);
				temp++;
			}
			fscanf(filepointer,"%s %s",status,process_status);
            while(fgets(path,sizeof(path),filepointer)!=NULL)
            {
                if(strncmp("VmPeak",path,5)==0)
                {
                    fgets(path,sizeof(path),filepointer);
                    break;
                }
            }
            char *token;
            token=strtok(path,"\n");
            char *token1;
            token = strtok(path,":");
            while(token!=NULL)
            {
                token1=token;
                token = strtok(NULL,":");
            }
            printf("Process Status -- = %s\n",process_status);
            printf("memory -- %s {Virtual Memory}\n",token1);
            char expath[2000];
            //printf("%lu\n",strlen(cwdpath));
            sprintf(path,"/proc/%d/exe",pid);
            readlink(path,expath,sizeof(expath));
            printf("Executable Path -- %s\n",expath);
        }
        else if(count==2)
        {
            char path[100];
            char pathto[1024];
            char status[100];
            char process_status[100];
            printf("pid -- %s\n",temp[1]);
            sprintf(path,"/proc/%s/status",temp[1]);
            FILE *filepointer = fopen(path,"r");
            int temp1 = 0;
            if(filepointer==NULL)
            {
                printf("file cannot be opened\n");
                return;
            }
            while(temp1 != 2)
			{
				fgets(status,100,filepointer);
				temp1++;
			}
            fscanf(filepointer,"%s %s",status,process_status);
            while(fgets(path,sizeof(path),filepointer)!=NULL)
            {
                if(strncmp("VmRSS",path,5)==0)
                    break;
            }
            char *token;
            token=strtok(path,"\n");
            char *token1;
            token = strtok(path,":");
            while(token!=NULL)
            {
                token1=token;
                token = strtok(NULL,":");
            }
            //printf("memory -- %s {Virtual Memory}\n",token);
            //token = strtok(NULL,"\n");
            //printf("memory -- %s {Virtual Memory}\n",token);
            printf("Process Status -- = %s\n",process_status);
            printf("memory -- %s {Virtual Memory}\n",token1);
            char expath[2000];
            //printf("%s\n",cwdpath);
            //printf("%lu\n",strlen(cwdpath));
            sprintf(path,"/proc/%s/exe",temp[1]);
            readlink(path,expath,sizeof(expath));
            //printf("%s\n",expath);
            printf("Executable Path -- %s\n",expath);
        }
        else
        {
            perror("ERROR");
        }   
    }
    else
    {
        perror("ERROR");   
    } 
}