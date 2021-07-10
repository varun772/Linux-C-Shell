#include"header.h"
void echo(char *sou)
{
    int n,count=0,firstspace=0;
    n = strlen(sou);
    char *v=(char *)malloc(n*sizeof(char));
    //printf("%s\n",sou);
    for(int i=5;i<n;i++)
    {
        if(sou[i]!=' ')
        {
            v[count]=sou[i];
            count++;
            firstspace++;
        }
        else if(sou[i]==sou[i+1] && sou[i]==' ')
        {
            continue;
        }
        else
        {
            if(firstspace>0)
            {
                v[count]=' ';
                count++;
            }
        }
    }
    //v = (char*)realloc(v,count-1);
    for(int i=0;i<count;)
    {
        printf("%c",v[i]);
        i++;
    }
    printf("\n");
    //free(v);
    //printf("%s\n",v);
}
    