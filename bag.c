#include"header.h"
void bag(char *sou)
{
    char *token;
    token = strtok(sou," ");
    char *varun[10000];
    int vcount=0;
    while(token!=NULL)
    {
        varun[vcount]=token;
        vcount++;
        token = strtok(NULL," ");
    }
    varun[vcount]=NULL;
    int flag23=0;
    //printf("%d\n",vcount);
    //printf("%s\n",varun[vcount-1]);
    if(strncmp(varun[vcount-1],"&",1)==0)
    {
        flag23=1;
        varun[vcount-1]=NULL;
    }
    //printf("%d\n",flag23);
    //printf("%s\n",varun[vcount-1]);
    if(flag23==1)
    {
        int k=fork();
        if(k==0)
        {
            setpgid(0,0);
            int anna;
            anna = execvp(varun[0],varun);
            if(anna<0)
            {
                perror("ERROR");
            }
            //if()
            exit(0);
        }
        printf("started %s with pid %d\n",varun[0],k);
        a[bagcount]=k;
        b[bagcount]=(char*)malloc(10000*sizeof(char));
        strcpy(b[bagcount],varun[0]);
        bagcount++;
    }
    else
    {
        int k = fork();
        //printf("%d\n",k);
        if(k!=0)
        {
	cpid=k;
	cpids=1;
            wait(NULL);
	cpids=0;        
}
        else
        {
            int anna;
            anna = execvp(varun[0],varun);
            if(anna<0)
            {
                perror("ERROR");
            }
            //printf("%s\n",varun[0]);
            exit(0);
        }
    }
    
}
