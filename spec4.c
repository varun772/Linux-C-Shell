#include "header.h"
void spec4(char* sou)
{
    char *token;
    char *temp[1000];
    int count=0;
    token = strtok(sou," ");
     while(token!=NULL)
    {
        temp[count]=token;
        count++;
        token = strtok(NULL," ");
    }
    if(strcmp(temp[0],"setenv")==0)
    {
        printf("%d\n",count);
        if(count==3)
            setenv(temp[1],temp[2],1);
        else
            perror("ERROR");
    }
    else if(strcmp(temp[0],"unsetenv")==0)
    {
        if(count==2)
            unsetenv(temp[1]);
        else
            perror("ERROR");
    }
    else if(strcmp(temp[0],"jobs")==0)
    {
        for(int i=0;i<bagcount;i++)
        {
            if(stop[i]!=234)
            {
                char run[]="Running";
                printf("[%d] %s %s [%d]\n",i+1,run,b[i],a[i]);
            }
            else
            {
                char run[]="stopped";
                printf("[%d] %s %s [%d]\n",i+1,run,b[i],a[i]);
            }
        }
    }
    else if(strcmp(temp[0],"kjob")==0)
    {
        int n1,n2;
        n1 = atoi(temp[1]);
        n2 = atoi(temp[2]);
        if(n1>bagcount)
            perror("ERROR");
        else
            kill(a[n1-1],n2);
    }
    else if(strcmp(temp[0],"overkill")==0)
    {
        printf("1234\n");
        if(count==1)
        {
            for(int i=0;i<bagcount;i++)
            {
                    kill(a[i],SIGKILL);
            }
        }
        else
            perror("ERROR");
    }
    else if(strcmp(temp[0], "fg")==0)
    {
        int l = strlen(temp[1]), x = 0, power = 1;
        for(int i=0; i<l; i++)
        {
            x+= (temp[1][l-1-i]- '0')*power;
            power *= 10;
        }
        if(count == 2)
        {
            signal(SIGCHLD, SIG_IGN);
            int tmp = kill(a[x], SIGCONT);
            if(tmp != 0)
            {
                perror("ERROR");
            }
            waitpid(-1,NULL, WUNTRACED);
        }
        else
            perror("ERROR");
    }
    else if(strcmp(temp[0], "bg")==0)
    {
        int l = strlen(temp[1]), x = 0, power = 1;
        for(int i=0; i<l; i++)
        {
            x+= (temp[1][l-1-i]- '0')*power;
            power *= 10;
        }
        if(count == 2)
        {
            signal(SIGCHLD, SIG_IGN);
            int tmp = kill(a[x], SIGTTIN);
            if(tmp != 0)
            {
                perror("ERROR");
            }
            tmp = kill(a[x], SIGCONT);
            if(tmp != 0)
            {
                perror("ERROR");
            }
        }
        else
            perror("ERROR");
    }
    else if(strcmp(temp[0],"fg")==0)
    {
        if(count==2)
        {
            int n1=atoi(temp[1]);
            int k = kill(n1,SIGCONT);
            if(k<0)
            {
                perror("ERROR");
            }
        }
        else
            perror("ERROR");
    }
}