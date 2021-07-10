#include"header.h"
void bonus(int verifycount)
{
    char presentdirec[1024];
    direclist[direccount]=malloc(10000);
    getcwd(presentdirec, sizeof(presentdirec));
    //direclist[direccount]=(char *)malloc(1000*sizeof(char));
    //int value=chdir(presentdirec[direccount]);
    //printf("%d",direccount);
    if(verifycount!=1)
    {
        if(direccount==0)
        {
            strcpy(direclist[direccount],presentdirec);
            direccount++;
        }
        else
        {
            if(strlen(direclist[direccount-1])==strlen(presentdirec))
            {
                if(strncmp(direclist[direccount-1],presentdirec,strlen(presentdirec))!=0)
                {
                    strcpy(direclist[direccount],presentdirec);
                    direccount++; 
                }
            }   
            else
            {
                strcpy(direclist[direccount],presentdirec);
                direccount++;   
            }
        }
    }
    //printf("%d\n",verifycount);
    //printf("%d\n",direccount);
    /*if(direccount>=2)
    {
        printf("in loop\n");
        printf("%s\n",direclist[direccount-2]);
    }*/
    if(verifycount==1)
    {
        //printf("%s\n",direclist[(direccount)-1]);
        //printf("1\n");
        //printf("%d\n",direccount);
        //char *copy=(char *)malloc(1000*sizeof(char));
        if(direccount>=2)
        {
            chdir(direclist[direccount-2]);
            printf("%s\n",direclist[direccount-2]);
        }
        else
        {
            perror("ERROR");
        }
        //printf("%s\n",direclist[direccount-2]);
        //strcpy(copy,direclist[direccount-1]);
        //printf("%s\n",copy);
        //return ;
    }
}