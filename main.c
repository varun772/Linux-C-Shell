#include"header.h"
//char *var[i];
void ctrlc(int sig_num)
{
	int thala=0;
    if (cpids == 1)
    {
    	thala++;
        if (kill(cpid, SIGINT) < 0 && thala)
        {
        	thala=1;
            perror("Error in kill");
         	thala++;
          //  printf("%s",fore.name);
        	thala--;
        }
        thala=1;
        cpid = 0;
    }
    else
    {
    	thala=0;
        fprintf(stderr,"\ntwanshell: No foreground process\n");
        fflush(stdout);
    //    tildconvertedpwd();
    }
    signal(SIGINT, ctrlc);
   thala++; 
    fflush(stdout);
    thala--;
    return;
}
void csk()
{
    int dhoni,score,i;
    while(4)
    { 
        dhoni = waitpid((pid_t)-1, &score, WNOHANG);
        if((dhoni ==0 || dhoni == -1) && dhoni<=0)
        {
            return;
        }
        else
         { 
            for(i=0;i<bagcount;i++)
            {
                if(a[i] == dhoni)
                    break;
            }
            printf("\n");
            fprintf(stderr,"%s exited normallu with pid %d\n",b[i],a[i]);
            stop[i]=234;
            //printf("%d\n",i);
         }
    } 
}
int ioredirec(char *c)
{
    for(int i=0;i<strlen(c);i++)
    {
        if(c[i]=='>' || c[i]=='<')
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    direccount=0;
    maincount=0;
    char *direclist[1000];
    while(1)
    {
        /*int whicount=0;
        whicount++;
        char *buffer= (char*)malloc(PATH_MAX);
        char *buffer1= (char*)malloc(PATH_MAX);
        getcwd(buffer, PATH_MAX);
        //if(strncmp())*/
        maincount++;
        signal(SIGCHLD,csk);
        signal(SIGTSTP,ctrlc);
        char *c = (char*)malloc(10000*sizeof(char));
        char *sou = (char*)malloc(100000*sizeof(char));
        char *token;
        char *var[100000];
        prompt();
        bonus(2);
        unsigned long int insize=100000,len;
        int tmp = getline(&c,&insize,stdin);
        if(tmp <= 0) return 0;
        //printf("%s",c);
        len = strlen(c);
        int count=0,len1=0;
        for(int i=0;i<len-1;i++)
        {
            if(c[i]!=' ')
                count++;

            if(count>0)
            {
                sou[len1] = c[i];
                len1++;
            }
        }
        int colummcount=0;
        token = strtok(sou,";");
        while(token!=NULL)
        {
                var[colummcount]=token;
                //printf("%s\n",var[colummcount]);
                colummcount++;
                token = strtok(NULL,";");
        }
        //printf("%d\n",colummcount);
        for(int i=0;i<colummcount;i++)
        {
            /*printf(" this is test =%s\nvarun",var[i]);
            printf("%lu\n",strlen(var[i]));*/
            char tempvar[1024][1024];
            //tempvar[0][1]='k';
            //printf("%c\n",tempvar[0][1]);
            //printf("1\n");
            int tempcount=0,tempcount1=0;
            //printf("2\n");
            for(int j=0;j<strlen(var[i]);j++)
            {
                if(var[i][j]!=' ')
                {
                    tempcount1++;
                }
                if(tempcount1>0)
                {
                    tempvar[i][tempcount]=var[i][j];
                    tempcount++;
                }
            }
            tempvar[i][tempcount] = '\0';
            /*printf(" this is test =%s\nvarun",tempvar[i]);
            printf("4\n");*/
            char ex[] = "exit ";char pw[] = "pwd ";char ec[] = "echo "; char cd1[] = "cd";char ls1[]="ls";char ps1[] = "pinfo";char his[]="history";
            char ste[]="setenv";char unste[] = "unsetenv";char jo[] = "jobs";char kjo[]="kjob";char ovjo[]="overkill";char totkill[]="quit";char fg[]="fg";
            
            if(strncmp(tempvar[i],ex,4)==0)
            {
                if((strlen(tempvar[i])==4))
                {
                    free(c);
                    tempvar[0][0] ='\0';
                    return 0;
                }
                else
                {
                        perror("ERROR");
                }   
            }
            else if(ioredirec(sou)==1)
            {
                //iodirec(tempvar[i]);
            }
            else if(strncmp(tempvar[i],pw,3)==0)
            {
                if(strlen(tempvar[i]) > 3)
                {
                    if(strncmp(tempvar[i],pw,4)==0)
                    {
                        pwd(NULL);
                        printf("\n");
                    }
                    else
                    {
                        perror("ERROR");   
                    }
                }
                else
                {
                    pwd(NULL);
                    printf("\n");
                }
            }
            else if(strncmp(tempvar[i],cd1,2)==0)
            {
                cd(tempvar[i]);
            }
            else if(strncmp(tempvar[i],ec,4)==0)
            {
                if(strncmp(tempvar[i],ec,5)==0 && strlen(tempvar[i])>5)
                {
                    if(strlen(tempvar[i])>5)
                        echo(tempvar[i]);
                    else
                        perror("ERROR");
                }
                else if(strlen(tempvar[i])==5)
                    printf("\n");
                else if(strlen(tempvar[i])==4)
                    printf("\n");
                else
                    perror("ERROR");
            }
            else if(strncmp(tempvar[i],ls1,2)==0)
            {
                //printf("%s",tempvar[i]);
                if(strlen(tempvar[i])>2)
                {
                    if(strncmp(tempvar[i],ls1,3))
                        ls(tempvar[i]);
                }
                else
                {
                    ls(tempvar[i]);  
                    //printf("1\n"); 
                }
            }
            else if (strncmp(tempvar[i],ps1,5)==0)
            {
                //printf("%s\n",tempvar[i]);
                pinfo(tempvar[i]);
            }
            else if(strncmp(tempvar[i],ste,6)==0)
            {
                //printf("1\n");
                spec4(tempvar[i]);
            }
            else if(strncmp(tempvar[i],unste,8)==0)
            {
                 spec4(tempvar[i]);
            }
            else if(strncmp(tempvar[i],jo,4)==0)
            {
                spec4(tempvar[i]);
            }
            else if(strncmp(tempvar[i],kjo,4)==0)
            {
                spec4(tempvar[i]);
            }
            else if(strncmp(tempvar[i],ovjo,8)==0)
            {
                printf("123\n");
                spec4(tempvar[i]);
            }
            else if(strncmp(tempvar[i],totkill,4)==0)
            {
                return 0;
            }
            else if(strncmp(tempvar[i],fg,2)==0)
            {
                spec4(tempvar[i]);
            }       
            else 
            {
                bag(tempvar[i]);
            }
        }
    }
    return 0;
}
