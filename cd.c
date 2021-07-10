#include"header.h"
void cd(char *sou)
{
    int count = 0;
    char *temp[1000];
    int len = strlen(sou);
    char *token;
    char *temp1[1000];
    char cd1[]="cd ";
    //printf("%d\n",len);
    //printf("%s\n",sou);
    if(len>2)
    {
        // cd kakunda inka edanna input isthe ee loop lo ki
        //printf("%d\n",len);
        if(strncmp(sou,cd1,3)==0)
        {
            //sou[len-1]='\0';
            count =0;
            token = strtok(sou," ");
            while(token!=NULL)
            {
                temp1[count]=token;
                //printf("%s\n",temp1[count]);
                count++;
                //printf("%s\n",token);
                token= strtok(NULL," ");
            }
            temp1[count]=NULL;
            //printf("%d\n",count);
            //printf("%s\n",temp1[0]);
            //printf("%s\n",temp1[1]);
            //printf("\n");
            //printf("%s\n",temp1[2]);
            char *pastdirectory="-";
            int n;
            if(count>1)
                n=strncmp(temp1[1],pastdirectory,1);
            //cd - ani chustunnam
            //printf("%d\n",n);
            //printf("%d\n",len);
            if((temp1[1]!= NULL) && (n!=0))
            {
                temp[0]=temp1[1];
                //printf("%d\n",len);
            }
            else
            {
                //printf("%d\n",len);
                if(((n==0) && (strlen(temp1[1])==1)) || (count==1)) //strlen enduku ante - okkate undali ani -- unte kakodadu kada
                {
                    if(n==0 && strlen(temp1[1])==1)
                    count = 3334;
                        //printf("came\n");
                    temp[0] = NULL;
                        //printf("came2\n");
                    //ikkada daka vastundi
                }
            }
            //printf("1\n");
        }
        else
        {
            printf("ERROR\n");
        }
        //printf("1\n"); 
    }
    else 
    {
        temp[0] = NULL;
    }
    //printf("1\n");//print avtundi
    //ikkadi daka kuda ratle
    //printf("1\n");
    if(temp[0] == NULL )
    {
        //printf("loop1\n");
        if(count == 3334)
        {
            bonus(1);
        }
        else
        {
            //printf("nothing\n");
            chdir(getenv("PWD"));
        }
    }
    else
    {
        //printf("loop2\n");
        if(count==2)
        {
            pwd(temp[0]);
        }
        else
        {
            perror("ERROR");
        }
    }
}   